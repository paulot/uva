#include <iostream>
#include <algorithm>
#include <vector>

/**
 * Still getting WA, although it seems to pass just about every test case
 */

using namespace std;

typedef pair<int, int> ii;

struct compf {
  bool operator()(const ii &lhs, const ii &rhs) {
    if (lhs.first == rhs.first) return lhs.second > rhs.second;
    return lhs.first < rhs.first;
  }
};

ii arr[100000];
int n, m;

int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> m;
    int s, e;
    n = 0;
    while (cin >> s >> e) {
      if (s == 0 and e == 0) break;
      arr[n++] = make_pair(s, e);
    }

    sort(arr, arr+n, compf());

    // for (int i = 0; i < n; i++) cout << arr[i].first << ' ' << arr[i].second << endl;
    // cout << endl;

    vector<ii> ans;
    ans.push_back(arr[0]);
    int c_start = arr[0].first, c_end = arr[0].second;
    if (c_start > 0) {
      cout << 0 << endl;
      goto end;
    }
    for (int i = 1; i < n; i++) {
      ii last = ans[ans.size()-1];
      if (arr[i].first > last.second and arr[i].first >= 0 and arr[i].first <= m) {
        cout << 0 << endl;
        goto end;
      }

      if (arr[i].first <= 0 and arr[i].second >= last.second) {
        ans.pop_back(); ans.push_back(arr[i]);
        c_end = arr[i].second;
      } else if (ans.size() >= 2 and arr[i].first <= ans[ans.size()-2].second and 
          arr[i].second >= last.second) {
        ans.pop_back(); ans.push_back(arr[i]);
        c_end = arr[i].second;
      } else if (arr[i].first <= last.second and arr[i].second > last.second) {
        ans.push_back(arr[i]);
        c_end = arr[i].second;
      }
    }

    for (int i = ans.size()-1; i > 0; i--) {
      if (ans[i].second >= m and ans[i-1].second >= m)
        ans.pop_back();
      else
        break;
    }
    /*
      ii last = ans[ans.size()-1];

      if (c_end >= m) {
        if (ans.size() >= 2 and arr[i].first <= ans[ans.size()-2].second and 
          arr[i].second >= last.second) {
          ans.pop_back(); ans.push_back(arr[i]);
          c_end = arr[i].second;
        }
        continue;
      }
      */


    if (c_end < m) {
      cout << 0 << endl;
      goto end;
    }
    
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) 
      cout << ans[i].first << ' ' << ans[i].second << endl;
end:

    if (tc) cout << endl;
  }
  return 0;
}
