#include <iostream>

using namespace std;

int n, m, g[27][2];
long long dp[27][32];
bool win[27];

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) {
      char pos, zero, one, can_win;
      cin >> pos >> zero >> one >> can_win;
      win[i] = false;
      g[i][0] = zero-'A', g[i][1] = one-'A', win[i] = can_win == 'x';
    }
    cin >> m;

    for (int i = 0; i <= m; i++) for (int j = 0; j < n; j++) dp[j][i] = 0;

    dp[0][0] = 1;
    for (int move = 0; move < m; move++)
      for (int pos = 0; pos < n; pos++) {
        dp[g[pos][0]][move+1] += dp[pos][move];
        dp[g[pos][1]][move+1] += dp[pos][move];
      }

    int sum = 0;
    for (int pos = 0; pos < n; pos++)
      if (win[pos]) sum += dp[pos][m];

    cout << sum << endl;
  }
  return 0;
}
