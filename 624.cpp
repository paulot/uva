#include <iostream>
#include <cstring>
#define get(p, i) ((p << i) % 2)

using namespace std;

int n, m, songs[21], bs;
bool picked[21], best[21];

void solve(int i, int s) {
  if (s <= n and n - s < n - bs) {
    bs = s;
    memcpy(best, picked, sizeof(picked));
  }
  if (s > n or i >= m) return;
  picked[i] = true;
  solve(i + 1, s + songs[i]);
  picked[i] = false;
  solve(i + 1, s);
}

int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < m; i++) cin >> songs[i];
    bs = 0;
    memset(best, 0, sizeof(best));
    solve(0, 0);
    for (int i = 0; i < 21; i++) if (best[i]) cout << songs[i] << ' ';
    cout << "sum:" << bs << endl;
  }
  return 0;
}
