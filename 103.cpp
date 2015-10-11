/* 
 * First sort the input topologically
 * then apply lis
 */

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, vector<int> > iv;


int l[50], back[50], order[50], n, m;
iv blocks[50];

struct smaller {
  bool operator() (const iv &lhs, const iv &rhs) {
    for (int i = 0; i < m; i++) {
      if (lhs.second[i] == rhs.second[i])
        continue;
      else
        return lhs.second[i] < rhs.second[i];
    }
    return false;
  }
};

bool fit(const iv &lhs, const iv &rhs) {
  for (int i = 0; i < m; i++) {
    if (lhs.second[i] >= rhs.second[i])
      return false;
  }
  return true;
};

int main() {
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) {
      blocks[i].first = i;
      blocks[i].second = vector<int>();
      for (int j = 0; j < m; j++) {
        int in; cin >> in;
        blocks[i].second.push_back(in);
      }
      l[i] = 1;
      back[i] = i;
      sort(blocks[i].second.begin(), blocks[i].second.end());
    }


    // Topological sort
    sort(blocks, blocks+n, smaller());

    // LIS
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (fit(blocks[j], blocks[i]) and l[i] < l[j]+1)
          l[i] = l[j] + 1, back[i] = j;
      }
    }

    int gm = 0, r;
    vector <int> ans;

    // Find max
    for (int i = 0; i < n; i++)
      if (l[i] > gm)
        gm = l[i], r = i;

    cout << gm << endl;

    // Build path
    while (back[r] != r) {
      ans.push_back(blocks[r].first + 1);
      r = back[r];
    }
    ans.push_back(blocks[r].first+1);

    // Print path
    for (int i = ans.size()-1; i >= 0; i--) {
      cout << ans[i];
      if (i != 0) cout << ' ';
    }
    cout << endl;
  }
  return 0;
}
