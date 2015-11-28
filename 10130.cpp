#include <iostream>

using namespace std;

int dp[1001][31], family[31], weights[1001], prices[1001], no, np, tc;

int main() {
  cin >> tc;
  while (tc--) {
    cin >> no;
    for (int i = 1; i <= no; i++) cin >> prices[i] >> weights[i];
    cin >> np;
    for (int i = 0; i < np; i++) cin >> family[i];
    for (int i = 0; i <= no; i++) for (int j = 0; j <= 30; j++) dp[i][j] = 0;

    for (int i = 1; i <= no; i++)
      for (int j = 1; j <= 30; j++)
        if (j >= weights[i])
          dp[i][j] = max(dp[i-1][j-weights[i]] + prices[i], dp[i-1][j]);
        else dp[i][j] = dp[i-1][j];

    long long total = 0;
    for (int i = 0; i < np; i++) total += dp[no][family[i]];
    cout << total << endl;
  }
  return 0;
}
