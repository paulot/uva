#include <iostream>
#include <vector>
#include <limits.h>
#define ll unsigned long long

using namespace std;


int books[501], m, k, t;
vector<int> printarr[501];

bool can_solve(int n) {
  ll filled = 0, cur = 0;
  for (int i = 0; i < m; i++) {
    if (books[i] + cur < n) cur += books[i];
    else if (books[i] > n) return false;
    else { cur = books[i]; filled++; }
  }
  return filled < k;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> m >> k;
    for (int i = 0; i < m; i++) cin >> books[i];
    ll low = 0, high = ULONG_MAX;

    while (low < high) {
      ll mid = (low + high) / 2;

      if (can_solve(mid)) high = mid;
      else low = mid + 1;
    }

    for(int i = 0; i < k; i++) printarr[i].clear();

    int cur = 0, filled = 0;
    for (int i = m - 1; i >= 0; i--) {
      if (books[i] + cur <= low and i + 1 >= k - filled) { cur += books[i]; printarr[filled].push_back(books[i]); }
      else { cur = books[i]; filled++; printarr[filled].push_back(books[i]); }
    }

    for (int i = k - 1; i >= 0; i--) {
      for (int j = printarr[i].size() - 1; j >= 0; j--) {
        cout << printarr[i][j];
        if (j != 0) cout << ' ';
      }
      if (i != 0) cout << " / ";
    }
    cout << endl;

  }
  return 0;
}
