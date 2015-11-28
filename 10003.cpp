#include <iostream>
#define INF 100000

using namespace std;

int len, n, cuts[1000], dp[1000][1000];

int cut(int left, int right) {
  if (left + 1 == right) return 0;
  if (dp[left][right] != INF) return dp[left][right];

  int cost = INF;
  for (int i = left+1; i < right; i++)
    cost = min(cost, cut(left, i) + cut(i, right) + (cuts[right] - cuts[left]));
  return dp[left][right] = cost;
}

int main() {
  while (cin >> len and len != 0 and cin >> n) {
    n += 2;
    cuts[0] = 0, cuts[n-1] = len;
    for (int i = 1; i < n-1; i++) cin >> cuts[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dp[i][j] = INF;
    cout << "The minimum cutting is " << cut(0, n-1) << '.' << endl;
  }
  return 0;
}
