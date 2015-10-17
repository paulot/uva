#include <iostream>
#include <limits.h>

using namespace std;

int sum[160][160], n, tc;

int main() {
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
      cin >> sum[i][j]; 
      sum[i+n][j] = sum[i][j+n] = sum[i+n][j+n] = sum[i][j];
    }
    for (int i = 1; i <= 2*n; i++) for (int j = 1; j <= 2*n; j++)
      sum[i][j] += (sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1]);

    int m = INT_MIN;

    for (int i0 = 0; i0 <= n; i0++) for (int j0 = 0; j0 <= n; j0++)
    for (int i1 = i0 + 1; i1 <= i0+n; i1++) for (int j1 = j0 + 1; j1 <= j0+n; j1++)
      m = max(m, sum[i1][j1] - sum[i0][j1] - sum[i1][j0] + sum[i0][j0]);

    cout << m << endl;
  }
  return 0;
}
