#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, in;
vector<int> heads, knights;

int main() {
  while (cin >> n >> m and n and m) {
    heads.clear();
    knights.clear();
    for (int i = 0; i < n; i++) { cin >> in; heads.push_back(in); }
    for (int i = 0; i < m; i++) { cin >> in; knights.push_back(in); }
    sort(knights.begin(), knights.end());
    sort(heads.begin(), heads.end());

    int gold = 0;
    bool solved = true;
    for (int i = 0; i < heads.size() and solved; i++) {
      auto it = lower_bound(knights.begin(), knights.end(), heads[i]);

      if (it == knights.end()) solved = false;
      else { gold += *it; knights.erase(it); }
    }

    if (solved) cout << gold << endl;
    else cout << "Loowater is doomed!" << endl;
  }
  return 0;
}
