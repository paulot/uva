#include <iostream>
#include <limits.h>

using namespace std;

int in[500][500];

class quadtree {
  private:
    int mins[500001];
    int n, m;
    int build(int node, int x1, int y1, int x2, int y2) {
      if (x1 > x2 or y1 > y2 or x1 >= m
          or x2 >= m or y1 >= n or y2 >= n) return INT_MAX;
      else if (x1 == x2 and y1 == y2) { mins[node] = in[y1][x1]; 
        return in[y1][x1]; }
      else {
        // cout << "node " << node << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
        int nw = 4 * node - 2, ne = 4 * node - 1,
            sw = 4 * node, se = 4 * node + 1;
        int hx = (x1+x2)/2, hy = (y1+y2)/2, m = INT_MAX;

        if (hx != x2 or hy != y2) m = min(m, build(nw, x1, y1, hx, hy));
        if (hx + 1 != x1 or hy != y2) m = min(m, build(ne, hx + 1, y1, x2, hy));
        if (hx != x2 or hy + 1 != y1) m = min(m, build(sw, x1, hy + 1, hx, y2));
        if (hx + 1 != x1 or hy + 1 != y1) m = min(m, build(se, hx + 1, hy + 1, x2, y2));
        mins[node] = m;
        return m;
      }
    };

    int query(int node, int sx1, int sy1, int sx2, int sy2,
              int x1, int y1, int x2, int y2) {
      
      if (sx1 > x2 or sx2 < x1 or sy1 > y2 or sy2 < y1 or sx1 > sx2 or sy1 > sy2) return INT_MAX;
      if (sx1 >= x1 and sx2 <= x2 and sy1 >= y1 and sy2 <= y2) return mins[node];
      else {
        // cout << "node " << node << ' ' << sx1 << ' ' << sy1 << ' ' << sx2 << ' ' << sy2 << endl;
        int nw = 4 * node - 2, ne = 4 * node - 1,
            sw = 4 * node, se = 4 * node + 1;
        int hx = (sx1+sx2)/2, hy = (sy1+sy2)/2, m = INT_MAX;

        if (hx != sx2 or hy != sy2) m = min(m, query(nw, sx1, sy1, hx, hy, x1, y1, x2, y2));
        if (hx + 1 != sx1 or hy != sy2) m = min(m, query(ne, hx + 1, sy1, sx2, hy, x1, y1, x2, y2));
        if (hx != sx2 or hy + 1 != sy1) m = min(m, query(sw, sx1, hy + 1, hx, sy2, x1, y1, x2, y2));
        if (hx + 1 != sx1 or hy + 1 != sy1) m = min(m, query(se, hx + 1, hy + 1, sx2, sy2, x1, y1, x2, y2));

        return m;
      }
    };

    void update(int node, int sx1, int sy1, int sx2, int sy2,
              int x1, int y1, int val) {
      if (sx1 > sx2 or sy1 > sy2 or sx1 >= m
          or sx2 >= m or sy1 >= n or sy2 >= n) return;
      else if (sx1 == sx2 and sy1 == sy2 and sx1 == x1 and sy1 == y1) { mins[node] = val; }
      else {
        int nw = 4 * node - 2, ne = 4 * node - 1,
            sw = 4 * node, se = 4 * node + 1;
        int hx = (sx1+sx2)/2, hy = (sy1+sy2)/2;





  public:
    // m is associated to x, n to y
    quadtree(int n, int m) {
      this->n = n;
      this->m = m;
      build(1, 0, 0, m-1, n-1);
    };

    int get_min(int x1, int y1, int x2, int y2) {
      return query(1, 0, 0, m-1, n-1, x1, y1, x2, y2);
    }

    void print() {
      for (int i = 0; i < 100; i++) cout << mins[i] << ' ';
      cout << endl;
    };
};

int check(int x1, int y1, int x2, int y2) {
  int m = INT_MAX;
  for (int i = y1; i <= y2; i++)
  for (int j = x1; j <= x2; j++)
    m = min(m, in[i][j]);
  return m;
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  for (int j = 0; j < m; j++)
    cin >> in[i][j];

  cout << "done\n";
  quadtree tree(n, m);
  cout << "done\n";

  tree.print();
  // cout << tree.get_min(0,0,1,0) << endl;

  for (int y1 = 0; y1 < n; y1++)
  for (int x1 = 0; x1 < m; x1++)
  for (int y2 = y1; y2 < n; y2++)
  for (int x2 = x1; x2 < m; x2++) {
    int num = tree.get_min(x1, y1, x2, y2), real = check(x1, y1, x2, y2);
    if (num != real) {
      cout << "WRONG AT " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
      cout << "GOT " << num << " EXPECTED " << real << endl;
    }
  }
}


