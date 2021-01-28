package _10HostSpineLeaf;
import _XHostSpineLeaf.LeafRouter;
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
import inet.node.inet.Router;
import inet.node.inet.StandardHost;


//
// TODO documentation
//
network spineLeafNetwork
{
    @display("bgb=1147,616");
    submodules:
        leaf1: LeafRouter {
            @display("p=223,284");
        }
        leaf4: LeafRouter {
            @display("p=739,292");
        }
        leaf2: LeafRouter {
            @display("p=411,284");
        }
        leaf3: LeafRouter {
            @display("p=580,292");
        }
        spine1: Router {
            @display("p=223,191");
        }
        spine2: Router {
            @display("p=411,191");
        }
        spine3: Router {
            @display("p=580,191");
        }
        H2: StandardHost {
            @display("p=223,366");
        }
        H9: StandardHost {
            @display("p=656,366");
        }
        H3: StandardHost {
            @display("p=282,366");
        }
        H7: StandardHost {
            @display("p=541,366");
        }
        H10: StandardHost {
            @display("p=739,366");
        }
        H8: StandardHost {
            @display("p=598,366");
        }
        H6: StandardHost {
            @display("p=469,366");
        }
        H5: StandardHost {
            @display("p=419,366");
        }
        H4: StandardHost {
            @display("p=365,366");
        }
        H1: StandardHost {
            @display("p=160,366");
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=56,34");
        }
        Visualizer: IntegratedCanvasVisualizer {
            @display("p=56,116");
        }
    connections:
        spine1.ethg++ <--> Eth100M <--> leaf1.ethg++;
        spine1.ethg++ <--> Eth100M <--> leaf2.ethg++;
        spine1.ethg++ <--> Eth100M <--> leaf3.ethg++;
        spine1.ethg++ <--> Eth100M <--> leaf4.ethg++;
        spine2.ethg++ <--> Eth100M <--> leaf1.ethg++;
        spine2.ethg++ <--> Eth100M <--> leaf2.ethg++;
        spine2.ethg++ <--> Eth100M <--> leaf3.ethg++;
        spine2.ethg++ <--> Eth100M <--> leaf4.ethg++;
        spine3.ethg++ <--> Eth100M <--> leaf1.ethg++;
        spine3.ethg++ <--> Eth100M <--> leaf2.ethg++;
        spine3.ethg++ <--> Eth100M <--> leaf3.ethg++;
        spine3.ethg++ <--> Eth100M <--> leaf4.ethg++;
        leaf1.ethg++ <--> Eth100M <--> H1.ethg++;
        leaf1.ethg++ <--> Eth100M <--> H2.ethg++;
        leaf1.ethg++ <--> Eth100M <--> H3.ethg++;
        leaf2.ethg++ <--> Eth100M <--> H4.ethg++;
        leaf2.ethg++ <--> Eth100M <--> H5.ethg++;
        leaf2.ethg++ <--> Eth100M <--> H6.ethg++;
        leaf3.ethg++ <--> Eth100M <--> H7.ethg++;
        leaf3.ethg++ <--> Eth100M <--> H8.ethg++;
        leaf3.ethg++ <--> Eth100M <--> H9.ethg++;
        leaf4.ethg++ <--> Eth100M <--> H10.ethg++;
}

