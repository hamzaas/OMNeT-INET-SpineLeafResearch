def writePrev(file, prev):
    file.write(prev.read())


def writePost(file, post):
    file.write(post.read())


def writeParameters(file, spines, leaves, hostsPerLeaf):
    file.write('\n\t\tint numSpines = ' + str(spines) + '\n')
    file.write('\t\tint numLeafs = ' + str(leaves) + '\n')
    file.write('\t\tint hostPerLeaf = ' + str(hostsPerLeaf) + '\n\n')


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
