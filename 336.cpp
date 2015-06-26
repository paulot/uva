#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int bfs(map<int, vector<int> > &g, int s, int ttl) {
  if (g.find(s) == g.end()) return g.size(); 
  set<int> visited;
  queue<ii> q;
  q.push(make_pair(s, ttl));

  while (not q.empty()) {
    ii cur = q.front(); q.pop();
    int c = cur.first, cttl = cur.second; 
    visited.insert(c);

    if (cttl > 0) {
      for (int i = 0; i < g[c].size(); i++) {
        if (visited.find(g[c][i]) == visited.end()) {
          q.push(make_pair(g[c][i], cttl-1));
        }
      }
    }
  }
  return g.size() - visited.size();
}

int main() {
  int n, tc = 1;
  while (true) {
    cin >> n;
    if (n == 0) return 0;

    map<int, vector<int> > graph;
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    while (true) {
      int s, ttl;
      cin >> s >> ttl;
      if (s == 0 and ttl == 0) break;
      cout << "Case " << tc++ << ": " << bfs(graph, s, ttl) << " nodes not reachable from node "
           << s << " with TTL = " << ttl << ".\n";
    }
  }
}
