#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define N 100000

using namespace std;

int lis[N], lim[N], arr[N], n;

int main() {
  int tc; cin >> tc;
  cin.get(); cin.get();
  while (tc--) {
    n = 0;
    while (cin.peek() != '\n' and not cin.eof()) cin >> arr[n++], cin.get();
    cin.get();

    int ans = 0;
    for (int i = 0; i < n; i++) {
      lim[i] = lower_bound(lis, lis+ans+1, arr[i]) - lis;
      lis[lim[i]] = arr[i];
      ans = max(lim[i], ans);
    }
    vector<int> a;
    for (int i = n-1; i >= 0; i--) 
      if (lim[i] == ans) a.push_back(arr[i]), ans--;

    cout << "Max hits: " << a.size() << endl;
    for (int i = a.size()-1; i >= 0; i--) 
      cout << a[i] << endl;

    if (tc) cout << endl;
  }
  return 0;
}
