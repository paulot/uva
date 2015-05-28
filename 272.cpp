#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int c;
  bool in = false;
  while ((c = getchar()) != EOF) {
    if (c == '"') {
      if (in) cout << "\'\'";
      else cout << "``";
      in = !in;
    } else cout << (char) c;
  }

  return 0;
}

