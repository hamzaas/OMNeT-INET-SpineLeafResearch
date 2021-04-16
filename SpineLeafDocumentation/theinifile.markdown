---
layout: default
title: The .ini File
parent: OMNeT++
grand_parent: Code
nav_order: 2
---

# The .ini File

***

The .ini is a important file for a project. Think of it as a configuration file for your network simulation. You must have one to run your network simulation. To run your simulation you must click on the .ini file so that it is highlighted and then hit the green run arrow button at the top of the IDE.


Below is a very simple example of a .ini file. I will try to break it down for you. You can also look at [OMNeT++'s Configuration File #sec330](https://doc.omnetpp.org/omnetpp4/manual/usman.html#sec330).

***

1. The first thing we notice is the Traffic Headings. When you run your simulation you have the option to run different traffics on the network. So when you click launch it will ask you which traffic heading you will like to run. There must be a General for a .ini file.

2. The next thing a .ini file needs is to know what network to preform the traffic on. That is the following line under General. Every .ini file must have this as well.

3. Finally under each traffic heading is the traffic specification. Which is broken down into appalications on eact host.

 - ![](images\i1.png)
