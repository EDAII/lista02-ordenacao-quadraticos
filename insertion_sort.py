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
random.shuffle(vector) #embaralha os vetores


before = time.time()
insertion_sort(vector)
after = time.time()

total  = (after-before)*1000

print("Tempo de ordenação para vetor de 100 elementos: %0.2f" %total)


vector2 = list(range(0,1000))
random.shuffle(vector2)

before2 = time.time()
insertion_sort(vector2)
after2 = time.time()

total2 = (after2-before2)*1000


print("Tempo de ordenação para vetor de 1000 elementos: %0.2f" %total2)