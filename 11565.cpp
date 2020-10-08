#include <iostream>

using namespace std;

int t, a, b, c;

int main() {
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    bool found = false;

    for (int x = -100; x <= 100 and not found; x++) {
      for (int y = x; y <= 100 and not found; y++) {
        int z = a - x - y;
        if (x + y + z == a and x * y * z == b and (x * x) + (y * y) + (z * z) == c and x != y and x != z and y != z) {
          cout << x << ' ' << y << ' ' << z << endl;
          found = true;
        }
      }
    }
    if (not found) cout << "No solution." << endl;
  }
  return 0;
}
