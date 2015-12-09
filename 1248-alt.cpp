
#include <iostream>
#include <cstring>

using namespace std;

/**
 * Before reading this, please ensure you understand the logic behind the
 * other way of solving this problem.
 *
 * In this alternate solution, we explore an optimization of the problem.
 * On the initial solution (see 1248.cpp) we linearly try all of the possible values
 * that we can order of the item that we're seeing. On this solution, we binary
 * search for a valid amount that we can order, and linearly search for the optimal
 * solution form there. This ends up running ~35% faster (on uva judge and input) than
 * the other solution.
 *
 * Note that we cannot simply binary search the answer because getting a valid answer
 * to the problem is not necessarily an indication that the amount of items for the
 * current position will decrease (we could get more of the current item and decrease
 * the global cost). Hence, the linear search at the end is needed.
 */

int n, tc, nums[1001][3], dp[1001][101];

// price, can order, needed
int solve(int pos, int carry) {
  carry = min(carry, nums[pos][2]);

  if (pos == n) {
    if (nums[pos][2] > carry + nums[pos][1]) return -1;
    int buy = nums[pos][2] - carry;
    return buy * nums[pos][0];
  } else if (dp[pos][carry] != -1) return dp[pos][carry];

  // Bin search the amount to buy
  int low = nums[pos][2] - carry;
  int high = min(nums[pos][1], nums[pos][2] - carry + nums[pos+1][2]) + 1;
  int price = -1;
  while (low < high) {
    int med = (low + high) / 2;
    int cprice = med * nums[pos][0];
    int cand = solve(pos + 1, med + carry - nums[pos][2]);

    if (cand != -1) {
      price = (price == -1) ? cprice + cand : min(price, cprice + cand);
      high = med;
    } else {
      low = med + 1;
    }
  }
  for (int i = high; i <= min(nums[pos][1], nums[pos][2] - carry + nums[pos+1][2]); i++) {
    int cprice = i * nums[pos][0];
    int cand = solve(pos + 1, i + carry - nums[pos][2]);
    if (cand != -1) price = (price == -1) ? cprice + cand : min(price, cprice + cand);
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
