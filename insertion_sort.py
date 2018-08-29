import random
import time

def insertion_sort(vector):
    for i in range(len(vector)):
        key = vector[i]
        j = i - 1
        while j >= 0 and key < vector[j]:
            vector[j + 1] = vector[j]
            j -= 1
        vector[j + 1] = key


vector = list(range(0,100))


before = time.time()
insertion_sort(vector)
after = time.time()

total  = (after-before)*1000

print("Tempo ordenação para vetor ja ordenado (100 elementos): %0.2f" %total)

#Tempo para vetor desordenado
random.shuffle(vector) #embaralha os vetores
before_shuffle = time.time()
insertion_sort(vector)
after_shuffle = time.time()
total_shuffle = (after_shuffle-before_shuffle)*1000

print("Tempo ordenação para vetor desordenado (100 elementos): %0.2f" %total_shuffle)


vector2 = list(range(0,1000))

before2 = time.time()
insertion_sort(vector2)
after2 = time.time()

total2 = (after2-before2)*1000


print("Tempo de ordenação para vetor ja ordenado (1000 elementos): %0.2f" %total2)

random.shuffle(vector2)
before_shuffle2 = time.time()
insertion_sort(vector2)
after_shuffle2 = time.time()
total_shuffle2 = (after_shuffle2-before_shuffle2)*1000


print("Tempo de ordenação para vetor desordenado (1000 elementos): %0.2f" %total_shuffle2)
