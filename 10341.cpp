#include <iostream>
#include <iomanip>
#include <cmath>
#define e 2.7182818284590452353602874713527

using namespace std;

int p, q, r, s, t, u;

double f(double x) {
  return p*pow(e,-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*(x*x)+u;
}

double solve(double left, double right) {
  double fl = f(left), fr = f(right), fm = f((left+right)/2);
  // cout << left << ' ' << right << ' ' << fr << endl;
  if (abs(fm) <= 0.00000000001) return (left+right)/2;
  if (abs(fr) <= 0.00000000001) return right;
  if (abs(fl) <= 0.00000000001) return left;
  if ((fl < 0 and fr < 0) or (fl >= 0 and fr >= 0)) return -5;
  return ((fm < 0 and fl < 0) or (fm >= 0 and fl >= 0)) ?
    solve((left+right)/2, right) : solve(left, (left+right)/2);
}

int main() {
  while (cin >> p >> q >> r >> s >> t >> u) {
    double sol = solve(0, 1);
    if (sol < -1) cout << "No solution" << endl;
    else cout << fixed << setprecision(4) << sol << endl;
  }
  return 0;
}
