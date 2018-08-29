import random
import time

def selection_sort(vector):
    # runs through inversed array searching for the greater number
    for fillslot in range(len(vector)-1, 0, -1):
        max_pos = 0
        # finds position of greater number
        for locale in range(1, fillslot + 1):
            if vector[locale] > vector[max_pos]:
                max_pos = locale
        # swaps those modafockars
        vector[fillslot], vector[max_pos] = vector[max_pos], vector[fillslot]

vector = list(range(0,100))

before = time.time()
selection_sort(vector)
after = time.time()

total = (after-before)*1000

print("Tempo total para ordenar vetor com 100 elementos: %0.2f ms" %total)


vector2 = list(range(0,1000))

before1 = time.time()
selection_sort(vector2)
after = time.time()


total2 = (after-before)*1000


print("Tempo total para ordenar vetor com 1000 elementos: %0.2f ms" %total2)

