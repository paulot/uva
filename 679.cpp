#include <iostream>
#include <cmath>
#define goLeft(n) (n % 2 == 0)

using namespace std;

int t, depth, in;

int search(int d, int i, int cnum) {
  if (d == depth) return cnum;
  int div = ceil(i/2.0);
  return goLeft(i) ? search(d + 1, div, cnum * 2 + 1) : search(d + 1, div, cnum * 2);
}

int main() {
  cin >> t;
  while (t--) {
    cin >> depth >> in;
    cout << search(1, in, 1) << endl;
  }
  return 0;
}
