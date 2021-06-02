import math
import random
#import argparse

APPLICATION_PERCENTAGE = 0.2
INTER_INTRA_PERCENTAGE = 2
MICE_ELEPHANT_PERCENTAGE = 2
ON_OFF_PERCENTAGE = 2
MAX_SECONDS = 3600
MICE_MIN = 100
MICE_MAX = 300
ELEPHANT_MIN = 1400
ELEPHANT_MAX = 1500


def write_configs(new_ini, ini_base):
    new_ini.write(ini_base.read())


def write_send_script(new_ini, send_script_string, app):
    new_ini.write(app + ".sendScript = \"" + send_script_string + "\"\n")


def write_connect_address(new_ini, connect_app, connect_address):
    new_ini.write(connect_app + ".connectAddress = \"" + connect_address + "\"\n")


def write_applications(new_ini, num_apps):
    new_ini.write("\n[Config scriptTraffic]\n")
    new_ini.write("\n**.packetCapacity = 20\n")
    new_ini.write("#Number of apps for all hosts\n")
    new_ini.write("**.leaf[*].H[*].numApps = " + str(num_apps) + "\n\n")
    new_ini.write("#TcpSinkApp for all hosts (to handle any incoming packets)\n")
    new_ini.write("**.leaf[*].H[*].app[0].typename = \"TcpSinkApp\"\n\n")
    new_ini.write("#TcpSession application settings\n")
    new_ini.write("**.leaf[*].H[*].app[1..].typename = \"TcpSessionApp\"\n")
    new_ini.write("**.leaf[*].H[*].app[1..].tSend = 0\n")
    new_ini.write("**.leaf[*].H[*].app[1..].sendBytes = 0\n\n")


def writeToMap(map, key):
    if key in map:
        map[key] += 1
    else:
        map[key] = 1


# Main Calls

graphical_mode = bool(int(input("Enter 0 for Terminal Mode enter 1 for Graphical Mode: ")))


new_ini_file = open('ini_generated.ini', 'w')

if graphical_mode:
	ini_base_file = open('iniBaseG.ini', 'r')
else:
	ini_base_file = open('iniBase.ini', 'r')
size_map = {}

# Writing configs and new lines
write_configs(new_ini_file, ini_base_file)
new_ini_file.write('\n\n#Generate Traffic through SendScript.py\n')

print("Enter the number of Spines: ")
NUM_SPINES = int(input())

print("Enter the number of leaves: ")
NUM_LEAFS = int(input())

NUM_HOSTS = 0
NUM_HOSTS_PER_LEAF = []
for i in range(NUM_LEAFS):
    print("Enter the number of hosts per leaf " + str(i + 1) + ": ")
    HOST_PER_LEAF = int(input())
    NUM_HOSTS = NUM_HOSTS + HOST_PER_LEAF
    NUM_HOSTS_PER_LEAF.append(HOST_PER_LEAF)

NUM_APPLICATIONS = math.ceil(NUM_HOSTS * APPLICATION_PERCENTAGE) if NUM_HOSTS * APPLICATION_PERCENTAGE < 7 else 7
write_applications(new_ini_file, NUM_APPLICATIONS)

app_list = []

# Iteration from 0 : NUM_LEAVES
for i in range(NUM_LEAFS):

    # Iterating from 0 : HOSTS_PER_LEAF of LEAF
    for j in range(NUM_HOSTS_PER_LEAF[i]):

        rand_num = int(random.random() * INTER_INTRA_PERCENTAGE)

        if rand_num == 0 and NUM_HOSTS_PER_LEAF[i] > 1:
            # Iterating from 1 : NUM_APPLICATIONS on host
            for k in range(1, NUM_APPLICATIONS):

                rand_host = int(random.random() * NUM_HOSTS_PER_LEAF[i])
                while rand_host == j:
                    rand_host = int(random.random() * NUM_HOSTS_PER_LEAF[i])

                current_app = "**.leaf[" + str(i) + "].H[" + str(j) + "].app[" + str(k) + "]"
                connect_address = "leaf[" + str(i) + "].H[" + str(rand_host) + "]"
                write_connect_address(new_ini_file, current_app, connect_address)
                app_list.append(current_app)

        else:
            for k in range(1, NUM_APPLICATIONS):
                rand_leaf = int(random.random() * NUM_LEAFS)
                while rand_leaf == i:
                    rand_leaf = int(random.random() * NUM_LEAFS)

                rand_host = int(random.random() * NUM_HOSTS_PER_LEAF[rand_leaf])
                current_app = "**.leaf[" + str(i) + "].H[" + str(j) + "].app[" + str(k) + "]"
                connect_address = "leaf[" + str(rand_leaf) + "].H[" + str(rand_host) + "]"
                write_connect_address(new_ini_file, current_app, connect_address)
                app_list.append(current_app)

new_ini_file.write("\n")

for app in app_list:
    send_script_string = ""
    for second in range(1, MAX_SECONDS):
        on_off = int(random.random() * ON_OFF_PERCENTAGE)
        if on_off == 0:
            rand_flow = int(random.random() * MICE_ELEPHANT_PERCENTAGE)

            # Mice Flow
            if rand_flow == 0:
                # Focusing more data on MICE_MIN 60% chance
                rand_mice_min = int(random.random() * 100)
                temp_max = MICE_MAX

                if rand_mice_min <= 80:
                    temp_max = MICE_MIN + (MICE_MAX - MICE_MIN) * 0.03
                else:
                    temp_max = MICE_MIN + (MICE_MAX - MICE_MIN) * random.random()

                rand_size = int((random.random() * (temp_max - MICE_MIN)) + MICE_MIN)
                send_script_string = send_script_string + " " + str(second) + " " + str(rand_size) + ";"
                writeToMap(size_map, rand_size)

            # Elephant Flow
            else:
                rand_ele_distro = int(random.random() * 100)
                temp_min = ELEPHANT_MIN

                if rand_ele_distro <= 40:
                    temp_min = ELEPHANT_MIN + int((ELEPHANT_MAX - ELEPHANT_MIN) * (random.random()))
                elif 60 < rand_ele_distro < 100:
                    temp_min = ELEPHANT_MIN + int((ELEPHANT_MAX - ELEPHANT_MIN) * 0.96)

                rand_size = int((random.random() * (ELEPHANT_MAX - temp_min)) + temp_min)
                send_script_string = send_script_string + " " + str(second) + " " + str(rand_size) + ";"
                writeToMap(size_map, rand_size)

    write_send_script(new_ini_file, send_script_string.strip(), app)

# Writing frequency data to file
size_file = open('size_freq.txt', 'w')
size_file.write("Size(Bytes),Frequency\n")

for key in size_map:
    size_file.write(str(key) + "," + str(size_map[key]) + "\n")
