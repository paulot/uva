#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>

using namespace std;

int t, n, board[10][10], cols[10];


int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> board[i][j];
    for (int i = 0; i < n; i++) cols[i] = i;
    int best = INT_MAX, cur = 0;

    do {
      cur = 0;
      for (int i = 0; i < n; i++) cur += board[i][cols[i]];
      best = min(best, cur);
    } while (next_permutation(cols, cols + n));
    cout << best << endl;
  }
  return 0;
}
