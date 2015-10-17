#include <iostream>
#include <limits.h>

using namespace std;

int ntc, n, arr[20001];

int main() {
  cin >> ntc;
  for (int tc = 1; tc <= ntc; tc++) {
    cin >> n;
    for (int i = 0; i < n-1; i++) cin >> arr[i];

    int gsum = INT_MIN, sum = 0, gf = 0, gl = 0, f = 0;
    for (int i = 0; i < n-1; i++) {
      sum += arr[i];
      if (sum > gsum or (sum == gsum and i-f > gf - gl))
        gsum = sum, gf = f, gl = i;

      if (sum < 0)
        f = i+1, sum = 0;
    }

    if (gsum < 0) cout << "Route " << tc << " has no nice parts" << endl;
    else cout << "The nicest part of route " << tc << " is between stops " 
              << gf + 1 << " and " << gl + 2 << endl;
  }
  return 0;
}
  
