#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>

using namespace std;

int atimes[10], aimp[10], na, durations[10], np, missTimes[10], tmp[10], bestOrder[10], tmpSum, curSum;
int d;

void calcMissTimes() {
  memset(tmp, 0, sizeof(tmp));
  tmpSum = 0;
  for (int i = 0; i < na; i++) {
    int start = 0, minMiss = 9999999;
    for (int j = 0; j < np; j++) {
      minMiss = min(minMiss, min(abs(start - atimes[i]), abs(start + durations[j] - atimes[i])));
      start += durations[j];
    }
    tmp[aimp[i]] += minMiss;
    tmpSum += minMiss;
  }
}

bool tmpSmaller() {
  // if (tmpSum < curSum) return true;
  // else if (tmpSum > curSum) return false;

  for (int i = 0; i < 10; i++)
    if (tmp[i] < missTimes[i]) return true;
    else if (tmp[i] > missTimes[i]) return false;

  return false;
}

void solve() {
  do {
    calcMissTimes();

    if (tmpSmaller()) {
      memcpy(missTimes, tmp, sizeof(missTimes));
      memcpy(bestOrder, durations, sizeof(durations));
      curSum = tmpSum;
    }
  } while (next_permutation(durations, durations + np));
}

int main() {
  while (cin >> np and np) { d++;
    curSum = INT_MAX;

    memset(missTimes, 0, sizeof(missTimes));
    for (int i = 0; i < np; i++) { cin >> durations[i]; }
    cin >> na;
    for (int i = 0; i < na; i++) { cin >> aimp[i] >> atimes[i]; missTimes[i] = INT_MAX; }

    sort(durations, durations + np);

    solve();

    cout << "Data set " << d << endl;
    cout << "Order: ";
    for (int i = 0; i < np; i++) { cout << bestOrder[i]; if (i != np - 1) cout << ' '; }
    cout << endl;
    cout << "Error: " << curSum << endl;
  }
  return 0;
}
