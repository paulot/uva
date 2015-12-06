#include <iostream>
#include <cstring>
#include <limits.h>

using namespace std;

/**
 * The idea of this algorithm is to minimize the possible price to reach
 * the destination, under the constraint that the time to reach the destination
 * is smaller than t. 
 *
 * To solve it, we run a dfs with dp to speed-up
 */

typedef pair<int, int> ii;

int times[51][51], toll[51][51], n, t, dptime[51][1001], dpprice[51][1001];

ii solve(int ccity, int ctime) {
  if (ccity == n-1) return make_pair(0, 0);
  if (dpprice[ccity][ctime] != -1) return make_pair(dpprice[ccity][ctime], dptime[ccity][ctime]);

  int price = INT_MAX, taken = 0;;
  for (int i = 0; i < n; i++) {
    if (i != ccity and ctime + times[ccity][i] <= t) {
      ii sol = solve(i, ctime + times[ccity][i]);
      if (sol.first != INT_MAX and sol.first + toll[ccity][i] < price) {
        price = toll[ccity][i] + sol.first, taken = times[ccity][i] + sol.second;
      }
    }
  }
  return make_pair(dpprice[ccity][ctime] = price, dptime[ccity][ctime] = taken);
}

int main() {
  while (cin >> n >> t and n and t) {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> times[i][j];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> toll[i][j];

    memset(dptime, -1, sizeof dptime);
    memset(dpprice, -1, sizeof dpprice);

    // Minimize price, then time
    ii sol = solve(0, 0);
    cout << sol.first << ' ' << sol.second << endl;
  }
}
