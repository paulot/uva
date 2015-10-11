#include <iostream>
#define cube(a) ((a)*(a)*(a))
#define ll unsigned long long

using namespace std;

int coins[21];
ll dp[10001];


void pop() {
  for (int i = 0; i < 21; i++) coins[i] = cube(i+1);
}

int main() {
  pop();
  int n;
  while (cin >> n) {
    for (int i = 0; i <= n; i++) dp[i] = 0;
    dp[0] = 1;

    for (int c = 0; c < 21; c++)
      for (int i = coins[c]; i <= n; i++)
        dp[i] += dp[i-coins[c]];

    cout << dp[n] << endl;
  }
  return 0;
}
