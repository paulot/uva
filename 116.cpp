#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

// printing wrong path, giving the right answer

int vals[11][101], shortest[11][101], paths[11][101], n, m;

void getPath(vector<int> &path, int row) {
  path.clear();
  for (int i = m; i >= 1; i--)
    path.push_back(row), row = paths[row][i];
}

bool smaller(vector<int> &v1, vector<int> &v2) {
  for (int i = m-1; i >= 0; i--)
    if (v1[i] != v2[i]) return v1[i] < v2[i];
  return false;
}

int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) for (int j = 1; j <= m; j++) cin >> vals[i][j], shortest[i][j] = 0;

    for (int j = 1; j <= m; j++) 
      for (int i = 0; i < n; i++) {
        /*
        cout << i << ' ' << j << endl;
        cout << i << ' ' << j-1 << ' ' << shortest[i][j-1] << endl;
        cout << i+1 % n << ' ' << j-1 << ' ' << shortest[(i+1 > n) ? 1 : i+1][j-1] << endl;
        cout << (n-(i-1)) % (n+1) << ' ' << j-1 << ' ' << shortest[(n-(i-1)) % (n+1)][j-1] << endl;;
        */
        int back = shortest[i][j-1], up = shortest[(i+1) % n][j-1],
            down = shortest[((i == 0) ? n-1 : i-1)][j-1], row = i, val = back;

        if (down < val or (down == val and row > ((i == 0) ? n-1 : i-1)))
          val = down, row = ((i == 0) ? n-1 : i-1);

        if (up < val or (up == val and row > (i+1) % n))
          val = up, row = (i+1) % n;

        shortest[i][j] = val + vals[i][j];
        paths[i][j] = row;
      }

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) cout << shortest[i][j] << ' ';
      cout << endl;
    } cout << endl;

    int ans = INT_MAX, row;
    vector<int> path;
    for (int i = 0; i < n; i++) {
      if (shortest[i][m] < ans) {
        ans = shortest[i][m], row = i;
        getPath(path, row);
      } else if (shortest[i][m] == ans) {
        cout << "asdfasdf " << ans << endl;
        vector<int> temp;
        getPath(temp, i);
        if (smaller(temp, path)) {
          ans = shortest[i][m], row = i;
          path = temp;
        }
      }
    }

    // Print path back
    for (int i = m-1; i >= 0; i--) {
      cout << 1 + path[i];
      if (i != 0) cout << ' ';
    }
    cout << endl;

    cout << ans << endl;
  }
  return 0;
}


