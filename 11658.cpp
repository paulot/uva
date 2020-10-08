#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

int m, n, x, holder, shares[101], dp[101][10001];
double in;

int solve(int i, int amount) {
  if (amount > 5000) return amount;
  if (i == m) return 99999999;
  if (dp[i][amount] != -1) return dp[i][amount];
  return dp[i][amount] = min(solve(i + 1, amount + shares[i]), solve(i + 1, amount));
}

int main () {
  while (cin >> n >> x and n and x) {
    m = 0;
    for (int i = 1; i <= n; i++) {
      if (i == x) { cin >> in; holder = round(in * 100); }
      else { cin >> in; shares[m++] = round(in * 100); }
    }
    memset(dp, -1, sizeof(dp));
    cout << fixed << setprecision(2) << round((((double) holder) / solve(0, holder)) * 10000) / 100 << endl;
  }
  return 0;
}
