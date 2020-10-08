#include <iostream>
#include <algorithm>

using namespace std;

int arr[10000], n, q, in, ca;

int query(int q) {
  int ind = lower_bound(arr, arr + n, q) - arr;
  int best = 99999999;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (abs(arr[i] + arr[j] - q) < abs(best - q)) best = arr[i] + arr[j];
  return best;
}

int main() {
  while (cin >> n and n) {
    ca++;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);

    cin >> q;
    cout << "Case " << ca << ':' << endl;
    for (int i = 0; i < q; i++) {
      cin >> in;
      cout << "Closest sum to " << in << " is " << query(in) << '.' << endl;
    }
  }
  return 0;
}
