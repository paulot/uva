#include <iostream>
#include <limits.h>

using namespace std;

int tc, m, n, arr[21][21], dp[201][21];

int solve(int left, int garmet) {
  if (garmet >= n) return 0;
  if (left <= 0) return INT_MIN;
  if (dp[left][garmet] != INT_MIN) return dp[left][garmet];

  int m = INT_MIN;
  for (int i = 1; i <= arr[garmet][0]; i++) {
    if (left >= arr[garmet][i]) {
      int candidate = solve(left - arr[garmet][i], garmet+1);
      if (candidate != INT_MIN)
        m = max(m, arr[garmet][i] + candidate);
    }
  }

  return dp[left][garmet] = m;
}

int main() {
  cin >> tc;
  while (tc--) {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
      cin >> arr[i][0];
      for (int j = 1; j <= arr[i][0]; j++)
        cin >> arr[i][j];
    }

    for (int i = 0; i <= m; i++)
      for (int j = 0; j <= n; j++)
        dp[i][j] = INT_MIN;

    int solution = solve(m, 0);
    if (solution == INT_MIN) cout << "no solution" << endl;
    else cout << solution << endl;
  }
  return 0;
}
