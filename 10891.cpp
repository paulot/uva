#include <iostream>
#include <limits.h>

using namespace std;

/*
 * The idea of this problem is to generalize the solution of the 
 * optimization for two players game. Initialy we can define the
 * recurrence relation for the classic problem as follows:
 * max(arr[i] - solve(i+1, j), arr[j] - solve(i, j-1))
 *
 * With this problem, we simply need to loop over all possible 
 * k's and find the max of all possibilities like so:
 *
 * for all k in the interval j-i:
 * max over all k of (max(arr[i...i+k] - solve(i+k,j),
 *                        arr[j-k...j] - solve(i, j-k)))
 */

int n, arr[101], dp[101][101], diff;

int solve(int i, int j) {
  if (i > j) return 0;
  if (i == j) return arr[i];
  if (dp[i][j] != INT_MIN) return dp[i][j];

  int m = INT_MIN, sumup = 0, sumdown = 0;
  for (int k = 1; k <= j-i+1; k++) {
    sumup += arr[i+k-1], sumdown += arr[j-k+1];
    m = max(m, max(sumup - solve(i+k, j),
                   sumdown - solve(i, j-k)));
  }
  return dp[i][j] = m;
}

int main() {
  while (cin >> n and n) {
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        dp[i][j] = INT_MIN;

    cout << solve(0, n-1) << endl;
  }
  return 0;
}
