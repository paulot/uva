#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <strings.h>
#include <iomanip>
#define set(pos, mask) mask |= (1 << pos)
#define clear(pos, mask) mask &= ~(1 << pos)
#define sq(a) ((a) * (a))

using namespace std;

/**
 * For this problem, we want to represent all students that have already been picked
 * using a bitmask. Hence, all students that have a 1 set have already been picked.
 * That way, we recursively iterate through all possible pairings of students in a
 * depth-first search fashion.
 */

int xs[17], ys[17], n, tc;
double dp[1<<20];
string in;

double dist(int i, int j) {
  return sqrt(sq(xs[i]-xs[j]) + sq(ys[i]-ys[j]));
}

double solve(int picked) {
  if (picked == ((1 << n) - 1)) return 0; // No more teams to pick
  if (dp[picked] > 0) return dp[picked];

  double m = 1<<20;
  int cur = ffs(~picked) - 1;
  set(cur, picked);

  for (int i = cur + 1; i < n; i++) {
    if (not ((picked >> i) & 1)) {  // If pos i is not picked
      set(i, picked);
      m = min(dist(cur, i) + solve(picked), m);
      clear(i, picked);
    }
  }
  clear(cur, picked);
  return dp[picked] = m;
}

int main() {
  while (cin >> n and n) {
    n *= 2; memset(dp, -1, sizeof dp);
    for (int i = 0; i < n; i++) cin >> in >> xs[i] >> ys[i];
    cout << "Case " << ++tc << ": " << fixed << setprecision(2) << solve(0) << endl;
  }
  return 0;
}

