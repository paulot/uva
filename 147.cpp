#include <iostream>
#include <iomanip>
#include <cmath>
#define ii unsigned long long

using namespace std;

int coins[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
ii dp[30001];

int main() {
  double in;
  while (cin >> in) {
    int num = ceil(in*100);
    if (num == 0) return 0;
    for (int i = 0; i <= num; i++) dp[i] = 0;
    dp[0] = 1;

    for (int i = 0; i < 11; i++)
      for (int j = coins[i]; j <= num; j++)
        dp[j] += dp[j-coins[i]];

    cout.width(6);
    cout << right << fixed << setprecision(2) << in;
    cout.width(17);
    cout << right << dp[num] << endl;
  }
}

