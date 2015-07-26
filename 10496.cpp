#include <iostream>
#include <cmath>

using namespace std;

int m = 1e6, n;
int xs[10], ys[10];
int sx, sy;
bool picked[10];

void dfs(int x, int y, int p, int dist) {
  // cout << x << ' ' << y << ' ' << p << ' ' << dist << endl;
  if (p == n) {
    int d = abs(x-sx) + abs(y-sy);
    m = min(dist + d, m);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (not picked[i]) {
      picked[i] = true;
      int d = abs(x-xs[i]) + abs(y-ys[i]);
      dfs(xs[i], ys[i], p+1, dist+d);
      picked[i] = false;
    }
  }
}

int main() {
  int tc; cin >> tc;
  while (tc--) {
    int a, b; cin >> a >> b;
    m = 1e6;
    cin >> sx >> sy;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> xs[i] >> ys[i]; picked[i] = false; }
    dfs(sx, sy, 0, 0);
    cout << "The shortest path has length " << m << endl;
  }
  return 0;
}
