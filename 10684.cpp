#include <iostream>
#include <limits.h>

using namespace std;

int n, arr[10000];

int main() {
  while (cin >> n and n) {
    for (int i = 0; i < n; i++) cin >> arr[i];

    int gsum = INT_MIN, sum = 0;
    for (int i = 0; i < n; i++)
      sum += arr[i], gsum = max(sum, gsum), sum = max(sum, 0);

    if (gsum > 0) cout << "The maximum winning streak is " << gsum << "." << endl;
    else cout << "Losing streak." << endl;
  }
  return 0;
}
