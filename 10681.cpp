#include <iostream>

using namespace std;

int s, e, d, n, m;
bool dp[102][202], g[102][102];

// Still getting WA, but the recurrence is correct, probably some small bug

int main() {
  while (cin >> m >> n and m and n) {
    for (int i = 0; i <= m; i++) for (int j = 0; j <= m; j++) g[i][j] = false;
    for (int i = 1; i <= n; i++) {
      int a, b; cin >> a >> b;
      g[a][b] = g[b][a] = true;
    }
    cin >> s >> e >> d;

    for (int i = 0; i <= m; i++) for (int j = 0; j <= d; j++) dp[i][j] = false;

    dp[s][0] = true;
    for (int day = 0; day < d; day++)
      for (int to = 1; to <= m; to++)
        for (int from = 1; from <= m; from++)
          if (g[from][to] and dp[from][day])
            dp[to][day+1] = true;

    if (dp[e][d]) cout << "Yes, Teobaldo can travel." << endl;
    else cout << "No, Teobaldo can not travel." << endl;
  }
  return 0;
}
