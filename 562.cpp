#include <iostream>
#include <cmath>

using namespace std;

int dp[50001][100], coins[100], n, tc;

int main() {
  cin >> tc;
  while (tc--) {
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) cin >> coins[i], sum += coins[i];

    int target = sum/2;
    for (int amount = 0; amount <= target; amount++)
      dp[amount][0] = 0;

    for (int coin = 1; coin <= n; coin++)
      for (int amount = 0; amount <= target; amount++)
        if (coins[coin] <= amount)
          dp[amount][coin] = max(dp[amount][coin-1], coins[coin] + dp[amount-coins[coin]][coin-1]);
        else
          dp[amount][coin] = dp[amount][coin-1];
    
    cout << sum - 2*dp[target][n] << endl;
  }
  return 0;
}


