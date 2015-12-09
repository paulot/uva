#include <iostream>
#include <cstring>

using namespace std;

int n, tc, nums[1001][3], dp[1001][101];

/**
 * The idea behind this algorithm is to do a depth first search on the input space,
 * such that we try every single possible value that the current item can take.
 *
 * We set our states as pos and carry, meaning the current position of the item that
 * we're looking at and the number of items carried over from the last computation.
 *
 * For every position, we try to get all possible numbers of the item at pos.
 */

// price, can order, needed
int solve(int pos, int carry) {
  carry = min(carry, nums[pos][2]);
  if (pos == n) {
    if (nums[pos][2] > carry + nums[pos][1]) return -1;
    int buy = nums[pos][2] - carry;
    return buy * nums[pos][0];
  } else if (dp[pos][carry] != -1) return dp[pos][carry];
  int price = -1;

  for (int i = nums[pos][2] - carry; i <= min(nums[pos][1], nums[pos][2] - carry + nums[pos+1][2]); i++) {
    int cand = solve(pos + 1, i + carry - nums[pos][2]);
    int cprice = i * nums[pos][0];

    if (cand != -1)
      price = (price == -1) ? cprice + cand : min(price, cprice + cand);
  }

  return dp[pos][carry] = price;
}

int main() {
  cin >> tc;
  nums[0][0] = 1 << 20;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> nums[i][0] >> nums[i][1] >> nums[i][2];
    memset(dp, -1, sizeof dp);
    cout << solve(1, 0) << endl;
  }
  return 0;
}
