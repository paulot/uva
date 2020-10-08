#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

using namespace std;

int t, n, m, classes[11][102], dp[12][102];

int solve(int i, int hoursLeft) {
  if (i > n or hoursLeft == 0) return 0;
  if (dp[i][hoursLeft] != -1) return dp[i][hoursLeft];
  int best = -10000;
  for (int hoursToStudy = 1; hoursToStudy <= hoursLeft - (n - i); hoursToStudy++) {
    if (classes[i][hoursToStudy] < 5) continue;
    best = max(best, classes[i][hoursToStudy] + solve(i + 1, hoursLeft - hoursToStudy));
  }
  return dp[i][hoursLeft] = best;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> classes[i][j];
    if (n > m) { cout << "Peter, you shouldn't have played billiard that much." << endl; continue; }
    memset(dp, -1, sizeof(dp));
    int sol = solve(1, m);
    if (sol < 5 * n) cout << "Peter, you shouldn't have played billiard that much." << endl;
    else cout << fixed << setprecision(2) << "Maximal possible average mark - " <<
                 round((((double) sol) / n) * 100) / 100 << "." << endl;
  }
  return 0;
}
