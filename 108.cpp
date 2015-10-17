#include <iostream>
#include <limits.h>
#define ll long long

using namespace std;

ll sum[101][101], n;

int main() {
  for (int i = 0; i <= 100; i++) sum[0][i] = sum[i][0] = 0;

  while (cin >> n) {
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
      cin >> sum[i][j], sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

    ll m = INT_MIN;
    for (int i0 = 0; i0 <= n; i0++) for (int j0 = 0; j0 <= n; j0++)
    for (int i1 = i0+1; i1 <= n; i1++) for (int j1 = j0+1; j1 <= n; j1++)
      m = max(m, sum[i1][j1] + sum[i0][j0] - sum[i0][j1] - sum[i1][j0]);

    cout << m << endl;
  }

  return 0;
}
