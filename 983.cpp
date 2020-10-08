#include <iostream>
#define ll long long

using namespace std;

ll matrix[1001][1001], n, m, t;

int main() {
  while (cin >> n >> m) {
    if (t++) cout << endl;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> matrix[i][j];
        matrix[i][j] += matrix[i-1][j];
        matrix[i][j] += matrix[i][j-1];
        matrix[i][j] -= matrix[i-1][j-1];
      }
    }
    ll sum = 0;
    for (int i = m; i <= n; i++) {
      for (int j = m; j <= n; j++) {
        cout << matrix[i][j] - matrix[i-m][j] - matrix[i][j-m] + matrix[i-m][j-m] << endl;
        sum += matrix[i][j] - matrix[i-m][j] - matrix[i][j-m] + matrix[i-m][j-m];
      }
    }
    cout << sum << endl;
  }
  return 0;
}
