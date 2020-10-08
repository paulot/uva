#include <iostream>
#include <cstring>
#define inf 6001

using namespace std;

int n, weights[1001], loads[1001], dp[1001][6003];

int solve(int i, int maxLoad) {
  if (i >= n) return 0;
  if (dp[i][maxLoad] != -1) return dp[i][maxLoad];
  if (maxLoad >= weights[i])
    return dp[i][maxLoad] = max(solve(i + 1, maxLoad), 1 + solve(i + 1, min(maxLoad - weights[i], loads[i])));
  return dp[i][maxLoad] = solve(i + 1, maxLoad);
}

int main() {
  while (cin >> n and n) {
    for (int i = 0; i < n; i++) cin >> weights[i] >> loads[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, inf) << endl;
  }
  return 0;
}
