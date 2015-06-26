#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef pair<string, int> si;

bool comp(const si &a, const si &b) {
  if (a.second == b.second) return a.first < b.first;
  return a.second < b.second;
}

int main() {
  int tc; cin >> tc;
  string null;
  getline(cin, null);
  while (tc--) {
    string bname;
    getline(cin, bname);
    //cout << "got binder " << bname << endl;
    int m, n, b;
    cin >> m >> n >> b;
    getline(cin, null);

    map<string, int> prices;
    for (int i = 0; i < m; i++) {
      string in; int num; cin >> in >> num; prices[in] = num;
      getline(cin, null);
      // cout << "got ingredient " << in << endl;
    }

    vector<si> affordable;
    for (int j = 0; j < n; j++) {
      string rname; int rs, price = 0;
      getline(cin, rname);
      // cout << "got recipe " << rname << endl;
      cin >> rs;
      for (int i = 0; i < rs; i++) {
        string in; int nu; cin >> in >> nu;
        getline(cin, null);
        price += prices[in] * nu;
      }
      if (price <= b) affordable.push_back(make_pair(rname, price));
    }

    sort(affordable.begin(), affordable.end(), comp);

    transform(bname.begin(), bname.end(), bname.begin(), ::toupper);
    cout << bname << endl;
    if (affordable.size() == 0) cout << "Too expensive!\n";
    else {
      for (int i = 0; i < affordable.size(); i++) cout << affordable[i].first << endl;
    }
    cout << endl;
  }
}



