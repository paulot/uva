#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


string in;
int q;
map<char, vector<int> > candidates;

int main() {
  cin >> in;
  cin >> q;
  for (int i = 0; i < in.size(); i++) candidates[in[i]].push_back(i);

  for (int i = 0; i < q; i++) {
    cin >> in;
    
    if (candidates.find(in[0]) == candidates.end()) {
      cout << "Not matched" << endl;
      continue;
    }

    int start = candidates[in[0]][0], end = start;
    bool exited = false;
    for (int j = 1; j < in.size(); j++) {
      auto cand = lower_bound(candidates[in[j]].begin(), candidates[in[j]].end(), end + 1);

      if (cand == candidates[in[j]].end()) {
        cout << "Not matched" << endl;
        exited = true;
        break;
      } else {
        end = *cand;
      }
    }
    if (not exited) cout << "Matched " << start << ' ' << end << endl;
  }
  return 0;
}
