#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
int start[8], endt[8], order[8], n;


bool canLand(int gap) {
  int last = start[order[0]];
  for (int i = 1; i < n; i++) {
    if (endt[order[i]] >= last+gap) {
      last = max(last+gap, start[order[i]]);
    } else {
      return false;
    }
  }
  return true;
}

int main() {
  int tc = 1;
  while (cin >> n and n != 0) {
    for (int i = 0; i < n; i++) {
      order[i] = i;
      cin >> start[i] >> endt[i];
      start[i] *= 600; endt[i] *= 600;
    }
    int m = 0, mid;
    do {
      int low = 0, high = 864000;
      while (abs(high-low) > 1) {
        mid = (high+low)/2;
        if (not canLand(mid)) {
          high = mid;
        } else {
          low = mid;
        }
      }

      m = max(m, ((canLand(mid)) ? mid : low));
    } while(next_permutation(order, order+n));
    m = round(m/10.0);

    cout << "Case " << tc++ << ": " << m/60 << ":" << setw(2) << setfill('0') << m%60 << endl;
  }
  return 0;
}

