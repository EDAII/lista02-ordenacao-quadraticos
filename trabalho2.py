import plotly
import plotly.graph_objs as go
from random import randint

from bubble_sort import bubble_sort
from selection_sort import selection_sort
from shell_sort import shell_sort
from gap_insertion_sort import gap_insertion_sort

print('creating vectors...')

l1 = list()
l2 = list()
l3 = list()

for i in range(1000):
    l1.append(randint(0, 100000))
for i in range(10000):
    l2.append(randint(0, 100000))
for i in range(100000):
    l3.append(randint(0, 100000))

print('vectors created!')



# plotly.offline.plot({
#     "data": [go.Scatter(x=[1, 2, 3, 4], y=[4, 3, 2, 1])],
#     "layout": go.Layout(title="hello world")
# }, auto_open=True)
