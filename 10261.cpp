#include <iostream>
#include <cstring>

using namespace std;

int best, n, t, capacity, cars[1002], dp[1002][10001];
long long sum[1002];

int solve(int i, int left) {
  if (i > n) return 0;
  if (dp[i][left] != -1) return dp[i][left];

  int right = sum[i] - left - cars[i], best = 0;

  if (left + cars[i] <= capacity) best = max(best, 1 + solve(i + 1, left + cars[i]));
  if (right + cars[i] <= capacity) best = max(best, 1 + solve(i + 1, left));
  return dp[i][left] = best;
}

void print(int i, int left) {
  if (i > best) return;

  if (dp[i + 1][left] == dp[i][left] - 1) {
    cout << "port" << endl;
    print(i + 1, left);
  } else {
    cout << "starboard" << endl;
    print(i + 1, left + cars[i]);
  }
}

int main() {
  cin >> t;
  while (t--) {
    n = 1;
    memset(sum, 0, sizeof(sum));
    memset(dp, -1, sizeof(dp));
    cin >> capacity;
    capacity *= 100;
    while (cin >> cars[n] and cars[n]) sum[n] = sum[n-1] + cars[n], n++;
    n--;
    
    best = solve(1, 0);
    cout << best << endl;
    print(1, 0);
    if (t) cout << endl;
  }
  return 0;
}
