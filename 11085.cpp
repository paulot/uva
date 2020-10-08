#include <iostream>
#include <limits.h>
#include <set>

using namespace std;

int rows[8], t, in, best;
bool takenRows[8];

bool allSolved() {
  for (int i = 0; i < 8; i++)
    for (int j = i + 1; j < 8; j++)
      if (rows[i] == rows[j] or abs(rows[j] - rows[i]) == j - i) return false;
  return true;
}

void solve(int c, int moves) {
  if (moves > best) return;
  if (c >= 8) {
    if (allSolved()) best = min(moves, best);
    return;
  }

  int t = rows[c];
  for (int i = 0; i < 8; i++) {
    if (not takenRows[i]) {
      rows[c] = i;
      takenRows[i] = true;
      solve(c + 1, moves + ((t == i) ? 0 : 1));
      takenRows[i] = false;
    }
  }
  rows[c] = t;
}

int main() {
  while (cin >> in) { t++;
    rows[0] = in - 1;
    for (int i = 1; i < 8; i++) { cin >> in; rows[i] = in - 1; }
    best = INT_MAX;
    solve(0, 0);
    cout << "Case " << t << ": " << best << endl;
  }
  return 0;
}
