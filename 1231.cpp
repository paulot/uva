#include <iostream>
#include <map>

using namespace std;

/**
 * Basic recurrence, but with tons of things to speed up
 *
 * The idea is to build a table in a bottom up fashion. We let
 * dp[tree][start_height] = max number of acorns we can collect at that
 * height at that tree. We then traverse through all heights starting at the
 * bottom and through all trees. We know that the max number of acorns at
 * tree t and at height h will be the number of acorns at height h on tree t +
 * max((max number of acorns at height h-f), (max number of acorns at height h-1
 * on tree t)).
 */

// dp[tree][start_height] = num acorns
int tc, t, h, f, dp[2002][2002], maxAtHeight[2002];
map<int, int> acorns[2002];

int main() {
  ios_base::sync_with_stdio(false);
  cin >> tc;
  while (tc--) {
    cin >> t >> h >> f;
    for (int i = 1; i <= t; i++) {
      acorns[i].clear(); int s, temp; cin >> s;
      for (int j = 1; j <= s; j++) {
        cin >> temp;
        acorns[i][temp]++;
      }
    }

    for (int height = 0; height <= h; height++) {
      maxAtHeight[height] = 0;
      for (int tree = 1; tree <= t; tree++) {

        // Sum all acorns at that height for the tree
        dp[tree][height] = acorns[tree][height];

        // Add the max of jumping to the left or jumping to the right or staying
        int m = 0;
        if (height > 0) m = dp[tree][height-1];
        if (height >= f) m = max(m, maxAtHeight[height-f]);

        dp[tree][height] += m;
        maxAtHeight[height] = max(maxAtHeight[height], dp[tree][height]);
      }
    }

    cout << maxAtHeight[h] << endl;
  }
  return 0;
}
