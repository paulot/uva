#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int reduce(int a, int b, int m, int w) {
  int price = 0;
  while (w > m) {
    if (w/2 >= m and (w/2)*a >= b) w /= 2, price += b;
    else w -= 1, price += a;
  }
  return price;
}

typedef pair<string, int> si;


struct comp {
  bool operator()(const si &lhs, const si &rhs) {
    if (lhs.second == rhs.second) return lhs.first < rhs.first;
    return lhs.second < rhs.second;
  }
};

int main() {
  int tc, n, m, l;
  string null;
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    cin >> n >> m >> l;
    getline(cin, null);
    vector<si> ans;
    for (int i = 0; i < l; i++) {
      int a, b; string name, in;
      getline(cin, name, ':');
      getline(cin, in, ','); a = stoi(in);
      getline(cin, in); b = stoi(in);
      ans.push_back(make_pair(name, reduce(a, b, m, n)));
    }

    sort(ans.begin(), ans.end(), comp());

    cout << "Case " << t << endl;
    for (auto &it : ans) {
      cout << it.first << ' ' << it.second << endl;
    }
  }
  return 0;
}


