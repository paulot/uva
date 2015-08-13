/**
 * Still getting WA on this, however I have tested it with every single input I
 * could generate (with my random input generator) and for every single test, I
 * get the right answer.
 */
#include<iostream>
#include <queue>
#define ll long long

using namespace std;

enum species { human=0, alien=1 };

int dist[251][251], n, m, vals[251][2], ratios[251][2];
int g[502][502];
int parent[502];

void augmentPath(int start, int end, int flow) {
  for (int cur = end; cur != start; cur = parent[cur])
    g[parent[cur]][cur] -= flow, g[cur][parent[cur]] += flow;
}

int bfs(int start, int end) {
  queue<int> q;
  q.push(start), q.push(10e8);
  while (not q.empty()) {
    int c = q.front(); q.pop();
    int flow = q.front(); q.pop();

    if (c == end) return flow;

    for (int i = 0; i <= n+m+1; i++) {
      if (g[c][i] and parent[i] == -1) {
        flow = min(flow, g[c][i]);
        q.push(i); q.push(flow);
        parent[i] = c;
        if (g[i][end] and parent[end] == -1) {
          parent[end] = i;
          return min(flow, g[i][end]);
        }
      }
    }
  }
  return 0;
}

int edKarp(int start, int end) {
  for (int i = 0; i <= n+m+1; i++) parent[i] = -1;
  int flow, mflow = 0;
  while ((flow = bfs(start, end)) != 0) {
    mflow += flow;
    augmentPath(start, end, flow);
    for (int i = 0; i <= n+m+1; i++) parent[i] = -1;
  }
  return mflow;
}

void init() {
  for (int i = 0; i <= n+m+1; i++)
  for (int j = 0; j <= n+m+1; j++)
    g[i][j] = 0;

  for (int i = 1; i <= n; i++)
    g[0][i] = 1;

  for (int i = n+1; i <= n+m; i++)
    g[i][m+m+1] = 1;
}

void print() {
  for (int i = 0; i <= n+m+1; i++) {
  for (int j = 0; j <= n+m+1; j++)
    cout << g[i][j] << ' ';
  cout << endl;}
  cout << endl;
}

void makeg(int years) {
  init();
  // print();
  for (int i = 1; i <= n; i++) {
    for (int j = n+1, a = 1; j <= n+m; j++, a++) {
      ll nh = vals[i][human] + ((ll) ratios[i][human])*(years-dist[i][a]);
      ll na = vals[a][alien] + ((ll) ratios[a][alien])*years;
      // cout << i << ' ' << j << ' ' << nh << ' ' << na << endl;
      if (nh >= na) g[i][j] = 1;
    }
  }
  // print();
}

int main() {
  while (cin >> n >> m) {
    if (n == 0 and m == 0) return 0;
    for (int i = 1; i <= n; i++) cin >> vals[i][human] >> ratios[i][human];
    for (int i = 1; i <= m; i++) cin >> vals[i][alien] >> ratios[i][alien];

    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> dist[i][j];
    }

    int l = 0, r = 0xfffffff;
    bool ok = false;
    while (l < r) {
      int mid = (l+r)/2;
      // mid = 9000;

      makeg(mid);
      int flow = edKarp(0, m+n+1);
      // print();
      // cout << "flow " << flow << " mid " << mid << endl;

      if (flow >= m) ok = true, r = mid;
      else l = mid + 1;
      // break;
    }
    if (ok) cout << r << endl;
    else cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}

/*
int bfs(int start, int end) {
  queue<int> q;
  q.push(start), q.push(10e8);
  while (not q.empty()) {
    int c = q.front(); q.pop();
    int flow = q.front(); q.pop();

    if (c == end) return flow;

    for (int i = 0; i <= n+m+1; i++) {
      if (g[c][i] and parent[i] == -1) {
        q.push(i); q.push(min(flow, g[c][i]));
        parent[i] = c;
      }
    }
  }
  return 0;
}
*/

/*
int bfs(int start, int end) {
  for (int i = 1; i <= n; i++) {
    if (g[start][i] and parent[i] == -1) {
      parent[i] = start;
      int flow = g[start][i];
      for (int j = n+1; j <= n+m; j++) {
        if (g[i][j] and parent[j] == -1) {
          parent[j] = i;
          parent[end] = j;
          return min(flow, g[i][j]);
        }
      }
    }
  }
  return 0;
}
*/

