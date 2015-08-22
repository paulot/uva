#include <algorithm>
#include <iostream>

using namespace std;

int heads[20000], knights[20000];

int main() {
  int n, m;
  while (cin >> n >> m and (n != 0 or m != 0)) {
    for (int i = 0; i < n; i++) cin >> heads[i];
    for (int i = 0; i < m; i++) cin >> knights[i];

    sort(heads, heads+n);
    sort(knights, knights+m);

    int k = 0, price = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
      while(k < m and knights[k] < heads[i]) k++;
      if (k >= m) { ok = false; break; }
      else { price += knights[k], k++; }
    }
    if (ok) cout << price << endl;
    else cout << "Loowater is doomed!" << endl;
  }
  return 0;
}
