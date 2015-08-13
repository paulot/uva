/*
 * This is the alternative solution proposed in 11262.cpp
 */
#include <iostream>
#include <set>
#include <string>
#include <map>
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

int main() {
  int tc; cin >> tc;
  while (tc--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      int x, y; string c; cin >> x >> y >> c;
      if (c == "blue") colors[i] = blue;
      else colors[i] = red;
      poles[i] = make_pair(x, y);
    }

    int l = 0, r = 3000, num;
    bool ok = false;
    // Idea is to binary search on the distance to a given vertex
    while (l < r) {
      int mid = (l+r)/2;

      set<ii> reds, blues;
      map<ii, int> count;
      for (int i = 1; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
          if (colors[i] != colors[j]) {
            int d = dist(poles[i].xc, poles[i].yc,
                         poles[j].xc, poles[j].yc);
            if (d <= sq(mid)) {
              if (colors[i] == red) reds.insert(poles[i]), blues.insert(poles[j]);
              else reds.insert(poles[j]), blues.insert(poles[i]);
              count[poles[i]]++; count[poles[j]]++;
            }
          }
        }
      }

      // least ammount of outing edges in the opposite side of the minimum set
      set<ii> sel;
      set<ii> &mins = (reds.size() < blues.size()) ? reds : blues;
      set<ii> &maxs = (reds.size() < blues.size()) ? blues : reds;

      ii minp, maxp; int cmin = 10e6, cmax = 10e6;
      while (cmin == 10e6) {
        cmin = 10e6, cmax = 10e6;
        for (auto &imin : mins) {
          for (auto &imax : maxs) {
            if (sel.find(imin) == sel.end() and sel.find(imax) == sel.end()) {
              if (count[imin] < cmin) {
                cmin = count[imin]; cmax = count[imax];
                minp = imin; maxp = maxp;
              } else if (count[imin] == cmin and count[imax] < cmax) {
                cmin = count[imin]; cmax = count[imax];
                minp = imin; maxp = maxp;
              }
            }
          }
        }
        if (cmin != 10e6) {
          sel.insert(minp); sel.insert(maxp);
        }
      }

      int flow = sel.size();
      cout << "flow " << flow << endl;
      if (flow >= k) ok = true, num = r = mid;
      else l = mid + 1;

    }
    if (ok) cout << num << endl;
    else cout << "Impossible" << endl;
  }
}
