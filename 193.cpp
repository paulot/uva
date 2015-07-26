#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

enum colors { black = 0, white = 1, plain = 2 };

int n, k;
bool graph[101][101];
colors color[101];
set <int> nodes;

bool can_add(int node) {
  for (int i = 1; i <= n; i++) {
    if (graph[node][i] and color[i] == black)
      return false;
  }
  return true;
}

void dfs(int node) {
  if (node == n+1) {
    int count = 0;
    for (int i = 1; i <= n; i++) if (color[i] == black) count++;
    if (nodes.size() < count) {
      nodes.clear();
      for (int i = 1; i <= n; i++) if (color[i] == black) nodes.insert(i);
    }
    return;
  }

  if (can_add(node)) {
    color[node] = black;
    dfs(node+1);
  }
  color[node] = white;
  dfs(node+1);
}

void solve() {
  nodes.clear();
  for (int i = 1; i <= n; i++) color[i] = plain;
  dfs(1);
}

int main() {
  int m; cin >> m;
  while (m--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      graph[i][j] = false;

    for (int i = 0; i < k; i++) {
      int a, b; cin >> a >> b;
      graph[a][b] = true;
      graph[b][a] = true;
    }

    solve();
    cout << nodes.size() << endl;
    auto last = nodes.end(); last--;
    for (auto it = nodes.begin(); it != nodes.end(); it++)
      cout << *it << ((it == last) ? "" : " ");
    cout << endl;
  }
  return 0;
}
