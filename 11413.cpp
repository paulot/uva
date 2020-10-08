#include <iostream>
#include <algorithm>

using namespace std;

int n, m, vessels[1001];

bool canFill(int cap) {
  int container = 0, fill = 0;
  for (int i = 0; i < n; i++) {
    if (vessels[i] > cap) return false;

    if (fill + vessels[i] <= cap) {
      fill += vessels[i];
    } else {
      container++; fill = vessels[i];
    }
  }
  if (fill) container++;
  return container <= m;
}

int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) cin >> vessels[i];
    int low = 0, high = 1100000000, mid, ans;
    while (low < high) {
      mid = (low + high) / 2;
      if (canFill(mid)) { ans = mid; high = mid; }
      else low = mid + 1;
    }
    cout << ans << endl;
  }
  return 0;
}
