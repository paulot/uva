#include <iostream>
#include <cstring>

using namespace std;

int b, n, mon[21];

int main() {
  while (cin >> b >> n and (b != 0 or n != 0)) {
    memset(mon, 0, sizeof(mon));
    for (int i = 1; i <= b; i++) cin >> mon[i];
    for (int i = 0; i < n; i++) {
      int from, to, v; cin >> from >> to >> v;
      mon[from] -= v; mon[to] += v;
    }
    bool bailed = false;
    for (int i = 1; i <= b; i++) if (mon[i] < 0) { bailed = true; break; }
    cout << ((not bailed) ? 'S' : 'N') << endl;
  }
  return 0;
}
