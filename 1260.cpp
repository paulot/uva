#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> nums;
int t, n, sum, in, ind;
vector<int>::iterator it;

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    nums.clear();
    sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> in;
      it = upper_bound(nums.begin(), nums.end(), in);
      ind = it - nums.begin();
      sum += ind;
      nums.insert(it, in);
    }
    cout << sum << endl;
  }
  return 0;
}

