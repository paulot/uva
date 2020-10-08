#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


/**
 * The idea is as follows:
 * For each car, we want to figure out what is the lis and the lds starting at that
 * particular location. Once we have that information, we can simply check for the
 * value that maximizes lds + lis.
 */

int t, n, cars[2001], lis[2001], lds[2001];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> cars[i];
    memset(lis, 0, sizeof(lis));
    memset(lds, 0, sizeof(lds));
    lis[n-1] = 1; lds[n-1] = 1;

    for (int i = n - 2; i >= 0; i--) {
      lis[i] = 1;
      for (int j = i + 1; j < n; j++) {
        if (cars[i] < cars[j]) lis[i] = max(lis[i], lis[j] + 1);
      }
    }

    for (int i = n - 2; i >= 0; i--) {
      lds[i] = 1;
      for (int j = i + 1; j < n; j++) {
        if (cars[i] > cars[j]) lds[i] = max(lds[i], lds[j] + 1);
      }
    }

    int best = 0;
    for (int i = 0; i < n; i++) best = max(best, lds[i] + lis[i] - 1);
    cout << best << endl;

  }
  return 0;
}
