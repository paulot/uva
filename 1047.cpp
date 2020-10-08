#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int t, n, m, counted[11], serving[21], nc, loc[21], best, commonSizes[11], commonNums[11]; 
bool picked[21], common[11][21], bestTowers[21];

int getTotal() {
  int total = 0;
  memset(counted, 0, sizeof(counted));

  for (int i = 0; i < 21; i++) {
    if (picked[i]) {
      total += serving[i];
      for (int j = 0; j < nc; j++)
        if (common[j][i]) counted[j]++;
    }
  }

  for (int j = 0; j < nc; j++)
    if (counted[j] > 1) total -= (counted[j] - 1) * commonNums[j];

  return total;
}

void solve(int pSoFar, int picking) {
  if (pSoFar == m) {
    int total = getTotal();
    if (total > best) {
      best = total;
      memcpy(bestTowers, picked, sizeof(picked));
    }
    return;
  } else if (picking >= n) return;

  picked[picking] = true;
  solve(pSoFar + 1, picking + 1);
  picked[picking] = false;
  solve(pSoFar, picking + 1);
}

int main() {
  while (cin >> n >> m and m != 0 and n != 0) {
    best = 0; t++;
    for (int i = 0; i < n; i++) cin >> serving[i];
    cin >> nc;
    memset(common, 0, sizeof(common));
    memset(bestTowers, 0, sizeof(bestTowers));
    for (int i = 0; i < nc; i++) {
      cin >> commonSizes[i];
      int in;
      for (int j = 0; j < commonSizes[i]; j++) { cin >> in; common[i][in - 1] = true; }
      cin >> commonNums[i];
    }

    solve(0, 0);

    cout << "Case Number  " << t << endl;
    cout << "Number of Customers: " << best << endl << "Locations recommended: ";
    for (int i = 0, j = 0; i < 21; i++)
      if (bestTowers[i]) {
        j++;
        cout <<  i + 1;
        if (j < m) cout << ' ';
      }
    cout << endl << endl;
  }
  return 0;
}
