#include <iostream>
#include <cstring>
#define check(pos, num) (((num) >> (pos-1)) & 1)

using namespace std;

int n, m, fields[21][21], dp[1<<20], visited;

/**
 * The idea is to iterate from cow 0 to cow n and for each cow
 * you want to assign it to a pasture that is not yet visited.
 *
 * We maintain a list of visited pastures as a bitmask, if we come to a
 * state that we have previously seen, we use the previous answer.
 * Else, we iterate over all non-visited pastures of the cow we're looking at
 * and try assigning the cow to the given pasture in a depth first search
 * like fashion.
 */

int solve(int cow) {
  if (cow >= n) return 1;
  if (dp[visited] != -1) return dp[visited];

  int m = 0;
  for (int i = 1; i <= fields[cow][0]; i++) {
    if (not check(fields[cow][i], visited)) {
      visited |= 1 << (fields[cow][i]-1);
      m += solve(cow+1);
      visited &= ~(1 << (fields[cow][i]-1));
    }
  }
  return dp[visited] = m;
}

int main() {
  ios_base::sync_with_stdio(false);
  while (cin >> n >> m) {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
      cin >> fields[i][0];
      for (int j = 1; j <= fields[i][0]; j++) cin >> fields[i][j];
    }
    cout << solve(0) << endl;
  }
  return 0;
}
