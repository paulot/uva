#include <iostream>
#include <queue>
#include <set>
#define op(a) (((a)+1)%2)

using namespace std;
typedef pair<int, int> ii;

int n;
bool graph[201][201];
bool visited[201];

int color(int node) {
  visited[node] = true;
  queue<ii> q;
  q.push(make_pair(node, 0));
  set <int> colors[2];
  bool impossible = false;
  while(not q.empty()) {
    ii c = q.front(); q.pop();
    colors[c.second].insert(c.first);

    for (int i = 0; i < n; i++) {
      if (graph[c.first][i]) {
        if (colors[c.second].find(i) != colors[c.second].end()) impossible = true;
        if (not visited[i]) {
          visited[i] = true;
          q.push(make_pair(i, op(c.second)));
        }
      }
    }
  }
  return (impossible) ? 0 : max(colors[0].size(), colors[1].size());
}

int colorAll() {
  int m = 0;
  for (int i = 0; i < n; i++)
    if (not visited[i]) m += color(i); 
  return m;
}

int main() {
  int tc; cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      visited[i] = false;
      for (int j = 0; j < n; j++) graph[i][j] = false;
    }

    for (int i = 0; i < n; i++) {
      int ne; cin >> ne;
      for (int j = 0; j < ne; j++) {
        int e; cin >> e; e--;
        if (e < n) {
          graph[i][e] = true;
          graph[e][i] = true;
        }
      }
    }
    cout << colorAll() << endl;
  }
  return 0;
}
