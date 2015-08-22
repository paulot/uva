#include <iostream>
#include <algorithm>

using namespace std;

int price[20000];

int main() {
  int tc; cin >> tc;
  for (int t = 0; t < tc; t++) {
    int n, d = 0; cin >> n;
    for (int i = 0; i < n; i++) cin >> price[i];
    sort(price, price+n, greater<int>());
    for (int i = 1; i <= n; i++)
      if (i % 3 == 0) d += price[i-1];
    cout << d << endl;
  }
  return 0;
}
