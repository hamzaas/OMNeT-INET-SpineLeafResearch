#!/bin/bash


# Building topology info and saving input
cd ../Python\ Scripts
touch mainCSV.csv
py RouterConfigurator.py
rm ../Spine-Leaf-ManualDCN/_XHostSpineLeaf/ManualRoutingXML.xml
mv ManualRoutingXML.xml ../Spine-Leaf-ManualDCN/_XHostSpineLeaf/ManualRoutingXML.xml

#Creating New .ned file
py nedConfigurator.py

# Creating Traffic based on topology input
py SendScript.py < input.txt
rm ../Spine-Leaf-ManualDCN/_XHostSpineLeaf/ini_generated.ini
mv ini_generated.ini ../Spine-Leaf-ManualDCN/_XHostSpineLeaf/ini_generated.ini


