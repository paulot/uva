#include <iostream>
#define ll unsigned long long

using namespace std;

ll coins[5] = {1,5,10,25,50}, dp[30001], value;

int main() {
  while (cin >> value) {
    for (int i = 1; i <= value; i++) dp[i] = 0;
    dp[0] = 1;

    for (int c = 0; c < 5; c++)
      for (int i = coins[c]; i <= value; i++)
        dp[i] += dp[i - coins[c]];

    if (dp[value] == 1) cout << "There is only 1 way to produce " << value << " cents change." << endl;
    else cout << "There are " << dp[value] << " ways to produce " << value << " cents change." << endl;
  }
  return 0;
}
