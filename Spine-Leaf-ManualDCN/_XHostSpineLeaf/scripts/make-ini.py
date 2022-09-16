from math import ceil
from random import randrange, seed, choice
def traffic_generation(leaf_count, host_count):

	config = ''
	config += '[Config test]\n\n'
	config += 'description = Test config for traffic generation\n'
	destinations = []
	for i in range(leaf_count):
		for j in range(host_count):
			destinations.append((i, j))
	for i in range(leaf_count):
		for j in range(host_count):
			connections = randrange(0, ceil(leaf_count * host_count * .1))+1
			config += f'**.leaf[{i}].H[{j}].numApps = {connections}\n'
			config += f'**.leaf[{i}].H[{j}].app[0].typename = "TcpSinkApp"\n'
			for l in range(1, connections):
				x = choice(destinations)
				while x[0] == i and x[1] == j:
					x = choice(destinations)
				if (randrange(0, 4) > 2):
					config += f'**.leaf[{i}].H[{j}].app[{l}].typename = "TcpSessionApp"\n'
					config += f'**.leaf[{i}].H[{j}].app[{l}].tOpen = {randrange(1, 15)}s\n'
					config += f'**.leaf[{i}].H[{j}].app[{l}].tSend = {randrange(1, 15)}s\n'
					config += f'**.leaf[{i}].H[{j}].app[{l}].sendBytes = {randrange(10, 300)}MiB\n'
					config += f'**.leaf[{i}].H[{j}].app[{l}].tClose = {randrange(0, 15)}s\n'
					config += f'**.leaf[{i}].H[{j}].app[{l}].connectAddress = moduleListByPath("*.leaf[{i}].H[{x[1]}]")\n'
					config += '\n'
				else:
					config += f'**.leaf[{i}].H[{j}].app[{l}].typename = "TcpSessionApp"\n'
					config += f'**.leaf[{i}].H[{j}].app[{l}].tOpen = {randrange(1, 15)}s\n'
					config += f'**.leaf[{i}].H[{j}].app[{l}].tSend = {randrange(1, 15)}s\n'
					config += f'**.leaf[{i}].H[{j}].app[{l}].sendBytes = {randrange(10, 300)}MiB\n'
					config += f'**.leaf[{i}].H[{j}].app[{l}].tClose = {randrange(0, 15)}s\n'
					config += f'**.leaf[{i}].H[{j}].app[{l}].connectAddress = moduleListByPath("*.leaf[{x[0]}].H[{x[1]}]")\n'
					config += '\n'
			config += '\n'
	return config



seed(31337)

#ned = open('../OWCellGrid.ned', 'r')
ini = open('../ini_generated.ini', 'r')

leaf_count = -1
host_count = -1

file = ini.readlines()

for line in file:
	if "**.leafs" in line:
		leaf_count = int(line.split("=")[1])

for line in file:
	if "**.hosts" in line:
		host_count = int(line.split("=")[1])



print(f'leafs: {leaf_count}, hosts: {host_count}\n')

newfile = []
for line in file:
	if "########" in line:
		newfile.append(line)
		break
	else:
		newfile.append(line)

ini.close()
ned = open('../ini_generated.ini', 'w')
for i in newfile:
	ned.write(i)

ned.write(traffic_generation(leaf_count, host_count))





ini.close()

