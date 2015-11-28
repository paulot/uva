#include <iostream>
#define cost(d) ((w*d)+(2*w*d))

using namespace std;

int dp[100000][31], n, cap, w, depths[31], value[31], print[31];

int main() {
  bool first = true;
  while (cin >> cap >> w >> n) {
    if (not first) cout << endl;
    first = false;
    for (int i = 1; i <= n; i++) cin >> depths[i] >> value[i];
    for (int i = 0; i <= cap; i++) dp[i][9] = 0;

    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= cap; j++)
        if (cost(depths[i]) <= j)
          dp[j][i] = max(dp[j][i-1], dp[j-cost(depths[i])][i-1] + value[i]);
        else
          dp[j][i] = dp[j][i-1];

    cout << dp[cap][n] << endl;

    int size = 0, i = n, j = cap;

    while (i > 0) {
      if (dp[j][i] > dp[j][i-1]) {
        j -= cost(depths[i]);
        print[size++] = i--;
      } else {
        i--;
      }
    }
    cout << size << endl;
    while (size--) cout << depths[print[size]] << ' ' << value[print[size]] << endl;
  }
  return 0;
}
