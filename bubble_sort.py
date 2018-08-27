from random import randint

def bubble_sort(array):
    limit = len(array)
    for i in range(limit):
        for j in range(0, limit-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]

vector = list()

print('generating vectors')

for i in range(10):
    vector.append(randint(0,10000))

for el in vector:
    print(el)

print('----------------------')

bubble_sort(vector)

for el in vector:
    print(el)
