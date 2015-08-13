#include <iostream>
#include <cmath>
#include <vector>
#define ll long long

using namespace std;

int books[500], n, k;

bool can_assign(ll num) {
  int i = 0;
  for (int m = 0; m < k; m++) {
    ll p = 0;
    while (i < n) {
      if (p+books[i] > num and m == k-1) return false;
      if (p+books[i] > num) break;
      else p += books[i++];
    }
  }
  return true;
}

void print(ll num) {
  int i = n-1;
  vector<vector<int> > ans;
  for (int m = 0; m < k; m++) {
    ll p = 0;
    ans.push_back(vector<int>());
    while (i >= 0) {
      if (p+books[i] > num or i + 1 < k - m) break;
      else {
        ans[m].push_back(books[i]);
        p += books[i--];
      }
    }
  }

  for (int m = k-1; m >= 0; m--) {
    for (int i = ans[m].size() - 1; i >= 0; i--) {
      cout << ans[m][i];
      if (m != 0 or i != 0) cout << ' ';
    }
    if (m > 0) cout << "/ ";
  }
  cout << endl;
}

ll search(ll lo, ll up) {
  if (abs(up-lo) < 2) return up;
  ll m = (lo+up)/2;
  if (can_assign(m)) return search(lo, m);
  else return search(m, up);
}

int main() {
  int tc; cin >> tc;
  while (tc--) {
    cin >> n >> k;
    ll m = 0;
    
    for (int i = 0; i < n; i++) { cin >> books[i]; m += books[i]; }
    print(search(0, m));
  }
  return 0;
}
