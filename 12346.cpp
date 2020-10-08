#include <iostream>
#include <limits.h>
#define ll unsigned long long

using namespace std;


ll n, q, flows[21], costs[21], solCost, bestCost, totalVolume, hoursOpen; 
bool open[21];

bool canSolve() {
  ll ctotal = 0; solCost = 0;
  for (int i = 0; i < n; i++) if (open[i]) { solCost += costs[i]; ctotal += flows[i] * hoursOpen; }
  return ctotal >= totalVolume;
}

void solve(int ind) {
  if (canSolve()) {
    bestCost = min(bestCost, solCost);
  } else if (ind < n) {
    open[ind] = true;
    solve(ind + 1);
    open[ind] = false;
    solve(ind + 1);
  }
}

int main () {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> flows[i] >> costs[i];
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> totalVolume >> hoursOpen;
    bestCost = INT_MAX;
    solve(0);
    cout << "Case " << i + 1 << ": ";
    if (bestCost != INT_MAX) cout << bestCost << endl;
    else cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
