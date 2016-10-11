#include <iostream>
#include <cmath>
#define ll unsigned long long

using namespace std;

int n, nf, na, size, ef;

int main() {
  cin >> n;
  for (int b = 0; b < n; b++) {
    cin >> nf;
    ll total = 0;
    for (int i = 0; i < nf; i++) {
      cin >> size >> na >> ef;
      total += round(((size / ((double) na)) * ef) * na);
    }
    cout << total << endl;
  }
  return 0;
}
