#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int t = 1, n, m, in;

int main() {
  while (cin >> n >> m and n and m) {
    int small = INT_MAX;
    for (int i = 0; i < n; i++) { cin >> in; small = min(in, small); }
    for (int i = 0; i < m; i++) cin >> in;
    if (n - m <= 0) cout << "Case " << t++ << ": 0" << endl;
    else cout << "Case " << t++ << ": " << n - m << ' ' << small << endl;
  }
  return 0;
}
