#include <iostream>
#define ll unsigned long long
#define inf 999999

using namespace std;

int coins[101], n, dp[20001];

int main() {
  int tc, target; cin >> tc;
  while (tc--) {
    cin >> target >> n;
    int max = 20000;
    for (int i = 0; i < n; i++) cin >> coins[i];
    for (int i = 1; i <= max; i++) dp[i] = inf;
    dp[0] = 0;

    for (int c = 0; c < n; c++) {
      for (int i = max - coins[c]; i >= 0; i--) {
        if (dp[i] != inf) {
          dp[i+coins[c]] = min(dp[i+coins[c]], 1+dp[i]);
        }
      }
    }

    for (int i = target; i <= max; i++)
      if (dp[i] != inf) {
        cout << i << ' ' << dp[i] << endl;
        break;
      }
  }
  return 0;
}
