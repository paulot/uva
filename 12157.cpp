#include <iostream>

using namespace std;

int main() {
  auto juice = [](int a) -> int { return ((a / 60) + 1) * 15; };
  auto mile = [](int a) -> int { return ((a / 30) + 1) * 10; };
  int n, tc, c; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    cin >> n;
    int tm = 0, tj = 0;
    while (n--) { cin >> c; tm += mile(c); tj += juice(c); }
    cout << "Case " << t << ": ";
    if (tj == tm) cout << "Mile Juice " << tj << endl;
    else if (tj < tm) cout << "Juice " << tj << endl;
    else if (tm < tj) cout << "Mile " << tm << endl;
  }
  return 0;
}
