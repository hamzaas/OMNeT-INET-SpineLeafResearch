# <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/d7df523fde0cfa57b07f5dae37a566d5afc6c277/images/DCNLogo.png" width="40" height="40"> INET++ ReadMe

Table of Contents
- [Introduction](#introduction)
- [The Problems](#problems)
- [Things We Changed](#changes)
- [Troubleshooting/Where to Get Support](#support)
- [Licensing](#licensing)

---

## Introduction <a name ="introduction"></a>

INET++ is a extension framework for OMNeT++ that allows the ability to drag and drop network devices. INET comes with a lot of nice features to allow you to build and test networks. 

## The Problem <a name ="problems"></a>

INET offers a lot of nice built in features. However to create our spine-leaf data center network we need to create our own "random router". We need to implement a truly random routing feature for the TopOfRack routers in the leaves. In a spine-leaf network, the leaf will randomly choose a spine to send the current packet. This allows the traffic load on each spine to be balanced. To our knowledge INET has no router or switch that allows for the random routingness. So we must create our own. Which is explained in the next section. It sounds pretty basic but INET does a very nice job of creating these devices from the very low level. Its all very modular. The picture below shows the router module. Which is made up of many smaller modules inside. So we will have to change a lot of things. For example, the routing tables that were being used inside of the basic router would not keep duplicate equal routes. For example if a host to host connection had multiple equal routes it would only keep the first / "defualt" route and discard the other routes. We have to create our own routing table module to save all equal routes.


## Things We Changed.<a name ="changes"></a>

Any file that we had to make/change of INET++ will have a \[RT\]. This signifyes that we have created that file.
## FAQs<a name ="faq"></a>

 - An error is received when attempting to run the program.
    - Try cleaning and rebuilding the workspace.
    - Make sure the ini_generated.ini file has the correct line commented out.
    
 - Is this project finished?
    - No, this project is still under construction by Ethan Little and Bryan Hill. We are both research assistants at Appalachian State University.
    - Will continue to update and work on this project.

## Troubleshooting/Where to Get Support<a name ="support"></a>

For more help with OMNeT++, please visit [OMNeT++ User Manual](https://doc.omnetpp.org/omnetpp4/manual/usman.html). </br>
For more help with INET, please visit [INET's User Guide](https://inet.omnetpp.org/docs/users-guide/) </br>
For more help with INET's Framework, please visit [INET's Framework Manual](https://doc.omnetpp.org/inet/api-current/neddoc/index.html) </br>

## Licensing<a name ="licensing"></a>

This project is free to use by anyone. It is intended for other data center researchers and data center enthusiasts.
