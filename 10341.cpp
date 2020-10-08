#include <iostream>
#include <cstdio>
#include <cmath>

#define e 2.718281828459045235360287
#define err 0.00000000001

using namespace std;

int p, r, q, s, t, u;

double f(double x) {
  return p * pow(e, -x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x, 2) + u;
}

int main() {
  while (cin >> p >> q >> r >> s >> t >> u) {
    double low = 0, high = 1, mid;
    while (fabs(low - high) > err) {
      mid = (low + high) / 2.0;

      if (f(mid) < 0) high = mid;
      else low = mid;
    }
    if ((long long) (f(mid) * 10000000) == 0) printf("%.4f\n", mid);
    else printf("No solution\n");
  }
  return 0;
}
