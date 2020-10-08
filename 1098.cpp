#include <iostream>
#include <cmath>

using namespace std;

int markers[4][2], n, m, nways, times[4], t = 1;
bool visited[10][10];

int distance(int ii, int ij, int ei, int ej) {
  return abs(ii - ei) + abs(ij - ej);
}

inline void dfs(int ci, int cj, int p, int step) {
  // If we visited a marker that we shouldn't have, don't carry on with the search
  for (int i = p; i < 4; i++) if (visited[markers[i][0]][markers[i][1]]) return;

  if (ci == markers[p][0] and cj == markers[p][1] and times[p] == step) {
    if (p == 3) { nways++; return; } // Got to the end on time
    else p++; // Got to checkpoint on time
  } else if (ci == markers[p][0] and cj == markers[p][1]) return; // Got to checkpoint but not on time
  else if (distance(ci, cj, markers[p][0], markers[p][1]) + step > times[p]) return; // Will time out

  visited[ci][cj] = true;

  // Try going up, down, left and right
  if (ci > 0 and not visited[ci - 1][cj]) {
    if (cj > 0 and cj < m - 1 and (ci - 1 == 0 or (ci > 1 and visited[ci - 2][cj]))) {
      if (visited[ci - 1][cj - 1] or visited[ci - 1][cj + 1]) dfs(ci - 1, cj, p, step + 1);
    } else dfs(ci - 1, cj, p, step + 1);
  } if (ci < n - 1 and not visited[ci + 1][cj]) {
    if (cj > 0 and cj < m - 1 and (ci + 1 == n - 1 or (ci < n - 2 and visited[ci + 2][cj]))) {
      if (visited[ci + 1][cj - 1] or visited[ci + 1][cj + 1]) dfs(ci + 1, cj, p, step + 1);
    } else dfs(ci + 1, cj, p, step + 1);
  } if (cj > 0 and not visited[ci][cj - 1]) {
    if (ci > 0 and ci < n - 1 and (cj - 1 == 0 or (cj > 1 and visited[ci][cj - 2]))) {
      if (visited[ci + 1][cj - 1] or visited[ci - 1][cj - 1]) dfs(ci, cj - 1, p, step + 1);
    } else dfs(ci, cj - 1, p, step + 1);
  } if (cj < m - 1 and not visited[ci][cj + 1]) {
    if (ci > 0 and ci < n - 1 and (cj + 1 == m - 1 or (cj < m - 2 and visited[ci][cj + 2]))) {
      if (visited[ci + 1][cj + 1] or visited[ci - 1][cj + 1]) dfs(ci, cj + 1, p, step + 1);
    } else dfs(ci, cj + 1, p, step + 1);
  }
  visited[ci][cj] = false;
}

int main() {
  while (cin >> n >> m and n and m) {
    for (int i = 0; i < 3; i++) cin >> markers[i][0] >> markers[i][1];
    markers[3][0] = 0; markers[3][1] = 1;
    nways = 0;
    for (int i = 0; i < 4; i++) times[i] = ((i + 1) * (n * m)) / 4;
    dfs(0, 0, 0, 1);
    cout << "Case " << t++ << ": " << nways << endl;
  }
  return 0;
}
