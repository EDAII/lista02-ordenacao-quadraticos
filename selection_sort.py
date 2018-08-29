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

print("Tempo total para ordenar vetor ja ordenado (100 elementos): %0.2f ms" %total)

random.shuffle(vector) #embaralha os vetores
random.shuffle(vector) #embaralha os vetores
before_shuffle = time.time()
selection_sort(vector)
after_shuffle = time.time()
total_shuffle = (after_shuffle-before_shuffle)*1000

print("Tempo ordenação para vetor desordenado (100 elementos): %0.2f" %total_shuffle)

vector2 = list(range(0,1000))

before2 = time.time()
selection_sort(vector2)
after2 = time.time()
total2 = (after2-before2)*1000

print("Tempo de ordenação para vetor ja ordenado (1000 elementos): %0.2f" %total2)

random.shuffle(vector2)
before_shuffle2 = time.time()
selection_sort(vector2)
after_shuffle2 = time.time()
total_shuffle2 = (after_shuffle2-before_shuffle2)*1000

print("Tempo de ordenação para vetor desordenado (1000 elementos): %0.2f" %total_shuffle2)

