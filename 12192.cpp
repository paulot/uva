#include <iostream>
#include <algorithm>

using namespace std;

int n, m, q, low, high, rows[501][501];

/**
 * This algorithm works in the following way:
 * For each query request that we have, we iterate from each row of the
 * input. On each row, we'll find the first column that matches the query.
 * Then we check if a square of a given size actually fits in the current
 * row, starting from the current column.
 *
 * This works because of the way that the input is guaranteed to come in,
 * each row should come in sorted order, and each column is also in sorted order.
 * Because of this, we can simply take a point i, j and a size and check if
 * point arr[i + size][j + size] is smaller than or equal to the high point
 * of the query. We don't need to check other points of the square because of the
 * following property. Take 4 points:
 *
 * a        b
 *
 *
 * c        d
 *
 * By the input definition we know that a < c < d and a < b < d. Hence, as
 * long as a and d are within the bounds of the query, we know that the square
 * given by a, b, c, d is valid.
 */

int main() {
  while (cin >> n >> m and n and m) {
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> rows[i][j];
    cin >> q;

    for (int qq = 0; qq < q; qq++) {
      cin >> low >> high;
      int best = 0;

      for (int i = 0; i < n; i++) {
        int j = lower_bound(rows[i], rows[i] + m, low) - rows[i];

        for (int size = best; size < n; size++) {
          if (i + size >= n or j + size >= m or rows[i + size][j + size] > high) break;
          best = max(best, size + 1);
        }
      }
      cout << best << endl;
    }
    cout << '-' << endl;
  }
  return 0;
}
