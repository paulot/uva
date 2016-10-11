#include <iostream>
#include <algorithm>

using namespace std;

int t, n, stores[100];

int main() {
  cin >> t;
  for (int p = 0; p < t; p++) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> stores[i];
    int min, max; min = *min_element(stores, stores+n); max = *max_element(stores, stores+n);
    cout << (max - min) * 2 << endl;
  }
  return 0;
}
