#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <tuple>
#include <set>
#define pb push_back
#define inf 10e6

using namespace std;

typedef pair<string, string> ss;
typedef pair<int, pair<string, char> > is;


map<string, vector<ss> > graph;
int dist[50000][30];

int djik(string &source, string &dest) {
  set<is> q;
  map<string, map<char, int> > dist;

  q.insert(make_pair(0, make_pair(source, '-')));

  for (auto &it : graph) {
    for (int i = 'a'; i <= 'z'; i++)
      dist[it.first][i] = inf;
  }

  for (int i = 'a'; i <= 'z'; i++) dist[source][i] = 0;

  while (not q.empty()) {
    is cur = *q.begin(); int c = cur.first;
    string v = cur.second.first; char l = cur.second.second;
    q.erase(q.begin());

    if (v == dest) break;

    for (auto &n : graph[v]) {
      string v2 = n.first, cost = n.second;

      if (l != cost[0] and dist[v2][cost[0]] > dist[v][l] + cost.size()) {
        auto it = q.find(make_pair(dist[v2][cost[0]], make_pair(v2, cost[0])));
        if (it != q.end()) q.erase(it);

        dist[v2][cost[0]] = dist[v][l] + cost.size();
        q.insert(make_pair(dist[v2][cost[0]], make_pair(v2, cost[0])));
      }
    }
  }
  int m = inf;
  for (auto &it : dist[dest]) m = min(m, it.second);
  return m;
}
  

int main() {
  while (true) {
    int n; cin >> n;
    if (n == 0) return 0;
    graph.clear();

    string s, d; cin >> s >> d;
    for (int i = 0; i < n; i++) {
      string a, b, c; cin >> a >> b >> c;
      graph[a].pb(make_pair(b, c));
      graph[b].pb(make_pair(a, c));
    }
    int dist = djik(s, d);
    if (dist == inf) cout << "impossivel" << endl;
    else cout << dist << endl;
  }
}

