#include <iostream>

using namespace std;

int deg = 9, total = 1080, a, b, c, d;

int main() {
  while (cin >> a >> b >> c >> d and not (a == 0 and b == 0 and c == 0 and d == 0)) {
    total += ((a >= b) ? a - b : 40 - b + a) * deg;
    total += ((b <= c) ? c - b : 40 - b + c) * deg;
    total += ((c >= d) ? c - d : 40 - d + c) * deg;
    cout << total << endl;
    total = 1080;
  }

  return 0;
}
