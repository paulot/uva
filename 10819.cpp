#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int m, n, p, v, dp[102][10201];
vector<ii> dresses;

bool comp(const ii &a, const ii &b) {
  return (a.first == b.first) ? a.second < b.second : a.first < b.first;
}

int solve(int i, int bought) {
  if (i >= n) return 0;
  if (dp[i][bought] != -1) return dp[i][bought];
  if (bought + dresses[i].first <= m) {
    return dp[i][bought] = max(dresses[i].second + solve(i + 1, bought + dresses[i].first), solve(i + 1, bought));
  } else if (bought + dresses[i].first > 2000 and m + 200 >= bought + dresses[i].first) {
    return dp[i][bought] = max(dresses[i].second + solve(i + 1, bought + dresses[i].first), solve(i + 1, bought));
  } else {
    return dp[i][bought] = solve(i + 1, bought);
  }
}

int main() {
  while (cin >> m >> n) {
    memset(dp, -1, sizeof(dp));
    dresses.clear();
    for (int i = 0; i < n; i++) { cin >> p >> v; dresses.push_back(make_pair(p, v)); }
    sort(dresses.begin(), dresses.end(), comp);
    cout << solve(0, 0) << endl;
  }
  return 0;
}
