#include <iostream>

using namespace std;

int n, in, p;

int main() {
  while (cin >> n and n) {
    p = 0;
    for (int i = 0; i < n; i++) {
      cin >> in;
      if (in) {
        if (p) cout << ' ';
        cout << in;
        p++;
      }
    }
    if (p) cout << endl;
    else cout << 0 << endl;
  }
  return 0;
}
