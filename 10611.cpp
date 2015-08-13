#include <iostream>
#include <vector>
#include <algorithm>
#define pb push_back

using namespace std;

int main() {
  int n; cin >> n;
  vector<int> hs;
  for (int i = 0; i < n; i++) { int h; cin >> h; hs.pb(h); }
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int h; cin >> h;
    int ts = lower_bound(hs.begin(), hs.end(), h) - hs.begin();
    int st = upper_bound(hs.begin(), hs.end(), h) - hs.begin();


    ts = (ts == n or hs[ts] >= h) ? ts-1 : ts;
    if (ts < 0) cout << "X ";
    else cout << hs[ts] << ' ';

    if (st >= n) cout << "X" << endl;
    else cout << hs[st] << endl;
  }
  return 0;
}
