#include <iostream>

using namespace std;

#ifndef NOT_FOUND
#define NOT_FOUND -1
#endif

int sequential_srch(int* vector, int target, int size) {
  for (int i = 0; i < size; i++) {
    if (vector[i] == target) {
      return i;
    }
  }
  return NOT_FOUND;
}

int* cpy_array_to_sentinel(int* vector, int size) {
  int* new_array = new int[size + 1];
  for (int i = 0; i < size; i++) {
    new_array[i] = vector[i];
  }
  return new_array;
}

int sentinel_seq_srch(int* vector, int target, int size) {
  int array_size = size;

  int* new_array = cpy_array_to_sentinel(vector, array_size);

  new_array[array_size] = target;

  int i = 0;
  while (new_array[i] != target) {
    i++;
  }

  if (i == array_size) {
    return NOT_FOUND;
  }
  return i;
}

int tab_search(int* vctor, int target, int size) {
  int *tab_index = new int[10];
  int step = size / 10;

  for (size_t i = 0; i < 10; i++) {
    tab_index[i] = vctor[i * step];
  }

  int init = 0;
  int fin = 0;

  for (size_t i = 0; i < 10; i++) {
    if (tab_index[i] == target) {
      return i;
    }
    else if (tab_index[i] > target) {
      init = i - 1;
      fin = i;
      break;
    }
    else
      init = i;
      fin = size;
  }

  if (init == -1) {
    return NOT_FOUND;
  }

  for (int i = init; i < fin; i++) {
    if (vctor[i] == target) {
      return i;
    }
  }
  return NOT_FOUND;
}

int binary_srch(int* array, int target, int size) {
  int sup = size - 1, inf = 0, guess = 0;

  do {
    guess = (sup + inf) / 2;
    if (array[guess] > target) {
      sup = guess - 1;
      guess = (inf + sup) / 2;
    }
    else if (array[guess] == target) {
      return guess;
    }
    else {
      inf = guess;
      guess = (inf + sup) / 2;
    }
  } while(target != guess && sup <= inf);

  return NOT_FOUND;
}

int binary_tree_search(/* arguments */) {
  /* code */
  return 0;
}

int menu () {
  int number = 0;
  do {
    std::cout << "Digite um número entre 1 e 10.000 para começar a aplicação" << '\n';
    std::cin >> number;
  } while (!(number > 0 && number <= 10000));
  return number;
}

int* generate_vctr(int size) {
  int* list = new int[size];
  for (int i = 0; i < size; i++) {
    list[i] = i + 1;
  }
  return list;
}

int main(int argc, char const *argv[]) {
  int option = menu ();

  std::cout << "gerando vetores" << '\n';
  int *v1 = generate_vctr(100);
  int *v2 = generate_vctr(1000);
  int *v3 = generate_vctr(10000);
  std::cout << "vetores gerados" << '\n';



  return 0;
}
