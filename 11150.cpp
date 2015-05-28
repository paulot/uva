#include <iostream>

using namespace std;

int get_bot(int n) {
  int ans = 0, r = 0;
  while (n) {
    // cout << r << ' ' << n << endl;
    ans += n;
    r += n % 3;
    n /= 3;
    if (r >= 3) {
      n += r/3;
      r %= 3;
    }
  }
  if (r == 2) ans += 1;
  return ans;
}

int main() {
  int n;
  while (cin >> n) {
    cout << get_bot(n) << endl;
  }
  return 0;
}
