#include <iostream>

using namespace std;

int main() {
  int n, i = 0;
  cout << "{ ";
  while (cin >> n) {
    if (i == 0) cout << "  ";
    cout << n << ',';
    if (i++ == 10) { i = 0; cout << endl; }
  }
  cout << '}';
}

