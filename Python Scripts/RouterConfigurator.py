def writeSelfRoutesToFile(file, leaf, leafs, host, spine, hostsPerLeaf):
    file.write(
        '\t<route hosts="leaf[' + str(leaf) + '].topOfRack" destination="' + 'leaf[' + str(leafs) + '].' + 'H[' + str(
            host) + ']"' + ' netmask="255.255.255.255" gateway="*" interface="eth' + str(spines + host) +
        '"' + ' metric="*"/>\n')


def writeOtherRoutesToFile(file, leaf, leafs, host, spine):
    file.write('\t<route hosts="leaf[' + str(leaf) + '].topOfRack" destination="' + 'leaf[' + str(leafs) +
               '].' + 'H[' + str(host) + ']"' + ' netmask="255.255.255.255" gateway="*" interface=' '"eth' +
               str(spine) + '"' + ' metric="*"/>\n')


def writeINBorderRoutesToFile(file, leaf, leafs, host, spine):
    file.write('\t<route hosts="leaf[' + str(leaf) + '].topOfRack" destination="' + 'border"' +
               ' netmask="255.255.255.255" gateway="*" interface=' '"eth' +
               str(spine) + '"' + ' metric="*"/>\n')


def writeOUTBorderRoutesToFile(file, leaf, leafs, host, spine):
    file.write('\t<route hosts="borderLeaf" destination="' + 'leaf[' + str(leafs) +
               '].' + 'H[' + str(host) + ']"' + ' netmask="255.255.255.255" gateway="*" interface=' '"eth' +
               str(spine) + '"' + ' metric="*"/>\n')


def writeBorderSelfRoute(file, numSpines):
    file.write('\t<!-- Border Self Routes -->\n')
    file.write('\t<route hosts="borderLeaf" destination="' + 'border"' +
               ' netmask="255.255.255.255" gateway="*" interface=' '"eth' + str(numSpines) + '"' + ' metric="*"/>\n')

def writeVLANS(file, max):
    for lan in range(max):
        file.write('\t<interface hosts="leaf[' + str(lan) + '].**" address="10.0.' + str(lan + 1) + '.x" netmask="255.255.255.x"/>\n')

    file.write('\n\t<interface hosts="**" address="10.0.' + str(max + 1) + '.x" netmask="255.255.255.x"/>\n\n')

def writeRoutes(fileName, numLeaves, numSpines, hostsPerLeaf):
    file = open(fileName, 'w')
    file.write('<config>\n\n');
    #Ip address and Vlans
    #for leaf in range(numLeaves + 1):
    #    file.write('\t<interface hosts="**" address="10.x.x.x" netmask="255.x.x.x"/>\n\n')

    writeVLANS(file, numLeaves)


    # Loop for all leaves
    for leaf in range(numLeaves + 1):
        commentPrint = False
        # Loop for leaves in each major subsection
        for leafs in range(numLeaves + 1):
            for host in range(hostsPerLeaf[leafs]):
                for spine in range(spines):
                    if leaf == leafs and leaf != numLeaves:
                        if not commentPrint:
                            file.write('\t<!-- Self Routes -->\n')
                            commentPrint = True
                        writeSelfRoutesToFile(file, leaf, leafs, host, spine, hostsPerLeaf)
                        break
                    elif leaf == numLeaves and leafs < numLeaves:
                        writeOUTBorderRoutesToFile(file, leaf, leafs, host, spine)
                    elif leafs == numLeaves and leaf < numLeaves:
                        writeINBorderRoutesToFile(file, leaf, leafs, host, spine)
                    elif leafs < numLeaves and leaf < numLeaves:
                        writeOtherRoutesToFile(file, leaf, leafs, host, spine)
                file.write('\n')
        file.write('\n\n')

    writeBorderSelfRoute(file, numSpines)
    file.write('</config>')


# -----------------------------------------------------------------------------------------------------------------------

# Input - Spines, Leaves, and hosts per each leaf
print("Enter Number of Spines: ")
spines = int(input())

print("Enter Number of Leaves: ")
leaves = int(input())

hostsPerLeafArray = []

# default is one
lastInput = 1

for i in range(leaves):
    print("Number of Hosts for leaf", (i + 1))
    inp = input()
    if inp == 'f':
        for j in range(leaves - i):
            hostsPerLeafArray.append(lastInput)
        break
    else:
        hostsPerLeafArray.append(int(inp))
        lastInput = int(inp)

# -------------------------------------------------------------------------------------------
# Writing input to file for bash implementation.

file = open('input.txt', 'w')
file.write(str(spines) + "\n")  # writing num spines to input file
file.write(str(leaves) + "\n")  # writing num leaves to input file
for i in hostsPerLeafArray:     # writing hosts per leaf to file
    file.write(str(i) + "\n")

# -------------------------------------------------------------------------------------------
# Creating Routes
# BorderLeafAppend
hostsPerLeafArray.append(1)

writeRoutes('ManualRoutingXML.xml', leaves, spines, hostsPerLeafArray)
