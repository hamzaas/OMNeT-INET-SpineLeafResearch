---
layout: default
title: RouterConfigurator.py
parent: Python Scripts
grand_parent: Code
nav_order: 1
---

# RouterConfigurator.py

***

 - `RouterConfigurator.py`: This script is responsible for generating the routes, based
off the input, to be used by the simulation. In more detail, this file utilizes INET's
option to [manually override individual routes](https://inet.omnetpp.org/docs/tutorials/configurator/doc/step5.html).
We do this operation because we have developed a custom router module in INET. The output
of this program is `ManualRoutingXML.xml`, the custom routes, and `input.txt`, the command
line input to be used later in the simulation.

 - The script achieves this by taking the number of `leafs`, `spines`, and `hostsPerLeaf`
  as input to the script, and then iterates over all pairs to generate routes from
  host -> leaf -> spine -> leaf -> host.

***

The code that completes this can be seen below.

```python
# Loop for all leaves
    for leaf in range(numLeaves + 1):
        commentPrint = False
        # Loop for leaves in each major subsection
        for leafs in range(numLeaves + 1):
            for host in range(hostsPerLeaf[leafs]):
                for spine in range(spines):
                    if leaf == leafs and leaf != numLeaves:
                        if not commentPrint:
                            file.write('\t<!-- Self Routes -->\n')
                            commentPrint = True
                        writeSelfRoutesToFile(file, leaf, leafs, host, spine, hostsPerLeaf)
                        break
                    elif leaf == numLeaves and leafs < numLeaves:
                        writeOUTBorderRoutesToFile(file, leaf, leafs, host, spine)
                    elif leafs == numLeaves and leaf < numLeaves:
                        writeINBorderRoutesToFile(file, leaf, leafs, host, spine)
                    elif leafs < numLeaves and leaf < numLeaves:
                        writeOtherRoutesToFile(file, leaf, leafs, host, spine)
                file.write('\n')
        file.write('\n\n')
```

 - As it can be seen, there are a few edge cases. In more detail, the idea of `self routes`
can cause some confusion but the idea can be found in this [paper](https://www.sciencedirect.com/science/article/abs/pii/074373159090023I#:~:text=A%20self%2Drouting%20permutation%20network%20is%20a%20connector%20which%20can,its%20inputs%20onto%20its%20outputs.)

- Moreover, this code can seem confusing at first, but the best way to understand it is to look at a snippet
of the output file to see what each `for loop` is doing.

***

Finally, these routes are written to `ManualRoutingXML.xml`, and the methods that do this can be seen below.

```python
def writeSelfRoutesToFile(file, leaf, leafs, host, spine, hostsPerLeaf):
    file.write(
        '\t<route hosts="leaf[' + str(leaf) + '].topOfRack" destination="' + 'leaf[' + str(leafs) + '].' + 'H[' + str(
            host) + ']"' + ' netmask="255.255.255.255" gateway="*" interface="eth' + str(spines + host) +
        '"' + ' metric="*"/>\n')


def writeOtherRoutesToFile(file, leaf, leafs, host, spine):
    file.write('\t<route hosts="leaf[' + str(leaf) + '].topOfRack" destination="' + 'leaf[' + str(leafs) +
               '].' + 'H[' + str(host) + ']"' + ' netmask="255.255.255.255" gateway="*" interface=' '"eth' +
               str(spine) + '"' + ' metric="*"/>\n')


def writeINBorderRoutesToFile(file, leaf, leafs, host, spine):
    file.write('\t<route hosts="leaf[' + str(leaf) + '].topOfRack" destination="' + 'border"' +
               ' netmask="255.255.255.255" gateway="*" interface=' '"eth' +
               str(spine) + '"' + ' metric="*"/>\n')


def writeOUTBorderRoutesToFile(file, leaf, leafs, host, spine):
    file.write('\t<route hosts="borderLeaf" destination="' + 'leaf[' + str(leafs) +
               '].' + 'H[' + str(host) + ']"' + ' netmask="255.255.255.255" gateway="*" interface=' '"eth' +
               str(spine) + '"' + ' metric="*"/>\n')


def writeBorderSelfRoute(file, numSpines):
    file.write('\t<!-- Border Self Routes -->\n')
    file.write('\t<route hosts="borderLeaf" destination="' + 'border"' +
               ' netmask="255.255.255.255" gateway="*" interface=' '"eth' + str(numSpines) + '"' + ' metric="*"/>\n')

def writeVLANS(file, max):
    for lan in range(max):
        file.write('\t<interface hosts="leaf[' + str(lan) + '].**" address="10.0.' + str(lan + 1) + '.x" netmask="255.255.255.x"/>\n')

    file.write('\n\t<interface hosts="**" address="10.0.' + str(max + 1) + '.x" netmask="255.255.255.x"/>\n\n')

def writeRoutes(fileName, numLeaves, numSpines, hostsPerLeaf):
    file = open(fileName, 'w')
    file.write('<config>\n\n');
    #Ip address and Vlans
    #for leaf in range(numLeaves + 1):
    #    file.write('\t<interface hosts="**" address="10.x.x.x" netmask="255.x.x.x"/>\n\n')
```
