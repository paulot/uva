#include <iostream>

using namespace std;

int weight[100000], load[100000], n;
int dp[100000][100000];

int main() {
  while (cin >> n and n != 0) {
    for (int i = 1; i <= n; i++) {
      cin >> weight[i] >> load[i];
      for (int j = weight[i]; j < 100000; j++) dp[i][j] = 1;
    }

    for (int i = 1; i < n; i++)
      for (int j = weight[i]; j < 100000; j++)
        dp[i][j] = max(dp[i+1][j], 1 + dp[i+1][min(load[i], j-weight[i])]);



  }
  return 0;
}
