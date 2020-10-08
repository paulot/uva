#include <iostream>
#define get(p, i) ((p >> i) % 2)

using namespace std;

int t, n, size, bars[21];

bool possible(int p) {
  int total = 0;
  for (int i = 0; i < n; i++) total += get(p, i) * bars[i];
  return total == size;
}

int main() {
  for (cin >> t; t--;) {
    cin >> size >> n;
    for (int i = 0; i < n; i++) cin >> bars[i];
    bool valid = false;
    for (int i = 0; i < 1 << n and not valid; i++)
      valid |= possible(i);
    cout << ((valid) ? "YES" : "NO") << endl;
  }
  return 0;
}
