#include <iostream>
using namespace std;

int vector_size(int* vector) {
  int a = (sizeof(vector) / sizeof(*vector));
  return a;
}

int sequential_srch(int* vector, int target) {
  for (int i = 0; i < 10; i++) {
    if (vector[i] == target) {
      return i;
    }
  }
  // mission failed
  return -1;
}

int* cpy_array_to_sentinel(int* vector, int array_size) {
  int* new_array = new int[array_size + 1];
  for (int i = 0; i < 10; i++) {
    new_array[i] = vector[i];
  }
  return new_array;
}

int sentinel_seq_srch(int* vector, int target) {
  int array_size = 10;

  int* new_array = cpy_array_to_sentinel(vector, array_size);

  new_array[array_size] = target;

  int i = 0;
  while (new_array[i] != target) {
    i++;
  }

  if (i == array_size) {
    // mission failed
    return -1;
  }
  return i;
}



int main(int argc, char const *argv[]) {
  int vector[] = {0,1,2,3,4,5,6,7,8,9};
  cout << 10 << endl;
  cout << sequential_srch(vector, 2) << endl;
  cout << sentinel_seq_srch(vector, 2) << endl;

  return 0;
}
