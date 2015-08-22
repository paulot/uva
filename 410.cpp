#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int spec[10], s, c, n;
double am;

struct comp {
  bool operator()(const ii &lhs, const ii &rhs) const {
    // return lhs.first+lhs.second > rhs.first+rhs.second;
    return abs(lhs.first + lhs.second - am) < abs(rhs.first + rhs.second - am);
  }
};

int main() {
  int set = 1;
  while (cin >> c >> s) {
    int total = 0;
    double imbalance = 0;
    for (int i = 0; i < s; i++) {
      cin >> spec[i]; total += spec[i];
    }
    for (int i = s; i < 2*c; i++) spec[i] = 0;
    n = 2*c; am = total/((double)c);
    sort(spec, spec+n);

    cout << "Set #" << set++ << endl;
    vector<ii> ans;

    for (int i = 0; i < c; i++) {
      imbalance += abs(spec[i] + spec[n-i-1] - am);
      ans.push_back(make_pair(spec[i], spec[n-i-1]));
    }
    sort(ans.begin(), ans.end(), comp());

    for (int i = 0; i < ans.size(); i++) {
      cout << " " << i << ": ";
      if (ans[i].first != 0) cout << ans[i].first << ' ';
      if (ans[i].second != 0) cout << ans[i].second;
      imbalance += abs(spec[i] + spec[n-i-1] - am);
      cout << endl;
    }
    cout << "IMBALANCE = " << fixed << setprecision(5) <<
      imbalance/2.0 << endl << endl;
  }
  return 0;
}




