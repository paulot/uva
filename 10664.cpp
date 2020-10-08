#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int t, n, bags[21], sum[21], dp[21][201];
string in;

bool solve(int i, int left) {
  if (i > n) return left == sum[n] - left;
  if (dp[i][left] != -1) return dp[i][left];
  return dp[i][left] = (solve(i + 1, left) or solve(i + 1, left + bags[i]));
}

int main() {
  cin >> t;
  getline(cin, in);
  while (t--) {
    memset(dp, -1, sizeof(dp));

    getline(cin, in);
    stringstream ss(in);
    n = 1;
    while (ss >> bags[n]) sum[n] = bags[n] + sum[n-1], n++;
    n--;

    cout << ((solve(1, 0)) ? "YES" : "NO") << endl;
  }
  return 0;
}
