#include <iostream>

using namespace std;

int main() {
  int tc, n;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    cin >> n;
    int h = 0, l = 0, last = 10e8, cur;
    for (int i = 0; i < n; i++) {
      cin >> cur;
      if (last == 10e8) last = cur;
      else {
        if (cur > last) h++;
        else if (cur < last) l++;

        last = cur;
      }
    }
    cout << "Case " << t << ": " << h << ' ' << l << endl;
  }
  return 0;
}
