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


def writeRoutes(fileName, numLeaves, numSpines, hostsPerLeaf):
    file = open(fileName, 'w')
    file.write('<config>\n');
    file.write('\t<interface hosts="**" address="10.x.x.x" netmask="255.x.x.x"/>\n\n')

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

    writeBorderSelfRoute(file, numSpines)
    file.write('</config>')


# -----------------------------------------------------------------------------------------------------------------------

# Input - Spines, Leaves, and hosts per each leaf
print("Enter Number of Spines: ")
spines = int(input())

print("Enter Number of Leaves: ")
leaves = int(input())

hostsPerLeafArray = []

for i in range(leaves):
    print("Number of Hosts for leaf", (i + 1))
    hostsPerLeafArray.append(int(input()))

# BorderLeafAppend
hostsPerLeafArray.append(1)

writeRoutes('XHost_SpineLeaf_Routing.xml', leaves, spines, hostsPerLeafArray)
