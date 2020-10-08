#include <iostream>
#include <map>
#include <cmath>
#define dist(a, b) (abs(a - b))

using namespace std;

map<int, int> houses;
int n, in, t;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    houses.clear();
    for (int i = 0; i < n; i++) { cin >> in; houses[in]++; }
    int best = 99999999;
    for (auto ii : houses) {
      int cur = 0;
      for (auto it : houses) {
        cur += it.second * dist(it.first, ii.first);
      }
      best = min(cur, best);
    }
    cout << best << endl;
  }
  return 0;
}
