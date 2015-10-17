#include <iostream>

using namespace std;

int sum[101][101], s, n, tc;

void clear() {
  for (int i = 0; i <= s; i++) for (int j = 0; j <= s; j++)
    sum[i][j] = 0;
}

void setBoard(int r1, int c1, int r2, int c2) {
  for (int i = r1; i <= r2; i++) for (int j = c1; j <= c2; j++)
    sum[i][j] = 1;
}

void setSum() {
  for (int i = 1; i <= s; i++) for (int j = 1; j <= s; j++)
    sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
}

int main() {
  cin >> tc;
  while (tc--) {
    cin >> s >> n;
    clear();

    for (int i = 0; i < n; i++) {
      int r1, c1, r2, c2;
      cin >> r1 >> c1 >> r2 >> c2;
      setBoard(r1, c1, r2, c2);
    }

    setSum();

    int maxArea = 0;
    for (int i0 = 0; i0 < s; i0++) for (int j0 = 0; j0 < s; j0++)
    for (int i1 = i0 + 1; i1 <= s; i1++) for (int j1 = j0 + 1; j1 <= s; j1++) {
      int area = (i1-i0)*(j1-j0);
      int s = sum[i1][j1] - sum[i1][j0] - sum[i0][j1] + sum[i0][j0];
      if (s == 0 and area > maxArea) maxArea = area;
    }

    cout << maxArea << endl;
  }
  return 0;
}
