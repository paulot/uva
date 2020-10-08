#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>

using namespace std;

int nums[20], sum, n, sols;
bool picked[20];
set<string> ans;
vector<string> pans;

void solve(int c, int s) {
  if (s == sum) {
    sols++;
    int np = 0;
    string a;
    for (int i = 0; i < n; i++) {
      if (picked[i]) {
        if (np != 0) a += '+';
        a += to_string(nums[i]);
        np++;
      }
    }
    if (ans.find(a) == ans.end()) {
      ans.insert(a);
      pans.push_back(a);
    }
    return;
  }
  if (s > sum or c >= n) return;
  picked[c] = true;
  solve(c + 1, s + nums[c]);
  picked[c] = false;
  solve(c + 1, s);
}

int main() {
  while (cin >> sum >> n and sum and n) {
    for (int i = 0; i < n; i++) cin >> nums[i];
    ans.clear(); pans.clear();
    sort(nums, nums + n, greater<int>());
    sols = 0;
    cout << "Sums of " << sum << ':' << endl;
    solve(0, 0);
    for (int i = 0; i < pans.size(); i++) cout << pans[i] << endl;
    if (sols == 0) cout << "NONE" << endl;
  }
  return 0;
}
