#include <iostream>

using namespace std;

int tc, len, winds[12][12], dp[12][12];

int main() {
  cin >> tc;
  while (tc--) {
    cin >> len;
    for (int i = 9; i >= 0; i--)
      for (int j = 0; j < len/100; j++)
        cin >> winds[i][j];

    for (int i = 0; i <= 10; i++)
      for (int j = 0; j <= len/100; j++)
        dp[i][j] = 100000;

    for (int j = 1; j <= 10; j++)
      winds[0][j] = -100000;

    dp[0][0] = 0;
    for (int j = 0; j <= len/100; j++)
      for (int i = 0; i < 10; i++) {
        if (i > 0) dp[i-1][j+1] = min(dp[i-1][j+1], dp[i][j] + 20 - winds[i][j]);
        dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j] + 60 - winds[i][j]);
        dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 30 - winds[i][j]);
      }

    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < len/100; j++)
        cout << dp[i][j] << ' ';
      cout << endl;
    } cout << endl;

    cout << dp[0][len/100]<< endl;
    if (tc) cout << endl;
  }
  return 0;
}
