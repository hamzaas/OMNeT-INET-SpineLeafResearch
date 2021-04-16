import pandas as panda

# Getting filename of current run
fileName = input()

# Getting data frames
tempFile = panda.read_csv(fileName)
mainFile = panda.DataFrame()

try:
    mainFile = panda.read_csv('mainCSV.csv')
except:
    mainFile = panda.DataFrame()
    print('Empty DF, creating new')

# isolating bits/sec revd
tempFile = tempFile[['name', 'value']].dropna()
tempFile = tempFile[tempFile['name'] == 'bits/sec rcvd']
tempFile = tempFile[tempFile['value'] != 0]
tempFile = tempFile.drop(columns=['name'])
tempFile = tempFile.rename(columns={'value': 'bits/sec rcvd'})
tempFile['Run'] = fileName


# Appending to main file
mainFile = mainFile.append(tempFile, ignore_index=True)

# Converting dataframe to csv file
mainFile.to_csv('mainCSV.csv', index=False, header=True)

print(mainFile)



