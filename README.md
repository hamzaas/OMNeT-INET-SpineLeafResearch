# <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/d7df523fde0cfa57b07f5dae37a566d5afc6c277/images/DCNLogo.png" width="40" height="40"> OMNeT-INET-SpineLeafResearch

Table of Contents
- [Introduction](#introduction)
- [System Requirements](#equipment)
- [Installation](#installation)
- [Running the Simulation](#running)
- [FAQs](#faq)
- [Troubleshooting/Where to Get Support](#support)
- [Licensing](#licensing)

---

## Introduction <a name ="introduction"></a>

OMNeT-INET-SpineLeafResearch is a simulation of a spine-leaf data center network implemented in Omnetpp and INET. This simulation allows for the data center to be scalable and customizable. Our custom traffic generator also allows for different sized traffic even on different sized networks. This project is intended for research purposes. It was developed as a research project by two students at Appalachian State University. 

## System Requirements<a name ="equipment"></a>

| Minimum | Recommended |
|---------|-------------|
|2GB RAM|3GB+ RAM     |
|3GB Disk Space|5GB+ Disk Space|
|3.5Ghz Processor|3.7Ghz+ Processor|

## Installation/use instructions<a name ="installation"></a>

Installing OMNeT++ version 5.6.2

1. Go to [OMNeT++'s download page](https://omnetpp.org/download/.).
	- *Note:* This simulation was built on Windows operating system. Other operating systems can lead to future erros.

2. Follow the installation process from [OMNeT++'s installation guide](https://omnetpp.org/download/.).
	- *Note:* Ensure the OMNeT++ is working properly before proceeding, by following the installation guide.

3. Launch the OMNet++ GUI.
	- You do not have to install the INET Framework, as we have our 'own' INET Framework that is specific to our Spine-Leaf Datacenter.
	- If you have already installed the INET Framework. You may delete it from the workspace, or leave it. Our simulation will not touch it.

Installing our repository into OMNeT++.

4. Download our repository. There are two main projects in our repository that you will have to import into OMNet++. The inet-4.2.0u and Spine-Leaf-ManualDCN. The inet-4.2.0u is basically an OMNeT++ extension (INeT version 4.2.0) that we have modified to allow the functionality of a Spine Leaf data center topology. The Spine-Leaf-ManualDCN is where the actual network is located. You will need to import both these projects into OMNet++. </br>

5. Right click on the workspace in OMNeT++ and click Import.

6. Then click Existing Projects Into Workspace and select our repository.

7. Confirm that Spine-Leaf-ManualDCN is referencing inetu by right clicking Spine-LeafDCN and click on properties.

8. From the properties click on project references and make sure inetu is checked.

## Running the simulation.<a name ="running"></a>
<p> You may run our simulation from inside the OMNeT++ GUI or from command line. </p>

Running from the GUI.

1. First check the XHost_SpineLeaf.ini file and make sure that the correct line is uncommented to run in GUI.
	- The path changes when running from command line to GUI.
2. Click on the XHost_SpineLeaf.ini file and hit the OMNeT++ run button at the top of the editor.

Running from the command line.

1. First check the XHost_SpineLeaf.ini file and make sure that the correct line is uncommented to run in the command line.

2.  Now open the mingwen terminal and go to Spine-Leaf-ManualDCN directory.

3.  Run the command below.
	- More information can be found about the OMNeT++ command line here: [OMNeT++ Manual #Section 360](https://doc.omnetpp.org/omnetpp4/manual/usman.html#sec360).

The command line will prompt and ask you for the parameters of the network. Once the simulation has finished you can view the results inside of the OMNeT++ GUI. More information on OMNeT++'s data visualization tool can be found here: [OMNeT++ Manual #Section 401](https://doc.omnetpp.org/omnetpp4/manual/usman.html#sec401).

## FAQs<a name ="faq"></a>

 - An error is recieved when attempting to run the program.
    - Try cleaning and rebuilding the workspace.
    - Make sure the XHost_SpineLeaf.ini file has the correct line commeted out.
    
 - How can I install plug-ins?
    - Open Eclipse.
    - Open the "Help" menu in the top naviation bar.
    - Click "Install New Software".
    - Search for your desired plug-in.
    - Follow the printed on screen instructions to installed the plug-in.
    
 - How do I change Eclipse's appearance?
    - Open Eclipse.
    - Open the "Window" menu in the top naviagation bar.
    - Click "Preferences".
    - Expand the "General" menu.
    - Select "Appearance".
    - You can now select your desired *Theme* and *Color and Font theme* from the appropriate drop down.
        - *Note:* Additional themes can be installed through the marketplace. See "How can I install plug-ins?" above.

## Troubleshooting/Where to Get Support<a name ="support"></a>

For more help with OMNeT++, please visit [OMNeT++ User Manual](https://doc.omnetpp.org/omnetpp4/manual/usman.html).
For more help with INET, please visit [INET's User Guide](https://inet.omnetpp.org/docs/users-guide/)
For more help with INET's Framework, please visit [INET's Framework Manual] (https://doc.omnetpp.org/inet/api-current/neddoc/index.html)

## Licensing<a name ="licensing"></a>

This project is free to use by anyone. It is intended for other data center researchers and data center enthusiasts.
