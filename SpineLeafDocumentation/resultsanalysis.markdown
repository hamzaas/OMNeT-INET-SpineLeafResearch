---
layout: default
title: Results Analysis
parent: Python Scripts
grand_parent: Code
nav_order: 4
---

# ResultsAnalysis.py

***

- `ResultsAnalysis.py`: This script takes the `results.csv` as input and produces a bar graph that
shows the traffic distribution across each spine. The purpose of this graph is to show that our Simulation
evenly distributes traffic across the spines, creating a balanced load.

- The script utilizes the Python packages `pandas` and `plotly.express` to accomplish two tasks.

1. `pandas` is used to create a data frame from the `results.csv` file that isolates the
`module`, `name`, and `value` fields and drops empty rows. Next regex is used to isolate
modules that match `XHost_SpineLeaf_Network.spine[*].eth[*].mac` patterns. Finally, the
`bits / sec rcvd` name field is isolated.

2. `plotly.express` is used to generate a bar graph of this cleaned data frame.

***

An example of a generated graph can be seen blow.

![](images\g1.png)

***

The code that does this can be seen below.

```python
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
fig.write_html('router_distribution.html', auto_open=True)
```
