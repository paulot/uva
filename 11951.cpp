#include <iostream>
#define ll long long

using namespace std;

int n, m, k, t;
ll matrix[101][101];

int main() {
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> matrix[i][j];
        matrix[i][j] += matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1];
      }
    }

    ll bestArea = 0, bestPrice = 0;
    for (int i1 = 1; i1 <= n; i1++) {
      for (int j1 = 1; j1 <= m; j1++) {
        for (int i2 = i1; i2 <= n; i2++) {
          for (int j2 = j1; j2 <= m; j2++) {
            ll currentPrice = matrix[i2][j2] - matrix[i1-1][j2] - matrix[i2][j1-1] + matrix[i1-1][j1-1];
            ll currentArea = (i2 - i1 + 1) * (j2 - j1 + 1);
            if ((currentPrice <= k and currentArea > bestArea) or (currentPrice < bestPrice and currentArea == bestArea)) {
              bestArea = currentArea;
              bestPrice = currentPrice;
            }
          }
        }
      }
    }
    cout << "Case #" << tt << ": " << bestArea << ' ' << bestPrice << endl;
  }
  return 0;
}
