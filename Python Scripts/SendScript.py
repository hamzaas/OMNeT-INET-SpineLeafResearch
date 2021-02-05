def write_configs(new_ini, ini_base):
    new_ini.write(ini_base.read())


def write_traffic_per_host(leaf_num, host_num, app_num, connect_leaf,
                           connect_host, traffic_string, new_ini):
    # Generating connect String
    connect_string = '**.leaf[' + str(leaf_num) + '].H[' + str(host_num) + \
                     '].app[' + str(app_num) + ']'
    # Writing connect address
    new_ini.write('\n\n' + connect_string + '.connectAddress = ' + '"leaf[' + str(connect_leaf)
                  + '].H[' + str(connect_host) + ']"\n')
    # Writing traffic to sendScript param
    new_ini.write(connect_string + '.sendScript = "' + traffic_string + '"')


def write_traffic_per_border(app_num, connect_leaf, connect_host, traffic_string, new_ini):
    new_ini.write('\n\n**.border.app[' + str(app_num) + '].connectAddress =' +
                  ' "leaf[' + str(connect_leaf) + '].H[' + str(connect_host) + ']"')
    new_ini.write('\n\n**.border.app[' + str(app_num) + '].sendScript = "' +
                  traffic_string + '"')


def read_simulation_data(input_file_name):
    input_file = open('input_file', 'r')
    lines = input_file.readlines()
    leaf_map = dict()

    #Format of input file
    #Leaf number -> number of hosts
    #To generate all pairs interate over map Keys
    #in nested for loop (leaf num -1 = border)

    for line in lines:
        line = line.split(" ")
        leaf_map.put[int(line[0])] = int(line[1])


# Main Calls

new_ini_file = open('ini_generated.ini', 'w')
ini_base_file = open('iniBase.ini', 'r')

# Writing configs and new lines
write_configs(new_ini_file, ini_base_file)
new_ini_file.write('\n\n#Generate Traffic through SendScript.py')

write_traffic_per_host(1, 2, 3, 4, 5, "5 3; 4 5;", new_ini_file)
