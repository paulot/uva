#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int score(const string &s) {
  int ans = 0;
  for (int i = 0; i < s.size() - 1; i++)
    for (int j = i+1; j < s.size(); j++)
      if (s[i] > s[j]) ans++;
  return ans;
}

bool cmp(const string &lhs, const string &rhs) {
  return score(lhs) < score(rhs);
}

int main() {
  int tc; cin >> tc;
  string null; getline(cin, null);
  getline(cin, null);
  while(tc--) {
    int n, m; cin >> n >> m;
    string arr[100];
    for (int i = 0; i < m; i++) cin >> arr[i];
    stable_sort(arr, arr+m, cmp);

    for (int i = 0; i < m; i++) cout << arr[i] << endl;
    getline(cin, null);
    getline(cin, null);
    if (tc != 0) cout << endl;
  }
  return 0;
}

