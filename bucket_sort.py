import random
from insertion_sort import insertion_sort

# FIXME
def bucket_sort(array):
    largest = max(array)
    length = len(array)
    size = int(largest/length)

    buckets = [[] for _ in range(length)]

    for i in range(length):
        j = int(array[i]/size)
        if j != length:
            buckets[j].append(array[i])
        else:
            buckets[length - 1].append(array[i])

    for i in range(length):
        insertion_sort(buckets[i])

    result = []
    for i in range(length):
        result = result + buckets[i]
    return result

lista = list()

for i in range(10):
    lista.append(random.randint(0,1000))
    print(lista[i])

print('-----')

bucket_sort(lista)
for i in range(len(lista)):
    print(lista[i])
