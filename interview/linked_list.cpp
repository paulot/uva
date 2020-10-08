#include <iostream>

using namespace std;

struct node {
  node *next;
  int item;

  node() : next(NULL) {}
  node(int it) : next(NULL), item(it) {}
};

void insert(node *root, int item) {
  while (root->next != NULL) root = root->next;
  root->next = new node(item);
}

void print(node *root) {
  if (root->next == NULL) { cout << root->item << endl; return; }
  print(root->next);
  cout << root->item << endl;
}

void del(node *root) {
  if (root->next == NULL) { delete root; return; }
  del(root->next);
  delete root;
}


int main() {
  node *bla = new node(1);

  if (bla->next == NULL) cout << "Set to NULL like expected" << endl;

  for (int i = 2; i < 100; i++) insert(bla, i);
  print(bla);
  del(bla);

  return 0;
}
