#include <iostream>
#include <cstring>
#include <algorithm>
#define ll unsigned long long

using namespace std;

ll coins[1001], t, s, nu;
int n;

/**
 * The idea behind this greedy algorithm is as follows:
 *
 * For each coin denomination we will check if the current amount
 * that we have plus the current coin that we're looking at is smaller
 * then the next largest coin. If it's not, then we know for for the given
 * amount the bank can simply give out the larger coin. Hence we only want to
 * add coins to the count if the current sum we're looking at + the coin we're
 * looking at is smaller than the next coin.
 */

int main() {
  cin >> t;

  while (t--) {
    cin >> n; nu = min(2, n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    s = 1;
    for (int i = 1; i < n - 1; i++) {
      if (coins[i + 1] > s + coins[i]) {
        s += coins[i];
        nu++;
      }
    }

    cout << nu << endl;
  }
  return 0;
}
