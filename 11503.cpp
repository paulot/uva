#include <iostream>
#include <map>
#include <string>

using namespace std;
typedef pair<int, int> ii;

class dset {
  private:
    map<string, int> set_map;
    ii sets[100000];
    int index = 0;
    int findSet(int a) { return (sets[a].first == a) ? a : findSet(sets[a].first); }
    int init(string &a) {
      if (set_map.find(a) == set_map.end()) {
        sets[index] = make_pair(index, 1);
        set_map[a] = index++; 
      }
      return set_map[a];
    }

  public:
    int unionSet(string &a, string &b) {
      int sa = findSet(init(a)), sb = findSet(init(b));
      if (sa != sb) {
        sets[sb].first = sa;
        sets[sa].second += sets[sb].second;
      }
      return sets[sa].second;
    }
};

int main() {
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n;
    dset myset;
    for (int i = 0; i < n; i++) {
      string a, b; cin >> a >> b;
      cout << myset.unionSet(a, b) << endl;
    }
  }
  return 0;
}
