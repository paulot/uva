#include <iostream>
#include <cstring>

using namespace std;

int n, m, k, best, a, b;
bool graph[101][101], black[101], visited[101], bb[101];

bool canBeBlack(int node) {
  for (int i = 1; i <= n; i++) if (graph[node][i] and black[i]) return false;
  return true;
}

void dfs(int node, int nb) {
  visited[node] = true;

  if (node == n + 1) {
    if (best < nb) {
      best = nb;
      memcpy(bb, black, sizeof(black));
    }
    return;
  }

  if (canBeBlack(node)) {
    black[node] = true;
    dfs(node + 1, nb + 1);
    black[node] = false;
  }

  dfs(node + 1, nb);
  visited[node] = false;
}

int main() {
  cin >> m;
  while (m--) {
    cin >> n >> k;
    memset(graph, 0, sizeof(graph));
    for (int i = 1; i <= k; i++) { cin >> a >> b; graph[a][b] = true; graph[b][a] = true; }
    
    dfs(1, 0);
    cout << best << endl;
    for (int i = 1; i <= n; i++)
      if (bb[i]) {
        best--;
        cout << i;
        if (best != 0) cout << ' ';
      }

    cout << endl;
  }
  return 0;
}
