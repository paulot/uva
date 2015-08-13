#include <iostream>
#include <cmath>

using namespace std;

int d;

int search(int cd, int num, int cnum) {
  if (cd == d) return cnum;
  int div = ceil(num/2.0);
  return (num % 2 == 1) ? search(cd+1, div, cnum*2) : search(cd+1, div, cnum*2+1);
}

int main() {
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> d;
    if (d == -1) return 0;
    cin >> n;
    cout << search(1, n, 1) << endl;
  }
  return 0;
}
