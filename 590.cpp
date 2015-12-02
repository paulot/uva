#include <iostream>
#include <limits.h>

// Still getting WA for some reason, something in the get function

using namespace std;

// n: number of cities that the escape will take her
// k: number of flights she has to take
int k, n, tc, g[11][11][10], dp[20][1002];

int get(int from, int to, int day) {
  return (g[from][to][0]) ? g[from][to][day%(g[from][to][0])+1] : 0;
}

int solve(int cur, int day) {
  // cout << cur << ' ' << day << endl;
  if (day == k-1) return (get(cur, n-1, day) == 0) ? INT_MAX : get(cur, n-1, day);
  if (dp[cur][day] != -1) return dp[cur][day];

  int m = INT_MAX;
  for (int i = 0; i < n; i++) {
    if (i == cur or not get(cur, i, day)) continue;
    int cost = solve(i, day+1);
    if (cost < INT_MAX) m = min(get(cur, i, day) + cost, m);
  }

  return dp[cur][day] = m;
}

int main() {
  while (cin >> n >> k and k and n) {
    // if (tc) cout << endl;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (j == i) continue;
        cin >> g[i][j][0];
        for (int f = 1; f <= g[i][j][0]; f++) cin >> g[i][j][f];
      }
    }

    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= k; j++) dp[i][j] = -1;

    int sol = solve(0, 0);
    cout << "Scenario #" << ++tc << endl;
    if (sol < INT_MAX) cout << "The best flight costs " << sol << "." << endl;
    else cout << "No flight possible." << endl;
    cout << endl;
  }
  return 0;
}
