import pandas as panda
import sys

# Getting filename of current run
fileName = sys.argv[1]
print(fileName)

# Getting data frames
tempFile = panda.read_csv(fileName)
tempFile2 = panda.read_csv(fileName)
mainFile = panda.DataFrame()
mainFile2 = panda.DataFrame()

try:
    mainFile = panda.read_csv('mainCSV.csv')
    mainFile2 = panda.DataFrame('mainCSV2.csv')
except:
    mainFile = panda.DataFrame()
    mainFile2 = panda.DataFrame()
    print('Empty DF, creating new')

# isolating bits/sec revd
tempFile = tempFile[['name', 'value']].dropna()
tempFile = tempFile[tempFile['name'] == 'bits/sec rcvd']
tempFile = tempFile[tempFile['value'] != 0]
tempFile = tempFile.drop(columns=['name'])
tempFile = tempFile.rename(columns={'value': 'bits/sec rcvd'})

tempFile2 = tempFile2[['name', 'value']].dropna()
tempFile2 = tempFile2[tempFile2['name'] == 'bits/sec sent']
tempFile2 = tempFile2[tempFile2['value'] != 0]
tempFile2 = tempFile2.drop(columns=['name'])
tempFile2 = tempFile2.rename(columns={'value': 'bits/sec sent'})

rcvd_sum = 0
sent_sum = 0

for ind in tempFile.index:
    rcvd_sum += tempFile['bits/sec rcvd'][ind]

for ind in tempFile2.index:
    sent_sum += tempFile2['bits/sec sent'][ind]

print(rcvd_sum / sent_sum)




# # Appending to main file
# mainFile = mainFile.append(tempFile, ignore_index=True)
#
# # Converting dataframe to csv file
# mainFile.to_csv('mainCSV.csv', index=False, header=True)
#
# print(mainFile)



