#include <iostream>
#include <string>

using namespace std;

int prices[10001][2], n, tc, q;
string names[10001];

int main() {
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> names[i] >> prices[i][0] >> prices[i][1];
    cin >> q;
    for (int i = 0; i < q; i++) {
      string found; int num = 0, c;
      cin >> c;
      for (int j = 0; j < n; j++) {
        if (num > 1) break;
        if (prices[j][0] <= c and prices[j][1] >= c) {
          found = names[j]; num++;
        }
      }
      if (num > 1 or num == 0) cout << "UNDETERMINED" << endl;
      else cout << found << endl;
    }
    if (tc) cout << endl;
  }
  return 0;
}
