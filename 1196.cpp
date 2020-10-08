#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

struct comp {
  bool operator()(ii const &t1, ii const &t2) {
    return (get<0>(t1) == get<0>(t2)) ? get<1>(t1) < get<1>(t2) : get<0>(t1) < get<0>(t2);
  }
};

int n, a, b, dp[10001][10001];
vector<ii> blocks;

int solve(int last, int pos) {
  if (pos == blocks.size()) return 0;
  if (dp[last][pos] != -1) return dp[last][pos];

  int cur = 0;
  if (get<0>(blocks[pos]) >= get<0>(blocks[last]) and get<1>(blocks[pos]) >= get<1>(blocks[last])) {
    cur = 1 + solve(pos, pos + 1);
  }
  return dp[last][pos] = max(cur, solve(last, pos + 1));
}

int main() {
  while (cin >> n and n) {
    blocks.clear();
    blocks.push_back(make_pair(0, 0));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) { cin >> a >> b; blocks.push_back(make_pair(a, b)); }
    sort(blocks.begin(), blocks.end(), comp());
    cout << solve(0, 1) << endl;
  }
  cout << '*' << endl;
  return 0;
}
