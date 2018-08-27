from random import randint

import bubble_sort
import selection_sort
import shell_sort

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


