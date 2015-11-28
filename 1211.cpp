#include <iostream>
#include <iomanip>
#include <limits.h>

using namespace std;

int n, arr[101], r;
double b, f, e, v, dp[101][101];

double get_time(int lc, int nc) {
  double sum = 0;
  for (int x = 0; x < arr[nc] - arr[lc]; x++) {
    if (x >= r) sum += 1.0/(v-e*(x-r));
    else sum += 1.0/(v-f*(r-x));
  }
  return sum;
}

double solve(int lc, int cc) {
  if (cc >= n) return get_time(lc, cc);
  if (dp[lc][cc] != INT_MAX) return dp[lc][cc];

  // Time that it will took to get to this checkpoint
  double time = get_time(lc, cc);

  // Stop/go at the current checkpoint
  return dp[lc][cc] = min(solve(cc, cc+1) + time + b, solve(lc, cc+1));
}


int main() {
  while (cin >> n and n) {
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> b >> r >> v >> e >> f;

    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++)
        dp[i][j] = INT_MAX;

    cout << fixed << setprecision(4) << solve(0, 0) << endl;
  }
  return 0;
}
