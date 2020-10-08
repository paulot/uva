#include <iostream>
#include <cmath>
#define inf 99999999

using namespace std;

int beepers[100][2], starti, startj, n, m, tc, nb, best, ncaptured;
bool captured[100];

int distance(int ii, int ij, int ei, int ej) {
  return abs(ii - ei) + abs(ij - ej);
}

int dfs(int ci, int cj) {
  if (ncaptured == nb) return distance(ci, cj, starti, startj);
  int cur = inf;
  for (int i = 0; i < nb; i++)
    if (not captured[i]) {
      captured[i] = true;
      ncaptured++;
      cur = min(cur, distance(ci, cj, beepers[i][0], beepers[i][1]) + dfs(beepers[i][0], beepers[i][1]));
      captured[i] = false;
      ncaptured--;
    }
  return cur;
}

int main() {
  cin >> tc;
  while (tc--) {
    cin >> n >> m >> starti >> startj >> nb;
    ncaptured = 0;
    for (int i = 0; i < nb; i++) cin >> beepers[i][0] >> beepers[i][1];
    cout << "The shortest path has length " << dfs(starti, startj) << endl;
  }
  return 0;
}
