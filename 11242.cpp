#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int back[10], front[10];
double ratios[100];

int main() {
  int b, f;
  while (cin >> b) {
    if (b == 0) return 0;
    cin >> f;
    for (int i = 0; i < b; i++) cin >> back[i];
    for (int i = 0; i < f; i++) cin >> front[i];

    int n = b * f, ir = 0;
    for (int i = 0; i < b; i++)
    for (int j = 0; j < f; j++)
      ratios[ir++] = front[j] / ((double) back[i]);

    sort(ratios, ratios+n);

    double m = 0;
    for (int i = 1; i < n; i++) m = max(m, ratios[i]/ratios[i-1]);

    cout << fixed << setprecision(2) << m << endl;
  }
}
