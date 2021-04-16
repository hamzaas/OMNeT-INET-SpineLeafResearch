import pandas as panda
import plotly.express as px

# Getting results
results = panda.read_csv('mainCSV.csv')

# Graphing box plot results
fig = px.box(results, x='Run', y="bits/sec rcvd")
fig.write_html('throughput.html', auto_open=True)




