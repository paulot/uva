#include <iostream>

using namespace std;

int n, t;

int main() {
  cin >> t;
  for (int rr = 1; rr <= t; rr++) {
    cin >> n;
    int in, start = 0, end = 0, best = -99999999, c = 0, bs = 0;
    for (int i = 0; i < n - 1; i++) {
      cin >> in;
      c += in;
      if (c < 0) {
        c = 0;
        start = i + 1;
      }
      if (c > best or (best == c and i - start > end - bs)) {
        best = c;
        bs = start;
        end = i;
      }
    }
    if (best > 0)
      cout << "The nicest part of route " << rr << " is between stops " << bs + 1 << " and " << end + 2 << endl;
    else cout << "Route " << rr << " has no nice parts" << endl;
  }
  return 0;
}
      
