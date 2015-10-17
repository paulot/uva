#include <iostream>

using namespace std;


int n, m, sum[101][101];

int main() {
  while (cin >> n >> m and n != 0 and m != 0) {
    for (int i = 0; i <= n; i++) sum[i][0] = 0;
    for (int i = 0; i <= n; i++) sum[0][i] = 0;

    for (int i = 1; i <= n; i++) 
      for (int j = 1; j <= m; j++)
        cin >> sum[i][j], sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];

    int maxArea = 0;
    for (int i0 = 0; i0 < n; i0++) for (int j0 = 0; j0 < m; j0++) 
    for (int i1 = i0+1; i1 <= n; i1++) for (int j1 = j0+1; j1 <= m; j1++) {
      int numTrees = sum[i1][j1] + sum[i0][j0] - sum[i1][j0] - sum[i0][j1];
      int area = (i1-i0)*(j1-j0);
      if (numTrees == 0 and area > maxArea) maxArea = area;
    }

    cout << maxArea << endl;
  }
  return 0;
}
