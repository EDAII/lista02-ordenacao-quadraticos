from random import randint

def bubble_sort(array):
    limit = len(array)
    for i in range(limit):
        for j in range(0, limit-i-1):
            if array[j] > array[j+1]:
                array[j], array[j+1] = array[j+1], array[j]
