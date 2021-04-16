import pandas as panda
import plotly.express as px

results = panda.read_csv('./lat files/333_1.csv')


# Creating new data frame
spines = results[['bits/sec rcvd']].dropna()
spines = spines[(spines != 0).all(1)]
print(spines)

fig = px.box(spines, y="bits/sec rcvd")
fig.write_html('throughput.html', auto_open=True)





