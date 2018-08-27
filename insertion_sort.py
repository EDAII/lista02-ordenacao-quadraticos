# import random
def insertion_sort(vector):
    for i in range(len(vector)):
        key = vector[i]
        j = i - 1
        while j >= 0 and key < vector[j]:
            vector[j + 1] = vector[j]
            j -= 1
        vector[j + 1] = key

# lista = list()

# for i in range(10):
#     lista.append(random.randint(0,1000))
#     print(lista[i])

# print('-----')

# insertion_sort(lista)
# for i in range(len(lista)):
#     print(lista[i])
