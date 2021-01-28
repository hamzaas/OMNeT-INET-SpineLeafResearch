package _2HostSpineLeaf;
import _XHostSpineLeaf.LeafRouter;
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
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.node.ethernet.Eth100M;
import inet.node.inet.Router;
import inet.node.inet.StandardHost;
import inet.visualizer.integrated.IntegratedCanvasVisualizer;


//
// TODO documentation
//
network RandomTestingTopology
{
    @display("bgb=780,557");
    submodules:
        spine1: Router {
            @display("p=245,265");
        }
        spine2: Router {
            @display("p=404,265");
        }
        spine3: Router {
            @display("p=569,265");
        }
        H0: StandardHost {
            @display("p=404,510");
        }
        H1: StandardHost {
            @display("p=404,48");
        }
        leaf1: LeafRouter {
            @display("p=404,405");
        }
        configurator: Ipv4NetworkConfigurator {
            @display("p=56,34");
        }
        Visualizer: IntegratedCanvasVisualizer {
            @display("p=45,116");
        }
        leaf2: LeafRouter {
            @display("p=404,130");
        }
    connections:
        leaf1.ethg++ <--> Eth100M <--> spine1.ethg++;
        leaf1.ethg++ <--> Eth100M <--> spine2.ethg++;
        leaf1.ethg++ <--> Eth100M <--> spine3.ethg++;
        leaf1.ethg++ <--> Eth100M <--> H0.ethg++;
        spine1.ethg++ <--> Eth100M <--> leaf2.ethg++;
        spine2.ethg++ <--> Eth100M <--> leaf2.ethg++;
        spine3.ethg++ <--> Eth100M <--> leaf2.ethg++;
        leaf2.ethg++ <--> Eth100M <--> H1.ethg++;
}

