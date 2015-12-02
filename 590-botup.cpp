#include <iostream>
#include <limits.h>

using namespace std;

// n: number of cities that the escape will take her
// k: number of flights she has to take
int k, n, tc, g[11][11][10], dp[20][1002];

int get(int from, int to, int day) {
  return (g[from][to][0]) ? g[from][to][day%(g[from][to][0])+1] : 0;
}

int main() {
  while (cin >> n >> k and k and n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j == i) continue;
        cin >> g[i][j][0];
        for (int f = 1; f <= g[i][j][0]; f++) cin >> g[i][j][f];
      }
    }

    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= k; j++) dp[i][j] = INT_MAX;

    dp[0][0] = 0;

    for (int day = 1; day <= k; day++)
      for (int cur = 0; cur < n; cur++)
        for (int to = 0; to < n; to++)
          if (cur != to and get(cur, to, day-1) and dp[cur][day-1] != INT_MAX) {
            dp[to][day] = min(dp[to][day], dp[cur][day-1] + get(cur, to, day-1));
          }

    cout << "Scenario #" << ++tc << endl;
    if (dp[n-1][k] < INT_MAX) cout << "The best flight costs " << dp[n-1][k] << "." << endl;
    else cout << "No flight possible." << endl;
    cout << endl;
  }
  return 0;
}
