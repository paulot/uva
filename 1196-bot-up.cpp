#include <iostream>
#include <cstring>

using namespace std;

int n, a, b, dp[101][101];

/**
 * The idea behind this algorithm is to generate a table that goes from
 * each of the 2 values coming in from the problem. For each value, we can
 * initialize the table to 1. So for values 2,2 dp[2][2] = 1. This initialization
 * takes care of the base cases for us. So we know that at the start, with a left
 * value of at most 2, and a right value of at most 2 we have 1 block.
 *
 * Once the base case is laid out, it becomes a matter of maximizing the sums.
 * We know that for left i and right j, the best value will be max(dp[i-1][j],
 * dp[i][j-1]), as we can either pick a value with a smaller left value or a smaller
 * right value.
 */

int main() {
  while (cin >> n and n) {
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) { cin >> a >> b; dp[a][b]++; }
    
    for (int i = 1; i <= 100; i++)
      for (int j = 1; j <= 100; j++)
        dp[i][j] += max(dp[i-1][j], dp[i][j-1]);

    cout << dp[100][100] << endl;
  }
  cout << '*' << endl;
  return 0;
}
