#include <iostream>

using namespace std;

int tc, m, n, q;
char arr[101][101];

bool is_square(int ii, int jj, int len, char item) {
  if (ii + len > m or jj + len > n) return false;
  for (int i = 0; i < len; i++) if (arr[ii][jj+i] != item) return false;
  for (int i = 0; i < len; i++) if (arr[ii+i][jj] != item) return false;
  ii += len-1, jj += len-1;
  for (int i = 0; i < len; i++) if (arr[ii][jj-i] != item) return false;
  for (int i = 0; i < len; i++) if (arr[ii-i][jj] != item) return false;
  return true;
}

int main() {
  cin >> tc;
  while (tc--) {
    cin >> m >> n >> q;
    cout << m << ' ' << n << ' ' << q << endl;
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        cin >> arr[i][j];

    int ii, jj;
    for (int i = 0; i < q; i++) {
      cin >> ii >> jj; int j = 0;
      for (;ii-j >= 0 and jj-j >= 0 and is_square(ii-j,jj-j, 1+2*j, arr[ii][jj]);
          j++);
      cout << 1+2*(j-1) << endl;
    }
  }
  return 0;
}
