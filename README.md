# OMNeT-INET-SpineLeafResearch

Code for SpineLeaf DCN implemented in Omnetpp and INET.


### Installing and Running ###

1) First step is to install OMNet++ version 5.6.2. We used the windows version, but other operating systems should work as well.
      You can install here: https://omnetpp.org/download/. Make sure it is 5.6.2 before preceding.
      
2) Follow the installation setup. I would highly recommend following the instructions found here: https://doc.omnetpp.org/omnetpp/InstallGuide.pdf.
      The installation guide is for version 5.6.1 but it should still be fine. Make sure OMNet++ is working properly before proceeding. 
      ./configure and 'make' can take a while.
      
3) Launch the OMNet++ GUI. Do not install the INET Framework, as we have our 'own' INET Framework that is specific to our Spine-Leaf Datacenter.

4) Go ahead and download our repository. There are two main projects in our repository that you will have to import into OMNet++.
      The inet-4.2.0u and Spine-Leaf-ManualDCN. The inet-4.2.0u is basically an OMNeT++ extension (INeT version 4.2.0) that we have modified to allow the 
      functionality of a Spine Leaf data center topology. The Spine-Leaf-ManualDCN is where the actual network is located. You will need to import
      both these projects seperately into OMNet++. To do this we recommend launching the GUI. 
      To import the projects into OMNeT++ General > Existing Projects Into Workspace
      
5) Once you have imported both projects into OMNet++. Confirm that Spine-Leaf-ManualDCN is referencing inetu. Right click Spine-LeafDCN, then go to
      properties > project references, and make sure inetu is checked.
      
 From here you can either run in the GUI or follow the below steps to run from command line.

6) Another thing you need to check is in Spine-LeafDCN > _XHost_SpineLeaf > XHost_SpineLeaf.ini and make sure that the "**.configurator.config = xmldoc" value
      is set to the command line option. Just simply comment out the GUI value and comment in the commmand line value. Should be the line adjacent.
      
7) Make sure you save anything and go ahead and close out of the GUI. Now inside the mingwen terminal go into the Spine-Leaf-ManualDCN directory. 

8) Run the command below. I'll break down the command for ya. The first argument is the executable to run the Spine Leaf simulation. The "-u Cmdenv"
      argument tells OMNeT++ to run the simulation in the terminal. The "-f _XHostSpineLeaf/XHostSpineLeaf.ini" argument directs it to the ini file 
      we want to run. The "-c Traffic_1" is the configuration within the .ini file we want to run. If you would like to learn more about the command
      line interface you can look at this: https://doc.omnetpp.org/omnetpp4/manual/usman.html#sec360

      ./Spine-LeafDCN.exe -u Cmdenv -f _XHostSpineLeaf/XHost_SpineLeaf.ini -c Traffic_1
      
      
### Useful links ####

1) OMNeT++ user Manual : https://doc.omnetpp.org/omnetpp4/manual/usman.html
2) INET User Guide : https://inet.omnetpp.org/docs/users-guide/
3) INET Framework Manual : https://doc.omnetpp.org/inet/api-current/neddoc/index.html

