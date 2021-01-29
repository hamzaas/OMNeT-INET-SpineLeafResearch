import pandas as panda
import matplotlib.pyplot as plot
import plotly.express as px

results = panda.read_csv('./Spine-Leaf-ManualDCN/_XHostSpineLeaf/results/results.csv')


# Creating new data frame
spines = results[['module', 'name', 'value']].dropna()

#Filtering out non spines
spines = spines[spines.module.str.match('XHost_SpineLeaf_Network.spine\[.\]\.eth\[.\]\.mac$')]

#Filtering out non bits/sec
spines = spines[spines.name.str.match('bits\/sec rcvd')]

#Displaying bar graph
fig = px.bar(spines, x='module', y='value')
fig.show()


# Matplotlib option (Bad pacing).
# plot.rcParams['figure.figsize'] = [10.0, 4.0]
# plot.rcParams['figure.dpi'] = 144
#
# spines.plot.bar('module', 'value')
# plot.show()
