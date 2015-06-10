#include <iostream>

using namespace std;

int rev(long long n) {
  unsigned long long ans = 0;
  unsigned char a1 = n;
  unsigned char a2 = n >> 8;
  unsigned char a3 = n >> 16;
  unsigned char a4 = n >> 24;

  // cout << (int) a1 << ' ' << (int) a2 << ' ' << (int) a3 << ' ' << (int) a4 << endl;

  ans += a1; ans <<= 8;
  ans += a2; ans <<= 8;
  ans += a3; ans <<= 8;
  ans += a4;

  return ans;
}

int main() {
  int n;
  while (cin >> n) {
    cout << n << " converts to " << rev(n) << endl;
  }
  return 0;
}
