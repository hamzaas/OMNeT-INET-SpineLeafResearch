# <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/d7df523fde0cfa57b07f5dae37a566d5afc6c277/images/DCNLogo.png" width="40" height="40"> OMNeT-INET-SpineLeafResearch

Table of Contents
- [Introduction](#introduction)
- [System Requirements](#equipment)
- [Installation](#installation)
- [Running in GUI](#runningGUI)
- [Running in Command Line](#runningCMD)
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

***Installing OMNeT++ version 5.6.2***

1. Go to [OMNeT++'s download page](https://omnetpp.org/download/.) and download the windows version.
	- *Note:* This simulation was built on Windows operating system. Other operating systems can lead to future errors.

2. Follow the installation process from [OMNeT++'s installation guide](https://omnetpp.org/download/.).
	- *Note:* Ensure the OMNeT++ is working properly before proceeding by following the installation guide.

3. Launch the OMNet++ GUI.
	- You do not have to install the INET Framework, as we have our 'own' INET Framework that is specific to our Spine-Leaf Datacenter.
	- If you have already installed the INET Framework. You may delete it from the workspace or leave it. Our simulation will not touch it.

***Installing our repository into OMNeT++.***

4. Download our repository. 
	- There are two main projects in our repository that you will have to import into OMNet++. The inet-4.2.0u and Spine-Leaf-ManualDCN. The inet-4.2.0u is basically an OMNeT++ extension (INeT version 4.2.0) that we have modified to allow the functionality of a Spine Leaf data center topology. The Spine-Leaf-ManualDCN is where the actual network is located. You will need to import both these projects into OMNet++. </br>

5. In the workspace section, click on Import Projects.
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/1891ca423db15d5cce0c28f0714fb3614f481e72/images/Import.PNG">
</p>

6. Then click Existing Projects Into Workspace.
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/1891ca423db15d5cce0c28f0714fb3614f481e72/images/ExistingProject.PNG">
</p>

7. Click browse and select the folder from our repository.
	- The folder should include both inet-4.2.0u and Spine-Leaf-ManualDCN.
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/f03daf70ca3fe0c10e68581c89ccd0c75ddf922a/images/BrowesProjects.PNG">
</p>

8. Click Finish.

9. Confirm that Spine-Leaf-ManualDCN is referencing inetu by right-clicking Spine-LeafDCN and click on properties.

10. From the properties click on project references and make sure inetu is checked.
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/1891ca423db15d5cce0c28f0714fb3614f481e72/images/Refrence.PNG">
</p>

10. Finally, build the workspace. Right-click the workspace and click Build Project.

## Running from the GUI.<a name ="runningGUI"></a>

1. First, check the ini_generated.ini file and reassure that the correct line is uncommented to run in GUI.
	- The path changes when running from the command line to GUI.
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/e04cf5e287cfdae7afa80950a65fb662cc8c7a5f/images/RunFromGUI.PNG">
</p>

2. Click on the ini_generated.ini file and hit the OMNeT++ run button located at the top of the editor.

## Running from the command line.<a name ="runningCMD"></a>

1. First check the ini_generated.ini file and make sure that the correct line is uncommented to run in the command line.
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/e04cf5e287cfdae7afa80950a65fb662cc8c7a5f/images/RunFromCommandLine.PNG">
</p>

2.  Now open the mingwen terminal and go to Spine-Leaf-ManualDCN directory.

3.  Run the command below.
	- More information can be found about the OMNeT++ command line here: [OMNeT++ Manual #Section 360](https://doc.omnetpp.org/omnetpp4/manual/usman.html#sec360).
<p align="center">
    <img src="https://github.com/littleet9/OMNeT-INET-SpineLeafResearch/blob/22dc51beecc7ab03fffe2e8d13c2db9ba5f6d872/images/RunCommands.PNG">
</p>

The command line will prompt and ask you for the parameters of the network. Once the simulation finishes, you can view the results inside of the OMNeT++ GUI. More information on OMNeT++'s data visualization tool can be found here: [OMNeT++ Manual #Section 401](https://doc.omnetpp.org/omnetpp4/manual/usman.html#sec401).

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

This project is free to use by anyone. It's intended for other data center researchers and data center enthusiasts.
