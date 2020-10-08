#include <iostream>

using namespace std;


struct node {
  int item;
  node *left, *right;

  node() : left(NULL), right(NULL) {}
  node(int it) : left(NULL), right(NULL), item(it) {}
};

void insert(node *root, int item) {
  if (root->item < item and root->right == NULL) root->right = new node(item);
  else if (root->item > item and root->left == NULL) root->left = new node(item);
  else if (root->item < item) insert(root->right, item);
  else if (root->item > item) insert(root->left, item);
}

bool isValid(node *root) {
  if (root == NULL) return true;

  bool valid = true;

  if (root->left != NULL) {
    if (root->item > root->left->item) valid &= isValid(root->left);
    else return false;
  }

  if (root->right != NULL) {
    if (root->item < root->right->item) valid &= isValid(root->right);
    else return false;
  }
  return valid;
}

void del(node *root) {
  if (root->left == NULL and root->right == NULL) { delete root; return; }

  if (root->left != NULL) del(root->left);
  if (root->right != NULL) del(root->right);
  delete root;
}

void print(node *root) {
  if (root->left != NULL) print(root->left);
  cout << root->item << endl;
  if (root->right != NULL) print(root->right);
}

int main() {
  node *root = new node(50);

  for (int i = 0; i < 100; i++) insert(root, i);
  print(root);
  cout << endl << endl;
  cout << isValid(root) << endl;
  root->left->right->right->right->item = 60;
  cout << isValid(root) << endl;

  del(root);

  return 0;

}

  

