#include <iostream>
#include <cstring>

using namespace std;

/**
 * The idea is to try all possible bitmasks in a complete search fashion.
 * So, given the current length, and the global bitmask (representing all
 * sticks that have been gathered) we try to set every possible bit that
 * can be set in the current bitmask. For each of these, we run the recursion
 * again.
 */

int n, tc, arr[20], dp[1 << 20], sum;

bool solve(int len, int bitmask) {
  if (len > sum/4) return false; // Can't continue this path
  if (len == sum/4 and bitmask == ((1 << n) - 1)) return true; // Done
  if (dp[bitmask] != -1) return dp[bitmask]; // Already found answer
  if (len == sum/4) len = 0; // Starting a new side

  for (int i = 0; i < n; i++)
    if ((bitmask & (1 << i)) == 0 and   // We are only setting something that can be set
        solve(len + arr[i], bitmask | (1 << i))) return dp[bitmask] = true;
  return dp[bitmask] = false;
}

int main() {
  cin >> tc;
  while (tc--) {
    cin >> n; sum = 0;
    for (int i = 0; i < n; i++) cin >> arr[i], sum += arr[i];
    memset(dp, -1, sizeof dp);
    if (sum % 4) cout << "no" << endl;
    else cout << ((solve(0, 0)) ? "yes" : "no") << endl;
  }
  return 0;
}

