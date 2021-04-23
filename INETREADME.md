# <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/d7df523fde0cfa57b07f5dae37a566d5afc6c277/images/DCNLogo.png" width="40" height="40"> INET++ ReadMe

Table of Contents
- [Introduction](#introduction)
- [The Problems](#problems)
- [The Changes](#changes)
- [Troubleshooting/Where to Get Support](#support)
- [Licensing](#licensing)

---

## Introduction <a name ="introduction"></a>

INET++ is a extension framework for OMNeT++ that allows the ability to drag and drop network devices. INET comes with a lot of nice features to allow you to build and test networks. 

## The Problem <a name ="problems"></a>

INET offers a lot of nice built in features. However to create our spine-leaf data center network we need to create our own "random router". We need to implement a truly random routing feature for the TopOfRack routers in the leaves. In a spine-leaf network, the leaf will randomly choose a spine to send the current packet. This allows the traffic load on each spine to be balanced. To our knowledge INET has no router or switch that allows for the random routingness. So we must create our own. Which is explained in the next section. It sounds pretty basic but INET does a very nice job of creating these devices from the very low level. Its all very modular. The picture below shows the router module. Which is made up of many smaller modules inside. So we will have to change a lot of things. For example, the routing tables that were being used inside of the basic router would not keep duplicate equal routes. For example if a host to host connection had multiple equal routes it would only keep the first/"defualt" route and discard the other routes. We have to create our own routing table module to save all equal routes.
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/d28e49f5e60513ab90afe7d97816dd5a535c4334/images/RouterModule.PNG">
</p>

## The Changes <a name ="changes"></a>

Any file that we had to make in INET++ directory will have a \[RT\] at the begining of the file name. The RT simply stands for ResearchTeam and the \[RT\] is placed at the begining of the file so that that file will appear first alphbetically.
Ok now INET is setup like building blocks. Multiple modules put together will create one module. So if we want to change one part of a basic router to create our random routingness then we have to change every link that refrences it. The picture below is an example of us trying to create our own routing table module. Every module with an astriek next to it a module we will have to create and rename to point it to our own routing table module.
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/5bd1ecb688f58616fb6d74c79223a113ab6c172a/images/RouterBreakDown.PNG">
</p>
Ok so at this point to make one change you have to create a new end of web of modules to implement this change. The majority of our changes take place in the \[RT\]Ipv4RoutingTableLR. We first changed the data structure of the routingCache from a vector to a hashmap of vectors. To allow the ability to hold multiple routes for a given destination. Previously only the best route was stored for the destination. Now in the findBestMatchingRoute method we implemented our randomness routing algorithm. Basically if a packet has multiple same distance routes that it can take than it will randomly select one. So for example if Leaf5 wants to communicate to Leaf2 then there will be spine number of routes to choose from. 
And that's it. Kinda. After implementing this we came across multiple problems with the arp module and defualt routes. Minor changes and fixes were made to fix these problems. Actually we had to create a similar new Arp module that had the same data structure as the routing table module because they work hand in hand, it was a lot work than I am crediting. Anyways thats pretty much it to get the good understanding of what we did.

## Troubleshooting/Where to Get Support<a name ="support"></a>

For more help with OMNeT++, please visit [OMNeT++ User Manual](https://doc.omnetpp.org/omnetpp4/manual/usman.html). </br>
For more help with INET, please visit [INET's User Guide](https://inet.omnetpp.org/docs/users-guide/) </br>
For more help with INET's Framework, please visit [INET's Framework Manual](https://doc.omnetpp.org/inet/api-current/neddoc/index.html) </br>

## Licensing<a name ="licensing"></a>

This project is free to use by anyone. It is intended for other data center researchers and data center enthusiasts.
