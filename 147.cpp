#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double in;
unsigned long long dp[30001], coins[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};

int main() {
  dp[0] = 1;
  for (int i = 0; i < 11; i++)
    for (int j = coins[i]; j < 30001; j++)
      dp[j] += dp[j-coins[i]];

  while (cin >> in and (int) (in * 100)) {
    printf("%6.2f%17lld\n", in, dp[((int) round(in * 100))]);
  }
  return 0;
}
