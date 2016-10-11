#include <iostream>

using namespace std;

int main() {
  int tc, n, c;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    cin >> n;
    int speed = 0;
    for (int i = 0; i < n; i++) {
      cin >> c;
      if (c > speed) speed = c;
    }
    cout << "Case " << t << ": " << speed << endl;
  }
  return 0;
}
