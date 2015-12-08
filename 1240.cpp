#include <iostream>
#include <cstring>
#define set(num, x) num |= 1 << (x)
#define clear(num, x) num &= ~(1 << (x))
#define check(num, x) (((num) >> (x)) & 1)

using namespace std;

/**
 * Writeup:
 * This problem can be solved using a top-down dp approach as follows:
 *
 * First, we define the states of our solution that make it unique. In this
 * case, the states are: the total number of minutes of our strategy, the last
 * person to solve a problem and which problems have already been solved.
 *
 * Note that we define states this way as we don't care about who solved which
 * problem. We simply care of who was the last one to solve and the total cost.
 *
 * Moreover, definig states this way allows us to re-use states that we already
 * traversed, which is what this problem is all about.
 *
 * After defining the states, we simply do a depth first search with memoization
 * at each step.
 */

int t, n, times[3][13], dp[1 << 13][3][300];

int solve(int solved, int last, int total) {
  if (total >= 280) return 0;
  if (last > -1 and dp[solved][last][total] > -1) return dp[solved][last][total];

  int m = 0;
  for (int person = 0; person < 3; person++)
    if (person != last)
      for (int problem = 0; problem < n; problem++)
        if (not check(solved, problem) and total + times[person][problem] <= 280) {
          set(solved, problem);
          m = max(m, 1 + solve(solved, person, total + times[person][problem]));
          clear(solved, problem);
        }

  return (last > -1) ? (dp[solved][last][total] = m) : m;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for(int i = 0; i < 3; i++) for (int j = 0; j < n; j++) cin >> times[i][j];

    memset(dp, -1, sizeof dp);
    cout << solve(0, -1, 0) << endl;
  }
  return 0;
}
