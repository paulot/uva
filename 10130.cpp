#include <iostream>

using namespace std;

/**
 * The idea behind this solution is to runs a regular 01 knapsack
 * and add all of the best weights to a running total value This total
 * will represent the total that the family can carry.
 */

int t, n, w, m, prices[1001], weights[1001], dp[1001][31];

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> prices[i] >> weights[i];
    cin >> m;

    for (int item = 1; item <= n; item++) {
      for (int weight = 0; weight <= 30; weight++) {
        if (weights[item] > weight) dp[item][weight] = dp[item-1][weight];
        else dp[item][weight] = max(dp[item-1][weight], prices[item] + dp[item-1][weight-weights[item]]);
      }
    }

    long long total = 0;
    for (int k = 0; k < m; k++) {
      cin >> w;
      total += dp[n][w];
    }

    cout << total << endl;
  }
  return 0;
}
