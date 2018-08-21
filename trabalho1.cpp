#include <iostream>

using namespace std;

#ifndef NOT_FOUND
#define NOT_FOUND -1
#endif

#ifndef null
#define null NULL
#endif

// class Node {
//   public:
//   int value;
//   int fb;
//   Node *left;
//   Node *right;
// };

typedef struct x {
  int value;
  struct x* left;
  struct x* right;
  int fb;
} Node;

int height (Node *root) {
  if (root != null) {
    int hright, hleft;
    hright = height(root->right) + 1;
    hleft = height(root->left) + 1;
    if (hright > hleft) {
      return hright;
    }
    else {
      return hleft;
    }
  }
  return 0;
}

int calc_factor_b(Node *target) {
  return (height(target->left) - height(target->right));
}

Node * rot_left(Node *t) {
  Node *aux;
  aux = t->right;
  t->right = aux->left;
  aux->left = t;
  aux->fb = calc_factor_b(aux);
  t->fb = calc_factor_b(t);
  return aux;
}

Node * rot_right(Node * a) {
  Node * b;
  b = a->left;
  a->left = b->right;
  b->right = a;
  a->fb = calc_factor_b(a);
  b->fb = calc_factor_b(b);
  return b;
}

Node * rot_left_right(Node* root) {
  root->left = rot_left(root->left);
  root = rot_right(root);
  return root;
}

Node * rot_right_left(Node* root) {
  root->right = rot_right(root->right);
  root = rot_left(root);
  return root;
}

Node * new_element(int value) {
  Node * newbie = new Node;

  newbie->value = value;
  newbie->left = newbie->right = NULL;
  newbie->fb = 0;

  return newbie;
}

// TODO
Node * insert(Node * root, int value) {
  if (root == null) {
    root = new_element(value);
    return root;
  }
  else if (value < root->value) {
    root->left = insert(root->left, value);
    root->fb = calc_factor_b(root);
  }
  else if (value > root->value) {
    root->right = insert(root->right, value);
    root->fb = calc_factor_b(root);
  }

  // balancing
  if (root->fb > 1) {
    if (root->left->fb < 0) {
      root = rot_left_right(root);
    }
    else {
      root = rot_right(root);
    }
  }
  if (root->fb < -1) {
    if (root->right->fb > 0) {
      root = rot_right_left(root);
    }
    else {
      root = rot_left(root);
    }
  }
  return root;
}

int srch_avl(Node * root, int target) {
  Node * node;
  node = root;

  while(node != NULL && node->value != target){

    if (target < node->value) {
      node = node->left;
    }

    else if (target > node->value)
    {
      node = node->right;
    }
  }


  if (node != NULL) {
    return node->value;
  }
  // node == NULL
  return -1;
}

//-----------------------------------------------------------

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

// auxiliary funcs

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

Node * generate_avl_tree(Node * tree, int *vector, int size) {
 for(int i = 0; i < size; i++) {
   tree = insert(tree, vector[i]);
 }
 return tree;
}

int main(int argc, char const *argv[]) {
  int option = menu ();

  std::cout << "gerando vetores" << '\n';

  int *v1 = generate_vctr(100);
  int *v2 = generate_vctr(1000);
  int *v3 = generate_vctr(10000);

  std::cout << "vetores gerados" << '\n';

  Node *tree100 = new Node;
  Node *tree1k = new Node;
  Node *tree10k = new Node;

  cout << 'gerando arvores' << endl;

  tree100 = generate_avl_tree(tree100, v1, 100);
  tree1k = generate_avl_tree(tree1k, v2, 1000);
  tree10k = generate_avl_tree(tree10k, v3, 10000);

  cout << 'arvores geradas' << endl;

  return 0;
}
