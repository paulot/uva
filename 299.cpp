#include <iostream>
#include <algorithm>

using namespace std;

int arr[50], n;

int bub() {
  int ans = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n-1; j++)
      if (arr[j] > arr[j+1]) swap(arr[j], arr[j+1]), ans++;
  return ans;
}

int main() {
  int tc; cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Optimal train swapping takes " << bub() << " swaps.\n";
  }
  return 0;
}



