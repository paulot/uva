#include <iostream>
#include <string>

using namespace std;

int veryBest, grid[102][102], dp[102][102], n, m, tc;
string name;


int best(int row, int col) {
  if (dp[row][col] != -1) return dp[row][col];

  // Try up, down, left and right
  int bestSoFar = 0;
  if (grid[row - 1][col] < grid[row][col]) bestSoFar = max(bestSoFar, 1 + best(row - 1, col));
  if (grid[row + 1][col] < grid[row][col]) bestSoFar = max(bestSoFar, 1 + best(row + 1, col));
  if (grid[row][col - 1] < grid[row][col]) bestSoFar = max(bestSoFar, 1 + best(row, col - 1));
  if (grid[row][col + 1] < grid[row][col]) bestSoFar = max(bestSoFar, 1 + best(row, col + 1));
  veryBest = max(veryBest, bestSoFar);
  return dp[row][col] = bestSoFar;
}

int main() {
  cin >> tc;
  while (tc--) {
    cin >> name >> n >> m;
    veryBest = 0;
    for (int i = 0; i < 102; i++) for (int j = 0; j < 102; j++) grid[i][j] = 200, dp[i][j] = -1;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> grid[i][j];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) best(i, j);
    cout << name << ": " << 1 + veryBest << endl;
  }
  return 0;
}
