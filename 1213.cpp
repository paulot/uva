#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> primes;
int dp[1121][15], n, k;
bool is_prime[1121];

void sieve(int n) {
  for (int i = 2; i <= n; i++) is_prime[i] = 1;

  for (int i = 2; i <= n;) {
    primes.push_back(i);
    for (int j = 2*i; j <= n; j += i) is_prime[j] = 0;
    while(is_prime[++i] == 0);
  }
}

int main() {
  sieve(1121);
  dp[0][0] = 1;
  for (int p = 0; p < primes.size(); p++)
    for (int i = 1120; i >= primes[p]; i--)
      for (int j = 1; j <= 14; j++)
        dp[i][j] += dp[i- primes[p]][j-1];

  while (cin >> n >> k and (n != 0 or k != 0)) {
    cout << dp[n][k] << endl;
  }
  return 0;
}
          
