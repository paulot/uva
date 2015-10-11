#include <iostream>

using namespace std;

// ammount, ncoins
int dp[301][301], ammount, ncoins;

int nways(int val, int nc) {
  if (nc == 1) return 1;
  if (val == 0) return 1;

  int ways = 0;
  for (int i = 1; i <= val; i++)
    ways += nways(val-i, nc-1);

  cout << val << ' ' << nc << ' ' << ways << endl;
  return ways;
}

int main() {
  while (cin >> ammount) {
    for (int i = 1; i <= ammount; i++)
    for (int j = 1; j <= ammount; j++)
      dp[i][j] = 0;

    for (int i = 0; i <= ammount; i++) dp[0][i] = 1;

    for (int i = 1; i <= ammount; i++)
      for (int j = 1; j <= i; j++)
        dp[i][j] += dp[

    cout << nways(ammount, 6) << endl;
  }
  return 0;
}


    

