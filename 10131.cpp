#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <cstring>

using namespace std;

typedef tuple<int, int, int> iii;

vector<iii> elephants;
int n, a, b, lis[10001], pre[10001];

struct lt {
  inline bool operator() (const iii& p1, const iii& p2) {
    return (get<0>(p1) == get<0>(p2)) ? get<1>(p1) > get<1>(p2) : get<0>(p1) < get<0>(p2);
  }
};

int main() {
  while (cin >> a >> b) {
    elephants.push_back(make_tuple(a, b, ++n));
  }
  sort(elephants.begin(), elephants.end(), lt());
  memset(pre, -1, sizeof(pre));
  int best = -1, ind = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (get<1>(elephants[j]) > get<1>(elephants[i]) and get<0>(elephants[j]) < get<0>(elephants[i]) and lis[j] + 1 > lis[i]) {
        lis[i] = lis[j] + 1;
        pre[i] = j;
        
        if (lis[i] > best) { best = lis[i], ind = i; }
      }
    }
  }

  cout << best + 1 << endl;
  vector<int> ans;
  while (ind != -1) { ans.push_back(get<2>(elephants[ind])); ind = pre[ind]; }
  for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << endl;
  return 0;
}
