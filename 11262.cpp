/**
 * In this problem, we want to find the minimum length of a fence that we need
 * to form at least k fences. There are two possible solutions. The trivial one
 * is to try all options in a dfs, which will yield an algorithm with exponential
 * run time and tle. The second is to phrase this problem as a maximum flow problem.
 *
 * The maximum flow problem attempts to find out the maximum flow that can go from
 * a vertex start to a vertex end. You can see the Edmonds Karp algorithm for detail.
 * So, for this problem we can think of the poles as distict graphs where we want
 * to find how many distinct ways we can connect them while maintaining the distance
 * between each of the poles smaller than a particular length. To do that, we'll
 * start by guessing a length. Then given this guess, we can form a graph that
 * only connects the nodes that have a distance smaller than the guessed length.
 * Then, on this newly formed graph, we can run Edmonds Karp to find how many
 * distinct ways we can connect the different poles. If the number of distinct ways
 * is bigger than or equal to k, we have a candidate answer.
 *
 * Guessing the length
 * To guess the length, we first calculate the largest possible distance that we
 * can have (3000). Then, we use binary search to guess a length in the middle.
 * If the number of flows for the graphs limited by this guessed length is too small,
 * we increase the lower bound, else we decrease the upper bound.
 */

#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#define xc first
#define yc second
#define sq(x) ((x)*(x))

using namespace std;

typedef pair<int, int> ii;
enum color { red=0, blue=1 };

int dist(int x1, int y1, int x2, int y2) {
  return sq(x1-x2)+sq(y1-y2);
}

int colors[101];
ii poles[101];
int n, k, ne;
int g[102][102];
int parent[102];

void print() {
  for (int i = 0; i <= n+1; i++) {
    for (int j = 0; j <= n+1; j++) {
      cout << g[i][j] << ' ';
    } cout << endl;
  } cout << endl;
}

void augmentPath(int start, int end, int flow) {
  for (int c = end; c != start; c = parent[c]) {
    g[parent[c]][c] -= flow; g[c][parent[c]] += flow;
  }
}

int bfs(int start, int end) {
  queue<int> q;
  q.push(start); q.push(10e6);
  while(not q.empty()) {
    // cout << "size is " << q.size() << endl;
    int c = q.front(); q.pop();
    int flow = q.front(); q.pop();
    // cout << c << ' ' << flow << endl;
    if (c == end) return flow;

    for (int i = 0; i <= n+1; i++) {
      // cout << "c " << c << " i " << i << endl;
      if (g[c][i] and parent[i] == -1) {
        q.push(i); q.push(min(flow, g[c][i]));
        parent[i] = c;
      }
    }
  }
  return 0;
}

int maxFlow(int start, int end) {
  for (int i = 0; i <= n+1; i++) parent[i] = -1;
  int mflow = 0, flow;

  while ((flow = bfs(start, end)) != 0) {
    // cout << "flow " << flow << endl;
    // print();
    mflow += flow;
    augmentPath(start, end, flow);
    for (int i = 0; i <= n+1; i++) parent[i] = -1;
  }

  return mflow;
}

int main() {
  int tc; cin >> tc;
  while (tc--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      int x, y; string c;
      cin >> x >> y >> c;
      if (c == "blue") colors[i] = blue;
      else colors[i] = red;
      poles[i] = make_pair(x, y);
    }

    int l = 0, r = 3000, num;
    bool ok = false;
    // Idea is to binary search on the distance to a given vertex
    while (l < r) {
      int mid = (l+r)/2;
      // mid = 0;

      for (int i = 0; i <= n+1; i++)
      for (int j = 0; j <= n+1; j++)
        g[i][j] = 0;

      for (int i = 1; i <= n; i++)
        if (colors[i] == red) g[0][i] = 1;
        else g[i][n+1] = 1;

      // print();

      for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
          if (colors[i] != colors[j]) {
            int d = dist(poles[i].xc, poles[i].yc,
                         poles[j].xc, poles[j].yc);
            // cout << i << ' ' << j << endl;
            // cout << "d " << d << ' ' << sq(mid) << endl;
            if (d <= sq(mid)) {
              if (colors[i] == red) g[i][j] = 1;
              else g[j][i] = 1;
            }
          }
        }
      }
      // print();

      int flow = maxFlow(0, n+1);
      // cout << "flow is " << flow << endl;
      if (flow >= k) ok = true, num = r = mid;
      else l = mid + 1;

      // cout << flow << ' ' << mid<< endl;
      // print();
      // break;
    }
    if (ok) cout << num << endl;
    else cout << "Impossible" << endl;
  }
}
