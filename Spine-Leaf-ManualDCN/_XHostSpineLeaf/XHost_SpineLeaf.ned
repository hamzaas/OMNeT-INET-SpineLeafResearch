package _XHostSpineLeaf;
import inet.linklayer.configurator.L2NetworkConfigurator;
import inet.visualizer.integrated.IntegratedCanvasVisualizer;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//
import inet.node.ethernet.Eth100M;
import inet.node.ethernet.EtherSwitch;
import inet.node.inet.Router;
import inet.node.inet.StandardHost;


//
// TODO documentation
//
network XHost_SpineLeaf_Network
{
    parameters:
		int numSpines = 4;
		int numLeafs = 9;
		int hostPerLeaf = 32;

        //** If hostPerLeaf moved to moduleLeaf then each leaf could have different # of hosts.
        @display("i=device/lan-bus;bgb=755,333");
    types:
        module Leaf
        {
            parameters:

                @display("i=device/server2;bgb=757,229");
            gates:
                inout leafDoor[];
            submodules:
                topOfRack: LeafRouter {
                    @display("p=147,53");
                }
		rackSwitch: EtherSwitch {
                    @display("p=147,116");
                }
                H[hostPerLeaf]: StandardHost {
                    @display("p=147,140,r,50");
                }
                LeafVisualizer: IntegratedCanvasVisualizer {
                    @display("p=39,40");
                    interfaceTableVisualizer.textColor = "white";
                    interfaceTableVisualizer.displayBackground = true;
                    interfaceTableVisualizer.backgroundColor = "black";
                }
            connections:
                // Establishes connection between topOfRack and outside the module
                for i=0..numSpines-1 {
                    topOfRack.ethg++ <--> leafDoor++;
                }
                // Connects rackSwitch to topOfRack router
                topOfRack.ethg++ <--> Eth100M <--> rackSwitch.ethg++;
                // Connects all hosts in leaf to rackSwitch
                for k=0..hostPerLeaf-1 {
                    H[k].ethg++ <--> Eth100M <--> rackSwitch.ethg++;
                }
        }
    submodules:
        spine[numSpines]: Router {
            @display("p=203,51,r,100");
        }
        border: StandardHost {
            @display("p=155,241");
        }
        leaf[numLeafs]: Leaf {
            @display("p=237,163,r,100;i=device/server2");
        }
        LanVisualizer: IntegratedCanvasVisualizer {
            @display("p=39,49");
            interfaceTableVisualizer.textColor = "white";
            interfaceTableVisualizer.displayBackground = true;
            interfaceTableVisualizer.backgroundColor = "black";
        }
        borderLeaf: LeafRouter {
            @display("p=155,162");
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=38.15625,138.75");
        }
    connections:
        // Connects all spines to the borderRouter
        for i=0..numSpines-1 {
            spine[i].ethg++ <--> Eth100M <--> borderLeaf.ethg++;
        }
        // Connects all spines to all leafs
        for i=0..numSpines-1, for k=0..numLeafs-1 {
            spine[i].ethg++ <--> Eth100M <--> leaf[k].leafDoor++;
        }
        // Connects borderRouter to lanDoor
        borderLeaf.ethg++ <--> Eth100M <--> border.ethg++;
}

