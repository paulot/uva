#include <iostream>

using namespace std;

int num[] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};

int main() {
  char c;
  while (cin.get(c)) {
    if (c >= 'A' and c <= 'Z') cout << num[c-'A'];
    else cout << c;
  }

  return 0;
}


