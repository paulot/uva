#include <iostream>
#include <string>
#define ll long long

using namespace std;

int poly[30], tc, pn, d, k, in;

ll power(int n, int p) {
  ll ans = 1;
  for (int i = 0; i < p; i++) ans *= n;
  return ans;
}

ll calc(int n) {
  ll ans = 0;
  for (int i = 0; i < pn; i++) ans += poly[i] * power(n, i);
  return ans;
}


int main() {
  cin >> tc;
  while (tc--) {
    cin >> pn; pn++;
    for (int i = 0; i < pn; i++) cin >> poly[i];
    cin >> d >> k;

    unsigned long long ck = 0;
    for (int n = 1; n <= k; n++) {
      ck += n * d;
      if (ck >= k) {
        cout << calc(n) << endl;
        break;
      }
    }
  }
  return 0;
}


