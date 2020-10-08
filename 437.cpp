#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <limits.h>
#include <cstring>

using namespace std;

struct Triple {
  int in[3];
  Triple(int a, int b, int c) { in[0] = a; in[1] = b; in[2] = c; };
  unsigned int operator [](int i) { return this->in[i]; }
  string toString() { return "(" + to_string(in[0]) + ", " + to_string(in[1]) + ", " + to_string(in[2]) + ")"; }
  bool operator<(Triple other) const {
    if (this->in[0] == other.in[0] and this->in[1] == other.in[1]) return in[2] > other.in[2];
    if (this->in[0] == other.in[0]) return in[1] > other.in[1];
    return in[0] > other.in[0];
  }
};

int n, a, b, c, best, t;
vector<Triple> blocks;
int dp[200][200];

int solve(int last, int pos) {
  if (pos == blocks.size()) {
    return 0;
  } else if (dp[last][pos] != -1) return dp[last][pos];

  int cur = 0;
  if (blocks[pos][0] < blocks[last][0] and blocks[pos][1] < blocks[last][1]) {
    cur = blocks[pos][2] + solve(pos, pos + 1);
  }

  return dp[last][pos] = max(cur, solve(last, pos + 1));
}

int main() {
  while (cin >> n and n) {
    blocks.clear();
    blocks.push_back(Triple(INT_MAX, INT_MAX, 0));
    best = 0;
    for (int i = 0; i < n; i++) {
      cin >> a >> b >> c;
      blocks.push_back(Triple(a, b, c));
      blocks.push_back(Triple(a, c, b));
      blocks.push_back(Triple(b, a, c));
      blocks.push_back(Triple(b, c, a));
      blocks.push_back(Triple(c, a, b));
      blocks.push_back(Triple(c, b, a));
    }

    memset(dp, -1, sizeof(dp));
    sort(blocks.begin(), blocks.end());
    a = INT_MAX; b = INT_MAX;
    cout << "Case " << ++t << ": maximum height = " << solve(0, 1) << endl;
  }
}
