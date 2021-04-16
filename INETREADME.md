# <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/d7df523fde0cfa57b07f5dae37a566d5afc6c277/images/DCNLogo.png" width="40" height="40"> OMNeT-INET-SpineLeafResearch

Table of Contents
- [Introduction](#introduction)
- [Installation](#installation)
- [Things we Changed](#changes)
- [Troubleshooting/Where to Get Support](#support)
- [Licensing](#licensing)

---

## Introduction <a name ="introduction"></a>

INET++ is a extension framework for OMNeT++ that allows the ability to drag and drop network devices. INET comes with a lot of nice features to allow you to build and test networks. 

## Installation/use instructions<a name ="installation"></a>

Since we made changes to INeT++. We included INeT++ in out github repoistory.

## Running from the GUI.<a name ="runningGUI"></a>

1. First check the ini_generated.ini file and make sure that the correct line is uncommented to run in GUI.
	- The path changes when running from the command line to GUI.
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/e04cf5e287cfdae7afa80950a65fb662cc8c7a5f/images/RunFromGUI.PNG">
</p>

2. Click on the ini_generated.ini file and hit the OMNeT++ run button at the top of the editor.

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
