#include <iostream>
#include <cmath>
#define ll long long
#define inf 9999999
#define sq(a) (a*a)

using namespace std;

int dp[301][301], values[41][2], target, ntypes;

int main() {
  int n; cin >> n;
  while (n--) {
    cin >> ntypes >> target;
    for (int i = 0; i < ntypes; i++) {
      cin >> values[i][0] >> values[i][1];
    }
    for (int i = 0; i <= target; i++)
      for (int j = 0; j <= target; j++)
        dp[i][j] = inf;
    dp[0][0] = 0;

    for (int c = 0; c < ntypes; c++)
      for (int i = values[c][0]; i <= target; i++)
        for (int j = values[c][1]; j <= target; j++)
          dp[i][j] = min(dp[i][j], 1 + dp[i-values[c][0]][j-values[c][1]]);

    int m = inf;
    for (int i = 0; i <= target; i++)
      for (int j = 0; j <= target; j++)
        if (sq(i) + sq(j) == sq(target))
          m = min(m, dp[i][j]);

    if (m == inf) cout << "not possible" << endl;
    else cout << m << endl;
  }
  return 0;
}
