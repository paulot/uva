#include <iostream>

using namespace std;

int t, n;
char field[101];

int main() {
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cin >> n;
    int placed = 0;
    for (int i = 0; i < n; i++) cin >> field[i];
    for (int i = 1; i <= n;) {
      if (field[i - 1] == '.') {
        placed++;
        i += 3;
      } else i++;
    }
    cout << "Case " << tt << ": " << placed << endl;
  }
  return 0;
}
