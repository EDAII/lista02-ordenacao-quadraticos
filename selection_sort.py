import random

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
