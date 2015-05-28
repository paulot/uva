#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> ii;

class arr {
  public:
    int base, es;
    vector<ii> D;
    vector<int> doff;
    arr(int, int, vector<ii>&);
    arr(const arr&);
    arr();
    int get_pos(vector<int> &);
    void print();
};

void arr::print() {
  cout << "D : ";
  for (int i = 0; i < D.size(); i++)
    cout << '(' << D[i].first << ',' << D[i].second << "), ";
  cout << endl << "doff : ";

  for (int i = 0; i < doff.size(); i++)
    cout << doff[i] << ", ";
  cout << endl;
}

arr::arr(const arr &a) {
  base = a.base, es = a.es, D = a.D, doff = a.doff;
}

arr::arr(int b, int s, vector<ii> &Ds) {
  D = Ds, base = b, es = s;

  doff.insert(doff.begin(), es);
  for (int i = D.size()-2; i >= 0; i--) {
    doff.insert(doff.begin(), doff[0]*(D[i+1].second - D[i+1].first + 1));
  }
}

int arr::get_pos(vector<int> &c) {
  int ans = 0;
  for (int i = 0; i < c.size(); i++) {
    ans += (c[i]-D[i].first) * doff[i];
  }
  return base + ans;
}

map<string, int> arrs;
vector<arr> bla;
int n, r;


int main() {
  cin >> n >> r;
  for (int i = 0; i < n; i++) {
    string name; int base, es, nd;
    cin >> name >> base >> es >> nd;
    vector<ii> dimensions;
    for (int j = 0; j < nd; j++) {
      int l, u;
      cin >> l >> u;
      dimensions.push_back(make_pair(l, u));
    }
    arr in(base, es, dimensions);
    bla.push_back(in);
    arrs[name] = bla.size()-1;
  }

  for (int i = 0; i < r; i++) {
    vector<int> ds;
    string name;
    cin >> name;
    cout << name << '[';
    for (int j = 0; j < bla[arrs[name]].D.size(); j++) {
      int q; cin >> q;
      ds.push_back(q);
      cout << q;
      if (j == bla[arrs[name]].D.size() - 1)
        cout <<"] = ";
      else cout << ", ";
    }
    cout << bla[arrs[name]].get_pos(ds) << endl;
  }


  /*
  for (auto &it : arrs) {
    cout << it .first << endl;
    bla[it.second].print();
  }
  */



  return 0;
}



