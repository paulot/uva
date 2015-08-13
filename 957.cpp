#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back

using namespace std;

int n, p;

int main() {
  while (cin >> p >> n) {
    vector<int> arr;
    int in;
    for (int i = 0; i < n; i++) { cin >> in; arr.pb(in); }
    
    int s, m = 0;
    for (int i = 0; i < n; i++) { 
      int pos = upper_bound(arr.begin(), arr.end(), arr[i]+p-1)-arr.begin();
      // cout << arr[i] << ' ' << arr[pos-1] << ' ' << i << ' ' << pos-1 << endl;
      if (pos-i > m) {
        s = i;
        m = pos-i;
      }
    }
    cout << m << ' ' << arr[s] << ' ' << arr[s+m-1] << endl;
  }
  return 0;
}


