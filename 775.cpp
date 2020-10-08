#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

map<int, vector<int> > graph;
vector<int> curPath;
bool visited[300];
int n, a, b;
char in;

bool allVisited() {
  for (int i = 1; i <= n; i++) if (not visited[i]) return false;
  return true;
}

bool cycle(int start, int node) {
  if (allVisited()) {
    if (find(graph[node].begin(), graph[node].end(), start) != graph[node].end()) {
      for (int i = 0; i < curPath.size(); i++)
        cout << curPath[i] << ' ';
      return true;
    } else {
      return false;
    }
  }

  for (int i = 0; i < graph[node].size(); i++) {
    if (not visited[graph[node][i]]) {
      visited[graph[node][i]] = true;
      curPath.push_back(graph[node][i]);
      if (cycle(start, graph[node][i])) {
        return true;
      }
      curPath.pop_back();
      visited[graph[node][i]] = false;
    }
  }

  return false;
}

int main() {
  while (cin >> n) {
    graph.clear();
    while (scanf("%d %d\n", &a, &b)) {
      graph[a].push_back(b);
      graph[b].push_back(a);
    }
    cin >> in;
    memset(visited, 0, sizeof(visited));
    visited[1] = true;
    curPath.clear();
    curPath.push_back(1);

    if (cycle(1, 1)) cout << 1 << endl;
    else cout << 'N' << endl;
  }
  return 0;
}
