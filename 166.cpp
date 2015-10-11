#include <iostream>
#include <cmath>
#define INF 99999
#define MAX 200

using namespace std;

int coins[6] = { 1, 2, 4, 10, 20, 40 };
int available[6], from_me[201]; // Number of coins available and the smallest
                                // number of coins I can use to make change

// Calculates the smallest number of coins needed to make change from the store
int min_change_from_store(int value) {
  for (int i = 5; i >= 0; i--)
    if (coins[i] <= value)
      return 1 + min_change_from_store(value - coins[i]);
  return 0;
}

// Calculates the smallest number of coins needed to make change with my coins
void populate_from_me() {
  for (int i = 0; i < 6; i++)
    while (available[i]--)
      for (int j = MAX - coins[i] - 1; j >= 0; j--)
        if (from_me[j] != INF)
          from_me[j + coins[i]] = min(from_me[j + coins[i]], from_me[j] + 1);
}

int main() {
  double value;
  while (cin >> available[0] >> available[1] >> available[2] >> available[3]
             >> available[4] >> available[5] >> value) {
    if (available[0] + available[1] + available[2] + available[3] +
        available[4] + available[5] == 0) return 0;

    for (int i = 1; i < MAX; i++) from_me[i] = INF;
    from_me[0] = 0;

    populate_from_me();
    int ans = INF, val = value * 20.0;
    for (int i = val; i < MAX; i++)
      ans = min(ans, from_me[i] + min_change_from_store(i - val));

    cout.width(3);
    cout << ans << endl;
  }
}
