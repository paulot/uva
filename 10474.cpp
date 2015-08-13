#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back

using namespace std;

int main() {
  int n, q, tc = 1;
  while (cin >> n >> q) {
    if (n == 0 and q == 0) return 0;
    vector<int> arr;
    for (int i = 0; i < n; i++) { int a; cin >> a; arr.pb(a); }
    sort(arr.begin(), arr.end());
    cout << "CASE# " << tc++ << ":" << endl;
    for (int i = 0; i < q; i++) {
      int num; cin >> num;
      int pos = lower_bound(arr.begin(), arr.end(), num) - arr.begin();
      if (arr[pos] != num) cout << num << " not found" << endl;
      else cout << num << " found at " << pos+1 << endl;
    }
  }
}
