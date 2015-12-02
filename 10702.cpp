#include <iostream>
#include <cstring>

using namespace std;

int c, s, e, t, g[101][101], en[101];
long long dp[1001][101];

int main() {
  while (cin >> c >> s >> e >> t and c and s and e and t) {
    for (int i = 1; i <= c; i++) for (int j = 1; j <= c; j++) cin >> g[i][j];
    for (int i = 1; i <= e; i++) cin >> en[i];

    memset(dp, -1, sizeof dp);
    dp[0][s] = 0;

    for (int trip = 1; trip <= t; trip++)
      for (int to = 1; to <= c; to++)
        for (int from = 1; from <= c; from++)
          if (dp[trip-1][from] != -1)
            dp[trip][to] = max(dp[trip][to], dp[trip-1][from] + g[from][to]);

    long long m = 0;
    for (int i = 1; i <= e; i++) m = max(m, dp[t][en[i]]);
    cout << m << endl;
  }
  return 0;
}
