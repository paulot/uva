#include <iostream>
#define ll unsigned long long

using namespace std;

ll coins[5] = {1,5,10,25,50}, dp[8000], value;

int main() {
  while (cin >> value) {
    for (int i = 1; i <= value; i++) dp[i] = 0;
    dp[0] = 1;

    for (int c = 0; c < 5; c++)
      for (int i = coins[c]; i <= value; i++)
        dp[i] += dp[i-coins[c]];

    cout << dp[value] << endl;
  }
  return 0;
}
