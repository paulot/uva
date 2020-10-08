#include <iostream>

using namespace std;

int t, n, rungs[100002];

// Soved in 7m 13s 56ms

bool canJump(int k) {
  for (int i = 1; i <= n; i++) {
    if (rungs[i] - rungs[i - 1] > k) return false;
    else if (rungs[i] - rungs[i - 1] == k) k--;
  }
  return true;
}

int main() {
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> rungs[i];
    int low = 0, high = 10000001, mid;
    while (low < high) {
      mid = (low + high) / 2;
      if (canJump(mid)) high = mid;
      else low = mid + 1;
    }
    cout << "Case " << tt << ": " << high << endl;
  }
  return 0;
}
