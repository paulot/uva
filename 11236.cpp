#include <cstdio>
#include <iostream>
#include <cmath>
#define ll unsigned long long

using namespace std;

int main() {
  for (int a = 1; a < 2000 - 3; a++)
  for (int b = a; a + b < 2000 - 2; b++)
  for (int c = b; a + b + c < 2000 - 1; c++) {
    ll A = a + b + c;
    ll B = a * b * c;
    ll C = 1000000;

    if (B != C and (C * A) % (B - C) == 0) {
      ll D = (C * A) / (B - C);
      if (D >= c and A + D <= 2000 and B * D <= 2000000000) {
        printf("%1.2f %1.2f %1.2f %1.2f\n", a / 100.0, b / 100.0, c / 100.0, D / 100.0);
      }
    }
  }
  return 0;
}
