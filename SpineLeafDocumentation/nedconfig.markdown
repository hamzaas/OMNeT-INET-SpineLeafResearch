---
layout: default
title: NedConfigurator.py
parent: Python Scripts
grand_parent: Code
nav_order: 2
---

# NedConfigurator.py

***

 - `nedConfigurator.py`: This script is responsible for generating a new `ned` file.
Think of the `ned` file as the a configuration file that will be used to build the simulation.
In this file, the python script will change the number of `spines`, `leaves`, and `hostsPerleaf`
to equal the command line input. The input of this program is `input.txt`, the command line
input, and the output is `XHost_SpineLeaf.ned`,  the new `ned` file to be used by the simulation.

 - This script works by taking the format of `.ned` files and copying it while inserting
 the number of `spines`, `leaves`, and `hosts`.

  - The entire `.ned` does not have to be changed, so the static parts are saved in files
  `node_prev.txt`, and `ned_post.txt`. These files are read and written to the new `.ned`
  around the parts that this script generates.

***

The code for this can be found below:

```python
def writePrev(file, prev):
    file.write(prev.read())


def writePost(file, post):
    file.write(post.read())


def writeParameters(file, spines, leaves, hostsPerLeaf):
    file.write('\n\t\tint numSpines = ' + str(spines) + ';\n')
    file.write('\t\tint numLeafs = ' + str(leaves) + ';\n')
    file.write('\t\tint hostPerLeaf = ' + str(hostsPerLeaf) + ';\n\n')


input_file = open('input.txt', 'r').read().splitlines()
ned_new = open('../Spine-Leaf-ManualDCN/_XHostSpineLeaf/XHost_SpineLeaf.ned', 'w')
ned_prev = open('ned_prev.txt', 'r')
ned_post = open('ned_post.txt', 'r')

input_spines = input_file[0]
input_leaves = input_file[1]
input_hosts = input_file[2]

writePrev(ned_new, ned_prev)
writeParameters(ned_new, input_spines, input_leaves, input_hosts)
writePost(ned_new, ned_post)
```
