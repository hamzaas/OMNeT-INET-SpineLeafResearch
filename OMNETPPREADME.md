# <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/d7df523fde0cfa57b07f5dae37a566d5afc6c277/images/DCNLogo.png" width="40" height="40"> OMNET++ README

Table of Contents
- [Introduction](#introduction)
- [Launching](#launch)
- [The .ini File](#ini)
- [The NED File](#ned)
- [Simulation GUI](#simulation)
- [Troubleshooting/Where to Get Support](#support)
---

## Introduction <a name ="introduction"></a>

"OMNeT++ is an extensible, modular, component-based C++ simulation library and framework, primarily for building network simulators." - [Omnetpp.org](https://omnetpp.org/intro/). OMNeT++ is basically an IDE for network simulations. 

## Launching<a name ="launch"></a>
1. Launching OMNet++ GUI is pretty simple. Open up the mingwenv commad line prompt. It will be located in the sub-root directory of the omnetpp-5.6.2-src-windows folder. I would just make a shortcut and put this on the desktop. 
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/f7106e9d90757ca00aff4a01143e4ff52bee2c01/images/RunTheGUI.PNG">
</p>

2. Once the command line opens. Simply type 'omnetpp' and hit enter. You will be spending 90% of your time in the GUI. The GUI is where you will be making, building, testing, and implementing your projects. The command line is used more when you are running your simulation for long periods of time to gather results.
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/f7106e9d90757ca00aff4a01143e4ff52bee2c01/images/RunTheGUIFromCMD.PNG">
</p>

## The .ini File <a name ="ini"></a>

The .ini is a important file for a project. Think of it as a configuration file for your network simulation. You must have one to run your network simulation. To run your simulation you must click on the .ini file so that it is highlighted and then hit the green run arrow button at the top of the IDE. 

Below is a very simple example of a .ini file. I will try to break it down for you. You can also look at [OMNeT++'s Configuration File #sec330](https://doc.omnetpp.org/omnetpp4/manual/usman.html#sec330).

1. The first thing we notice is the Traffic Headings. When you run your simulation you have the option to run different traffics on the network. So when you click launch it will ask you which traffic heading you will like to run. There must be a General for a .ini file.

2. The next thing a .ini file needs is to know what network to preform the traffic on. That is the following line under General. Every .ini file must have this as well. 

3. Finally under each traffic heading is the traffic specification. Which is broken down into appalications on eact host.
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/f7106e9d90757ca00aff4a01143e4ff52bee2c01/images/Example%20ini%20file.PNG">
</p>

## The NED File <a name ="ned"></a>

The NED file is also a critical file to your network simulation as it describes your network topology. With OMNeT alone building network topologies can be difficult. That is why we use INET++. INET is an extension to OMNeT++ and allows us to drag and drop routers, servers, switches, radios, ethernet cables, and like a 1,000 different things. 
Now back to the NED file. The NED file has two tabs. You can build and edit using either tab.
1. The Design tab. Shows you the actual look of your network.
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/f7106e9d90757ca00aff4a01143e4ff52bee2c01/images/Example%20NED%20file.PNG">
</p>
3. The Source tab. Shows you the code to the network. Inside the source tab you can see the network class. That name goes into your .ini file.
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/f7106e9d90757ca00aff4a01143e4ff52bee2c01/images/Example%20NED%20file%20source.PNG">
</p>

## Simulation GUI <a name ="simulation"></a>

When you run you simulation the simulation GUI will pop up. In here you can visualy watch your netork simulation run. Which is really nice for testing and debugging but can be very slow when trying to run your simulation for a long period of time to gather results. 
1. The first thing you will notics is the simulation time and tools. The time at the top right is simulation time. The tools to the left of it just simply change the real-time speed. 
2. The second thing you should focus on is the green background portion of the GUI. This is where the actual simulation visualization takes place.
3. The last thing is the console at the bottom. Can be very useful for debug purposes. 
More information about the simulation can be found here: [OMNeT++ simulation GUI #Chapter 7.1](https://doc.omnetpp.org/omnetpp/UserGuide.pdf).
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/f7106e9d90757ca00aff4a01143e4ff52bee2c01/images/SimulationGUI.PNG">
</p>

## Troubleshooting/Where to Get Support<a name ="support"></a>

OMNeT++ Manual, please visit [OMNeT++ User Manual](https://doc.omnetpp.org/omnetpp4/manual/usman.html). </br>
OMNeT++ User Guid, please visit [OMNeT++ User Guid](https://doc.omnetpp.org/omnetpp/UserGuide.pdf). </br>
