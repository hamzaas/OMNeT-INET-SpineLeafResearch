---
layout: page
title: Installation
nav_order: 2
---

# **Installation**

***

_Table of Contents_
1. [System Requirements](#system-requirements)
2. [Installing OMNeT++ 5.6.2](#installing-omnet-version-562)
3. [Installing Repository into OMNeT++](#installing-our-repository-into-omnet)

***

### System Requirements

| Minimum          | Recommended       |
|:-----------------|:------------------|
| 2GB RAM          | 3GB+ RAM          |
| 3GB Disk Space   | 5GB+ Disk Space   |
| 3.5Ghz Processor | 3.7Ghz+ Processor |

***

### Installing OMNeT++ version 5.6.2

<br/>

1. **Go to [OMNeT++'s download page](https://omnetpp.org/download/) and download the windows version.**\
  - _Note: This simulation was built on Windows operating system.
 Other operating systems can lead to future errors._{:.text-grey-dk-200}

 2. **Follow the installation process from [OMNeT++'s installation guide](https://doc.omnetpp.org/omnetpp/InstallGuide.pdf).**\
  - _Note: Ensure the OMNeT++ is working properly before proceeding,
 by following the installation guide._{:.text-grey-dk-200}

 3. **Launch the OMNet++ GUI.**
  - You do not have to install the INET Framework, as we have our 'own' INET
  Framework that is specific to our Spine-Leaf Datacenter.
  - If you have already installed the INET Framework. You may delete it from the
  workspace, or leave it. Our simulation will not touch it.

***

### Installing our repository into OMNeT++.

<br/>

1. **Download our repository.**
 - There are two main projects in our repository that you will have to import into
OMNet++. The inet-4.2.0u and Spine-Leaf-ManualDCN. The inet-4.2.0u is basically an
OMNeT++ extension (INeT version 4.2.0) that we have modified to allow the
functionality of a Spine Leaf data center topology. The Spine-Leaf-ManualDCN is
where the actual network is located. You will need to import both these projects
into OMNet++.

2. **In the workspace section, click on Import Projects.**
 - ![](images\s3.png)
3. **Then click Existing Projects Into Workspace./**
- ![](images\s4.png)

4. **Click browse and select the folder from our repository.**
 - The folder should include both inet-4.2.0u and Spine-Leaf-ManualDCN.
 - ![](images\s5.png)

5. **Click Finish.**

6. **Confirm that Spine-Leaf-ManualDCN is referencing inetu by right-clicking Spine-LeafDCN and click on properties.**

7. **From the properties click on project references and make sure inetu is checked.**
 - ![](images\s6.png)

8. **Finally, build the workspace. Right-click the workspace and click Build Project.**
