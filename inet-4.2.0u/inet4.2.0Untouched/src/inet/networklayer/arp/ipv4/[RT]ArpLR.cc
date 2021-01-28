/*
 * Copyright (C) 2004 Andras Varga
 * Copyright (C) 2008 Alfonso Ariza Quintana (global arp)
 * Copyright (C) 2014 OpenSim Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include "inet/common/IProtocolRegistrationListener.h"
#include "inet/common/ProtocolTag_m.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/common/lifecycle/NodeStatus.h"
#include "inet/common/packet/Packet.h"
#include "inet/common/packet/dissector/ProtocolDissector.h"
#include "inet/common/packet/dissector/ProtocolDissectorRegistry.h"
#include "inet/linklayer/common/InterfaceTag_m.h"
#include "inet/linklayer/common/MacAddressTag_m.h"
#include "inet/networklayer/arp/ipv4/[RT]ArpLR.h"
#include "inet/networklayer/arp/ipv4/ArpPacket_m.h"
#include "inet/networklayer/contract/IInterfaceTable.h"
#include "inet/networklayer/ipv4/IIpv4RoutingTable.h"
#include "inet/networklayer/ipv4/Ipv4Header_m.h"
#include "inet/networklayer/ipv4/Ipv4InterfaceData.h"

namespace inet {

simsignal_t ArpLR::arpRequestSentSignal = registerSignal("arpRequestSent");
simsignal_t ArpLR::arpReplySentSignal = registerSignal("arpReplySent");

static std::ostream& operator<<(std::ostream& out, std::vector<inet::ArpLR::ArpCacheEntryLR *, std::allocator<inet::ArpLR::ArpCacheEntryLR *>>& e)
{
    out << "hello";
    return out;
}


Define_Module(ArpLR);

ArpLR::ArpLR()
{
}

void ArpLR::initialize(int stage)
{
    OperationalBase::initialize(stage);

    if (stage == INITSTAGE_LOCAL) {
        retryTimeout = par("retryTimeout");
        retryCount = par("retryCount");
        cacheTimeout = par("cacheTimeout");
        proxyArpInterfaces = par("proxyArpInterfaces").stdstringValue();

        proxyArpInterfacesMatcher.setPattern(proxyArpInterfaces.c_str(), false, true, false);

        // init statistics
        numRequestsSent = numRepliesSent = 0;
        numResolutions = numFailedResolutions = 0;
        WATCH(numRequestsSent);
        WATCH(numRepliesSent);
        WATCH(numResolutions);
        WATCH(numFailedResolutions);

        //WATCH_PTRMAP](arpCache);
    }
    else if (stage == INITSTAGE_NETWORK_LAYER) {
        ift = getModuleFromPar<IInterfaceTable>(par("interfaceTableModule"), this);
        rt = getModuleFromPar<IIpv4RoutingTable>(par("routingTableModule"), this);
        registerService(Protocol::arp, gate("netwIn"), gate("ifIn"));
        registerProtocol(Protocol::arp, gate("ifOut"), gate("netwOut"));
    }
}

void ArpLR::finish()
{
}

ArpLR::~ArpLR()
{
    std::map<Ipv4Address, std::vector<ArpCacheEntryLR *>>::iterator it = arpCache.begin();
    while (it != arpCache.end()){
        arpCache.erase(it);
        it++;
    }
}

void ArpLR::handleMessageWhenUp(cMessage *msg)
{
    if (msg->isSelfMessage()) {
        requestTimedOut(msg);
    }
    else {
        Packet *packet = check_and_cast<Packet *>(msg);
        processArpPacket(packet);
    }
}

void ArpLR::handleStartOperation(LifecycleOperation *operation)
{
    ASSERT(arpCache.empty());
}

void ArpLR::handleStopOperation(LifecycleOperation *operation)
{
    flush();
}

void ArpLR::handleCrashOperation(LifecycleOperation *operation)
{
    flush();
}

void ArpLR::flush()
{
    //TODO: Fix Flush Method

//    while (!arpCache.empty()) {
//        std::vector<ArpCacheEntryLR *> i = arpCache[0];                      //the first element of the cache
//
//        for (int k = 0; k < i.size(); k++) {
//
//
//        while(!i->second.empty()){                      //While the vector is not empty
//            ArpCacheEntryLR *entry = i->second.begin();   //entry is each element in vector
//            cancelAndDelete(entry->timer);
//            entry->timer = nullptr;
//            delete entry;
//        }
//        arpCache.erase(i);
//    }
}

void ArpLR::refreshDisplay() const
{
    OperationalBase::refreshDisplay();

    std::stringstream os;

    os << "size:" << arpCache.size() << " sent:" << numRequestsSent << "\n"
       << "repl:" << numRepliesSent << " fail:" << numFailedResolutions;

    getDisplayString().setTagArg("t", 0, os.str().c_str());
}

void ArpLR::initiateArpResolution(ArpCacheEntryLR *entry)
{
    Ipv4Address nextHopAddr = entry->addr;
    entry->pending = true;
    entry->numRetries = 0;
    entry->lastUpdate = SIMTIME_ZERO;
    entry->macAddress = MacAddress::UNSPECIFIED_ADDRESS;
    sendArpRequest(entry->ie, nextHopAddr);

    // start timer
    cMessage *msg = entry->timer = new cMessage("ARP timeout");
    msg->setContextPointer(entry);
    scheduleAt(simTime() + retryTimeout, msg);

    numResolutions++;
    Notification signal(nextHopAddr, MacAddress::UNSPECIFIED_ADDRESS, entry->ie);
    emit(arpResolutionInitiatedSignal, &signal);
}

void ArpLR::sendArpRequest(const InterfaceEntry *ie, Ipv4Address ipAddress)
{
    // find our own IPv4 address and MAC address on the given interface
    MacAddress myMACAddress = ie->getMacAddress();
    Ipv4Address myIPAddress = ie->getProtocolData<Ipv4InterfaceData>()->getIPAddress();

    //XXX:
    // both must be set
    ASSERT(!myMACAddress.isUnspecified());
    ASSERT(!myIPAddress.isUnspecified());

    // fill out everything in ARP Request packet except dest MAC address
    Packet *packet = new Packet("arpREQ");
    const auto& arp = makeShared<ArpPacket>();
    arp->setOpcode(ARP_REQUEST);
    arp->setSrcMacAddress(myMACAddress);
    arp->setSrcIpAddress(myIPAddress);
    arp->setDestIpAddress(ipAddress);
    packet->insertAtFront(arp);

    packet->addTag<MacAddressReq>()->setDestAddress(MacAddress::BROADCAST_ADDRESS);
    packet->addTag<InterfaceReq>()->setInterfaceId(ie->getInterfaceId());
    packet->addTag<PacketProtocolTag>()->setProtocol(&Protocol::arp);
    // send out
    EV_INFO << "Sending " << packet << " to network protocol.\n";
    emit(arpRequestSentSignal, packet);
    send(packet, "ifOut");
    numRequestsSent++;
}

void ArpLR::requestTimedOut(cMessage *selfmsg)
{
    ArpCacheEntryLR *entry = (ArpCacheEntryLR *)selfmsg->getContextPointer();
    entry->numRetries++;
    if (entry->numRetries < retryCount) {
        // retry
        Ipv4Address nextHopAddr = entry->addr;
        EV_INFO << "ARP request for " << nextHopAddr << " timed out, resending\n";
        sendArpRequest(entry->ie, nextHopAddr);
        scheduleAt(simTime() + retryTimeout, selfmsg);
        return;
    }

    delete selfmsg;

    // max retry count reached: ARP failure.
    // throw out entry from cache
    EV << "ARP timeout, max retry count " << retryCount << " for " << entry->addr << " reached.\n";
    Notification signal(entry->addr, MacAddress::UNSPECIFIED_ADDRESS, entry->ie);
    emit(arpResolutionFailedSignal, &signal);
    //XXX://arpCache.erase(entry->myIter);
    delete entry;
    numFailedResolutions++;
}

bool ArpLR::addressRecognized(Ipv4Address destAddr, InterfaceEntry *ie)
{
    if (rt->isLocalAddress(destAddr))
        return true;
    else {
        // if proxy ARP is enables in interface ie
        if (proxyArpInterfacesMatcher.matches(ie->getInterfaceName())) {
            // if we can route this packet, and the output port is
            // different from this one, then say yes
            InterfaceEntry *rtie = rt->getInterfaceForDestAddr(destAddr);
            return rtie != nullptr && rtie != ie;
        }
        else
            return false;
    }
}

void ArpLR::dumpArpPacket(const ArpPacket *arp)
{
    EV_DETAIL << (arp->getOpcode() == ARP_REQUEST ? "ARP_REQ" : arp->getOpcode() == ARP_REPLY ? "ARP_REPLY" : "unknown type")
              << "  src=" << arp->getSrcIpAddress() << " / " << arp->getSrcMacAddress()
              << "  dest=" << arp->getDestIpAddress() << " / " << arp->getDestMacAddress() << "\n";
}

void ArpLR::processArpPacket(Packet *packet)
{
    EV_INFO << "Received " << packet << " from network protocol.\n";
    const auto& arp = packet->peekAtFront<ArpPacket>();
    dumpArpPacket(arp.get());

    // extract input port
    InterfaceEntry *ie = ift->getInterfaceById(packet->getTag<InterfaceInd>()->getInterfaceId());

    //
    // Recipe a'la RFC 826:
    //
    // ?Do I have the hardware type in ar$hrd?
    // Yes: (almost definitely)
    //   [optionally check the hardware length ar$hln]
    //   ?Do I speak the protocol in ar$pro?
    //   Yes:
    //     [optionally check the protocol length ar$pln]
    //     Merge_flag := false
    //     If the pair <protocol type, sender protocol address> is
    //         already in my translation table, update the sender
    //         hardware address field of the entry with the new
    //         information in the packet and set Merge_flag to true.
    //     ?Am I the target protocol address?
    //     Yes:
    //       If Merge_flag is false, add the triplet <protocol type,
    //           sender protocol address, sender hardware address> to
    //           the translation table.
    //       ?Is the opcode ares_op$REQUEST?  (NOW look at the opcode!!)
    //       Yes:
    //         Swap hardware and protocol fields, putting the local
    //             hardware and protocol addresses in the sender fields.
    //         Set the ar$op field to ares_op$REPLY
    //         Send the packet to the (new) target hardware address on
    //             the same hardware on which the request was received.
    //

    MacAddress srcMacAddress = arp->getSrcMacAddress();
    Ipv4Address srcIpAddress = arp->getSrcIpAddress();

    if (srcMacAddress.isUnspecified())
        throw cRuntimeError("wrong ARP packet: source MAC address is empty");
    if (srcIpAddress.isUnspecified())
        throw cRuntimeError("wrong ARP packet: source IPv4 address is empty");


    // "If ... sender protocol address is already in my translation table"

//---------------------------------------------------------------------------------------------------------------------
//XXX: Needs Testing

    if (addressRecognized(arp->getDestIpAddress(), ie)) {                               //If the ipv4address is valid

        bool duplicate = false;
        //Lets first check to see if this entry is already in the cache.
        if (arpCache.count(srcIpAddress) != 0) {                            //If this IpAddress has a vector in the table
            std::vector<ArpCacheEntryLR *> it = arpCache.at(srcIpAddress);  //"it" is pointing to a vector of entries
            //Iterate through the vector and see if the entry is already in the vector
            for (int k = 0; k != it.size(); k++){
                if(ie == it[k]->ie){
                    updateArpCache(it[k], srcMacAddress);   //Update pending
                    duplicate = true;
                    break;
                }
            }
        }
        if (!duplicate) {                               //If there is no duplicate
            ArpCacheEntryLR *entry;                     //Create a new entry
            entry = new ArpCacheEntryLR();
            entry->ie = ie;
            entry->macAddress = srcMacAddress;
            entry->pending = false;
            entry->timer = nullptr;
            entry->numRetries = 0;
            entry->addr = srcIpAddress;
            if(arpCache.count(srcIpAddress) == 0){      //If there is not a vector for the IpAddress, create one
                std::vector<ArpCacheEntryLR *> temp;
                temp.push_back(entry);
                arpCache.insert(std::pair<Ipv4Address, std::vector<ArpCacheEntryLR *>>(srcIpAddress, temp));
            }
            else{
                arpCache.at(srcIpAddress).push_back(entry);
            }
            EV << "\n\nArpCacheEntry not known. Creating a new entry and updating the ARP Cache Entry\n\n";
            updateArpCache(entry, srcMacAddress);       //UpdateArpCache so that Ipv4Routing knows its safe to send
        }
//--------------------------------------------------------------------------------------------------------------------
        // "?Is the opcode ares_op$REQUEST?  (NOW look at the opcode!!)"
        switch (arp->getOpcode()) {
            case ARP_REQUEST: {
                EV_DETAIL << "Packet was ARP REQUEST, sending REPLY\n";
                MacAddress myMACAddress = resolveMacAddressForArpReply(ie, arp.get());
                if (myMACAddress.isUnspecified()) {
                    delete packet;
                    return;
                }

                Ipv4Address myIPAddress = ie->getProtocolData<Ipv4InterfaceData>()->getIPAddress();

                // "Swap hardware and protocol fields", etc.
                const auto& arpReply = makeShared<ArpPacket>();
                Ipv4Address origDestAddress = arp->getDestIpAddress();
                arpReply->setDestIpAddress(srcIpAddress);
                arpReply->setDestMacAddress(srcMacAddress);
                arpReply->setSrcIpAddress(origDestAddress);
                arpReply->setSrcMacAddress(myMACAddress);
                arpReply->setOpcode(ARP_REPLY);
                Packet *outPk = new Packet("arpREPLY");
                outPk->insertAtFront(arpReply);
                outPk->addTag<MacAddressReq>()->setDestAddress(srcMacAddress);
                outPk->addTag<InterfaceReq>()->setInterfaceId(ie->getInterfaceId());
                outPk->addTag<PacketProtocolTag>()->setProtocol(&Protocol::arp);

                // send out
                EV_INFO << "Sending " << outPk << " to network protocol.\n";
                emit(arpReplySentSignal, outPk);
                send(outPk, "ifOut");
                numRepliesSent++;
                break;
            }

            case ARP_REPLY: {
                EV_DETAIL << "Discarding packet\n";
                break;
            }

            case ARP_RARP_REQUEST:
                throw cRuntimeError("RARP request received: RARP is not supported");

            case ARP_RARP_REPLY:
                throw cRuntimeError("RARP reply received: RARP is not supported");

            default:
                throw cRuntimeError("Unsupported opcode %d in received ARP packet", arp->getOpcode());
        }
    }
    else {
        // address not recognized
        EV_INFO << "IPv4 address " << arp->getDestIpAddress() << " not recognized, dropping ARP packet\n";
    }
    delete packet;
}

MacAddress ArpLR::resolveMacAddressForArpReply(const InterfaceEntry *ie, const ArpPacket *arp)
{
    return ie->getMacAddress();
}

void ArpLR::updateArpCache(ArpCacheEntryLR *entry, const MacAddress& macAddress)
{
    EV_DETAIL << "Updating ARP cache entry: " << entry->addr << " <--> " << macAddress << "\n";

    // update entry
    if (entry->pending) {
        entry->pending = false;
        delete cancelEvent(entry->timer);
        entry->timer = nullptr;
        entry->numRetries = 0;
    }
    entry->macAddress = macAddress;
    entry->lastUpdate = simTime();
    Notification signal(entry->addr, macAddress, entry->ie);
    emit(arpResolutionCompletedSignal, &signal);
}

MacAddress ArpLR::resolveL3Address(const L3Address& address, const InterfaceEntry *lie)
{
    Enter_Method("resolveMACAddress(%s,%s)", address.str().c_str(), lie->getInterfaceName());

    //XXX:

    Ipv4Address addr = address.toIpv4();

    bool duplicate = false;
    //Lets first check to see if this entry is already in the cache.
    if (arpCache.count(addr) != 0) {                            //If this IpAddress has a vector in the table
        std::vector<ArpCacheEntryLR *> it = arpCache.at(addr);  //"it" is pointing to a vector of entries
        //Iterate through the vector and see if the entry is already in the vector
        for (int k = 0; k != it.size(); k++){
            if(lie == it[k]->ie){
                duplicate = true;
                break;
            }
        }
    }
    if (!duplicate) {                               //If there is no duplicate, so we must create a new entry
        ArpCacheEntryLR *entry;
        entry = new ArpCacheEntryLR();
        entry->addr = addr;
        entry->ie = lie;
        if(arpCache.count(addr) == 0){              //If there is no vector, create one
            std::vector<ArpCacheEntryLR *> temp;
            temp.push_back(entry);
            arpCache.insert(std::pair<Ipv4Address, std::vector<ArpCacheEntryLR *>>(addr, temp));
        }
        else{
            arpCache.at(addr).push_back(entry);
        }
        EV << "Starting ARP resolution for " << addr << "\n";
        initiateArpResolution(entry);               //Send Arp Request
        return MacAddress::UNSPECIFIED_ADDRESS;
    }
	else {
	    std::vector<ArpCacheEntryLR *> it = arpCache.at(addr);
		for (int i = 0; i < it.size(); i++) {
			if (it[i]->ie == lie) {
				if (it[i]->pending) {
					EV << "ARP resolution for " << addr << " is already pending\n";
					return MacAddress::UNSPECIFIED_ADDRESS;
				}
				else {
					return it[i]->macAddress;
				}
			}
		}
	}
    return MacAddress::UNSPECIFIED_ADDRESS;
}

L3Address ArpLR::getL3AddressFor(const MacAddress& macAddr) const
{
    Enter_Method_Silent();

    if (macAddr.isUnspecified())
        return Ipv4Address::UNSPECIFIED_ADDRESS;

    simtime_t now = simTime();
    for (const auto & pair : arpCache){
        for (int k = 0; k != pair.second.size(); k++){
            if(pair.second[k]->macAddress == macAddr)
                return pair.first;

        }
    }
    return Ipv4Address::UNSPECIFIED_ADDRESS;
}

// Also known as ARP Announcement
void ArpLR::sendArpGratuitous(const InterfaceEntry *ie, MacAddress srcAddr, Ipv4Address ipAddr, ArpOpcode opCode)
{
    Enter_Method_Silent();

    // both must be set
    ASSERT(!srcAddr.isUnspecified());
    ASSERT(!ipAddr.isUnspecified());

    // fill out everything in ARP Request packet except dest MAC address
    Packet *packet = new Packet("arpGrt");
    const auto& arp = makeShared<ArpPacket>();
    arp->setOpcode(opCode);
    arp->setSrcMacAddress(srcAddr);
    arp->setSrcIpAddress(ipAddr);
    arp->setDestIpAddress(ipAddr);
    arp->setDestMacAddress(MacAddress::BROADCAST_ADDRESS);
    packet->insertAtFront(arp);

    auto macAddrReq = packet->addTag<MacAddressReq>();
    macAddrReq->setSrcAddress(srcAddr);
    macAddrReq->setDestAddress(MacAddress::BROADCAST_ADDRESS);
    packet->addTag<InterfaceReq>()->setInterfaceId(ie->getInterfaceId());
    packet->addTag<PacketProtocolTag>()->setProtocol(&Protocol::arp);

    ArpCacheEntryLR *entry;
    entry = new ArpCacheEntryLR();

    entry->ie = ie;
    //entry->macAddress = srcAddr; //Should we have this here?
    entry->pending = false;
    entry->timer = nullptr;
    entry->numRetries = 0;
    entry->addr = ipAddr;
    //If there is no vector for ipAddr
    if(arpCache.count(ipAddr) == 0){
        std::vector<ArpCacheEntryLR *> temp;
        temp.push_back(entry);
        arpCache.insert(std::pair<Ipv4Address, std::vector<ArpCacheEntryLR *>>(ipAddr, temp));
    }
    else{
        arpCache.at(ipAddr).push_back(entry);
    }

    // send out
    send(packet, "ifOut");
}

// A client should send out 'ARP Probe' to probe the newly received IPv4 address.
// Refer to RFC 5227, IPv4 Address Conflict Detection
void ArpLR::sendArpProbe(const InterfaceEntry *ie, MacAddress srcAddr, Ipv4Address probedAddr)
{
    Enter_Method_Silent();

    // both must be set
    ASSERT(!srcAddr.isUnspecified());
    ASSERT(!probedAddr.isUnspecified());

    Packet *packet = new Packet("arpProbe");
    const auto& arp = makeShared<ArpPacket>();
    arp->setOpcode(ARP_REQUEST);
    arp->setSrcMacAddress(srcAddr);
    arp->setSrcIpAddress(Ipv4Address::UNSPECIFIED_ADDRESS);
    arp->setDestIpAddress(probedAddr);
    arp->setDestMacAddress(MacAddress::UNSPECIFIED_ADDRESS);
    packet->insertAtFront(arp);

    auto macAddrReq = packet->addTag<MacAddressReq>();
    macAddrReq->setSrcAddress(srcAddr);
    macAddrReq->setDestAddress(MacAddress::BROADCAST_ADDRESS);
    packet->addTag<InterfaceReq>()->setInterfaceId(ie->getInterfaceId());
    packet->addTag<PacketProtocolTag>()->setProtocol(&Protocol::arp);

    // send out
    send(packet, "ifOut");
}

} // namespace inet

