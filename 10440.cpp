#include <iostream>
#include <cmath>

using namespace std;

/*
 * The idea for this problem is to load the ferry so that the first batch
 * is always the smallest. Hence if m is not completely divisible by n, we
 * should load the ferry m%n cars. By always loading the smallest batch first
 * we ensure that the last car is always arriving in the smallest time.
 */

int arr[2000];

int main() {
  int tc; cin >> tc;
  while (tc--) {
    int n, t, m; cin >> n >> t >> m;
    for (int i = 0; i < m; i++) cin >> arr[i];

    int time = 0, trips = 0;
    for (int i = (m+n-1)%n; i < m; i += n, trips++) time = max(arr[i], time) + t+t;
    cout << time-t << ' ' << trips << endl;
  }
  return 0;
}

