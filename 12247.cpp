#include <iostream>
#include <algorithm>

using namespace std;

int a[3], b[3];

bool allZero() {
  for (int i = 0; i < 2; i++) if (a[i] != 0 or b[i] != 0) return false;
  return a[2] == 0;
}

bool valid(int num) {
  for (int i = 0; i < 2; i++) if (a[i] == num or b[i] == num) return false;
  return a[2] != num;
}

bool canWin(int num) {
  b[2] = num;
  bool taken[3] = { 0, 0, 0 };
  int score = 0;
  for (int i = 0; i < 3; i++) {
    int took = -1;
    int best = -1;
    for (int j = 0; j < 3; j++) {
      if (not taken[j] and a[i] > b[j] and b[j] > best) {
        took = j;
        best = b[j];
      }
    }
    if (took != -1) {
      taken[took] = true;
      score++;
    } else {
      score--;
    }
  }
  return score < 0;
}

int main() {
  while (cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] and not allZero()) {
     // cout << canWin(30) << endl;

    bool won = false;
    for (int i = 1; i <= 52; i++) {
      if (valid(i) and canWin(i)) {
        won = true;
        cout << i << endl;
        break;
      }
    }
    if (not won) cout << -1 << endl;
  }
  return 0;
}
