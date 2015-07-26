#include <iostream>
#include <string>

using namespace std;

int grid[100][100], dp[100][100];
int n, m;

int dfs(int i, int j) {
  if (dp[i][j] != -1) return dp[i][j];
  int mi = 0;
  if (i > 0 and grid[i-1][j] < grid[i][j]) mi = max(dfs(i-1, j)+1, mi);
  if (j > 0 and grid[i][j-1] < grid[i][j]) mi = max(dfs(i, j-1)+1, mi);
  if (i < n-1 and grid[i+1][j] < grid[i][j]) mi = max(dfs(i+1, j)+1, mi);
  if (j < m-1 and grid[i][j+1] < grid[i][j]) mi = max(dfs(i, j+1)+1, mi);
  dp[i][j] = mi;
  // cout << i << ' ' << j << ' ' << mi << endl;
  return mi;
}


int main() {
  int tc; cin >> tc;
  while (tc--) {
    string name; cin >> name >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i][j] = -1;
        cin >> grid[i][j];
      }
    }
    int mi = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        mi = max(mi, dfs(i, j));

    cout << name << ": " << mi+1 << endl;
  }
  return 0;
}
