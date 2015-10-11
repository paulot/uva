#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#define ll long long

using namespace std;

ll arr[100000], dp[100000], dpi[100000], n = 0;

int main() {
  while (cin >> arr[n++]);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int c  = lower_bound(dp, dp+ans+1, arr[i]) - dp;
    dp[c] = arr[i];
    dpi[i] = c;
    ans = max(c, ans);
  }

  vector<ll> a;
  for (int i = n; i >= 0; i--)
    if (dpi[i] == ans) {
      a.push_back(arr[i]);
      ans--;
    }

  cout << a.size() << endl << '-' << endl;
  reverse(a.begin(), a.end());
  for (int i = 0; i < a.size(); i++)
    cout << a[i] << endl;
}
