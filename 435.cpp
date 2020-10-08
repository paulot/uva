#include <iostream>
#include <cstring>

using namespace std;

int t, parties[20], n, total, indexes[20];

void solve(int op, int pivot, int c) {
  if (pivot == c) return solve(op, pivot, c + 1);
  if (c >= n) {
    int controlling = total - op - parties[pivot];
    if (controlling == op) indexes[pivot]++;
    if (controlling < op and controlling + parties[pivot] >= op) indexes[pivot]++;
    if (op < controlling and op + parties[pivot] > controlling) indexes[pivot]++;
    return;
  }

  solve(op + parties[c], pivot, c + 1);
  solve(op, pivot, c + 1);
}

int main() {
  cin >> t;

  while (t--) {
    total = 0;
    memset(indexes, 0, sizeof(indexes));
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> parties[i]; total += parties[i]; }
    for (int i = 0; i < n; i++) solve(0, i, 0);
    for (int i = 0; i < n; i++) cout << "party " << i + 1 << " has power index " << indexes[i] << endl;
    cout << endl;
  }
  return 0;
}
