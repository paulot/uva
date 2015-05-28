#include <iostream>
#include <cmath>

using namespace std;
long long s, d, a, b;

bool check() {
  return (a+b)==s and abs(a-b)==d and a >= 0 and b >= 0;
}

int main() {
  int n;
  cin >> n;
  for (; n > 0; n--) {
    cin >> s >> d;
    b = (s+d)/2;
    a = s-b;
    if (check()) cout << max(a,b) << ' ' << min(a,b) << endl;
    else {
      b = (s-d)/2;
      a = s-b;
      if (check()) cout << max(a,b) << ' ' << min(a,b) << endl;
      else cout << "impossible" << endl;
    }
  }

  return 0;
}
