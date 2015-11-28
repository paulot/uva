#include <iostream>
#include <iomanip>
#include <limits.h>

using namespace std;

/*
 * The idea behing the bottom up solution is the same as
 * the top down one. For all endpoints we want to see the time
 * it would take to go from checkpoint j to checkpoint i, given
 * that we stopped at checkpoint j.
 *
 * Hence, for all endpoints, we want to try all start points and see
 * if the time it takes to reach the endpoint from my start point is
 * smaller than the time that it currently takes to reach my endpoint.
 */

int n, arr[101], r;
double b, f, e, v, dp[101];

double get_time(int lc, int nc) {
  double sum = 0;
  for (int x = 0; x < arr[nc] - arr[lc]; x++) {
    if (x >= r) sum += 1.0/(v-e*(x-r));
    else sum += 1.0/(v-f*(r-x));
  }
  return (lc) ? sum + b : sum;
}

int main() {
  while (cin >> n and n) {
    for (int i = 1; i <= n; i++) cin >> arr[i];
    cin >> b >> r >> v >> e >> f;

    for (int i = 1; i <= n; i++) {
      dp[i] = INT_MAX;
      for (int j = 0; j < i; j++)
        dp[i] = min(dp[i], dp[j] + get_time(j, i));
    }

    cout << fixed << setprecision(4) << dp[n] << endl;
  }
  return 0;
}
