#include <iostream>
#include <cstring>
#define mod(a, b) ((((a) % (b)) < 0) ? ((a) % (b)) + (b) : (a) % (b)) 
#define ll unsigned long long

using namespace std;

/**
 * The main idea is to setup dp on 3 dimensions. Since there is
 * no way to iterate through all possibilities we maintain the count
 * for all elements up to i and grouping up to g. For each i, g
 * we maintain the total of sums that end at sum % d. So
 *
 * dp[g][i][4] is the total sums that have a modulo of 4 with
 * g total numbers up to i.
 */

int t = 1, n, q, nums[202], d, m;
ll dp[21][202][21];

int main() {
  while (cin >> n >> q and n and q) {
    for (int i = 1; i <= n; i++) cin >> nums[i];
    cout << "SET " << t++ << ':' << endl;
    for (int qq = 1; qq <= q; qq++) {
      cin >> d >> m;
      memset(dp, 0, sizeof(dp));

      cout << "QUERY " << qq << ": ";
      // Setup initial dp for groups of size 1
      for (int i = 1; i <= n; i++) {
        for (int j = 0; j < d; j++)
          dp[1][i][j] = dp[1][i - 1][j];
        dp[1][i][mod(nums[i], d)]++;
      }


      for (int g = 2; g <= m; g++) {
        for (int i = 1; i <= n; i++) {
          // Copy what we had from previous iteration
          for (int j = 0; j < d; j++) dp[g][i][j] = dp[g][i - 1][j];

          // Add num we're looking at to each sum end
          for (int j = 0; j < d; j++) {
            dp[g][i][mod(nums[i] + j, d)] += dp[g - 1][i - 1][j];
          }
        }
      }

      cout << dp[m][n][0] << endl;
    }

  }
  return 0;
}
