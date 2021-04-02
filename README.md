# <img src="" width="24" height="24"> OMNeT-INET-SpineLeafResearch

Table of Contents
- [Introduction](#introduction)
- [System Requirements](#equipment)
- [Installation/use instructions](#installation)
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

2. Follow the installation process from [OMNeT++'s installation guide](https://omnetpp.org/download/.).<br/>
	- *Note:* Ensure the OMNeT++ is working properly before proceeding, by following the installation guide.

3. Launch the OMNet++ GUI. <br/>
	- You do not have to install the INET Framework, as we have our 'own' INET Framework that is specific to our Spine-Leaf Datacenter.
	- If you have already installed the INET Framework. You may delete it from the workspace, or leave it. Our simulation will not touch it.

Installing our repository into OMNeT++.

4. Download our repository. There are two main projects in our repository that you will have to import into OMNet++. The inet-4.2.0u and Spine-Leaf-ManualDCN. The inet-4.2.0u is basically an OMNeT++ extension (INeT version 4.2.0) that we have modified to allow the functionality of a Spine Leaf data center topology. The Spine-Leaf-ManualDCN is where the actual network is located. You will need to import both these projects into OMNet++. </br>

5. Right click on the workspace in OMNeT++ and click Import.

6. Then click Existing Projects Into Workspace and select our repository.

7. Confirm that Spine-Leaf-ManualDCN is referencing inetu by right clicking Spine-LeafDCN and click on properties.

8. From the properties click on project references and make sure inetu is checked.

Running the simulation.
<p> You may run our simulation from inside the OMNeT++ GUI. Or 

5. Click the button for the appropriate version of Eclipse you need.
    - *Note:* If unsure, the "Eclipse IDE for Java Developers" will suffice for most cases.

6. Click the large Install Button.<br/>
    - *Note:* Choose a different installation path here if desired. You can also choose to uncheck "create start menu entry" or "create desktop shortcut" options if desired.                                                                                               
    
7. Wait for the installation to finish.<br/>

You may now use Eclipse however you wish. If you selected "create desktop shortcut" then you can find the Eclipse icon on your desktop which can be used to launch the application. Otherwise, you may have to open the path which you installed the application to and launch from there by opening "eclipse.exe".

## FAQs<a name ="faq"></a>

 - How can I tell if I have Java installed?
    - Open the command prompt (*Note:* This can be done by pressing  + R then running "cmd").
    - Type "java -version" and press enter.
    - If the returned message displays a version of Java such as 1.8.0_241 then Java is installed an configured.
    
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

For more help with Eclipse or help with other issues, please visit [Eclipse's help page](https://help.eclipse.org/2020-03/index.jsp).

## Licensing<a name ="licensing"></a>

Eclipse is an open-source piece of software which abides by a Public License. For more info about the Eclipse Public License (EPL) click [here](https://www.eclipse.org/legal/epl-2.0/).
