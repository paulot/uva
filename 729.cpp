#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int tc; cin >> tc;
  while (tc--) {
    int n, h; cin >> n >> h;
    vector<bool> bits;
    for (int i = 0; i < n-h; i++) bits.push_back(0);
    for (int i = 0; i < h; i++) bits.push_back(1);
    do {
      for (int i = 0; i < n; i++) cout << bits[i];
      cout << endl;
    } while (next_permutation(bits.begin(), bits.end()));
    if (tc) cout << endl;
  }
  return 0;
}
