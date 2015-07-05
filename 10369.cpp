#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cmath>
#include <iomanip>
#define sq(a) ((a)*(a))

using namespace std;

typedef pair<int, int> ii;
typedef tuple<double, int, int> dii;

struct point { int x, y; };

struct comp {
  bool operator() (const dii& lhs, const dii& rhs) const {
    return get<0>(lhs) > get<0>(rhs);
  }
};


int sets[501];
point points[501];

int findSet(int a) { while (sets[a] != a) a = sets[a]; return a; }
void unionSet(int a, int b) { sets[findSet(a)] = findSet(b); }


int main() {
  int tc; cin >> tc;
  while (tc--) {
    int s, p; cin >> s >> p;
    for (int i = 0; i < p; i++) cin >> points[i].x >> points[i].y;

    for (int i = 0; i < p; i++) sets[i] = i;
    
    priority_queue<dii, vector<dii>, comp> Q;
    for (int i = 0; i < p; i++)
    for (int j = i+1; j < p; j++)
      Q.push(make_tuple(
            sq(points[i].x-points[j].x) + sq(points[i].y-points[j].y),
            i,
            j));

    double dist;
    for (int i = 0; i < p-s;) {
      dii c = Q.top();
      Q.pop();

      dist = get<0>(c); int p1 = get<1>(c), p2 = get<2>(c);
      int s1 = findSet(p1), s2 = findSet(p2);

      // cout << s1 << ' ' << s2 << ' ' << sqrt(dist) << ' ' << Q.size()<< endl;

      if (s1 == s2) continue;
      else {
        // cout << "took it\n";
        unionSet(s1, s2);
        i++;
      }
    }

    cout << fixed << setprecision(2) << sqrt(dist) << endl;
  }
  return 0;
}
