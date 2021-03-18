import pandas as panda
import plotly.express as px

results = panda.read_csv('size_freq.txt')

# Creating new data frame
spines = results[['Size(Bytes)', 'Frequency']].dropna()

# Displaying bar graph
fig = px.bar(spines, x='Size(Bytes)', y='Frequency')
fig.write_html('size_graph.html', auto_open=True)
