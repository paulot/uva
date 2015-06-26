#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <tuple>
#define ll unsigned long long

using namespace std;

typedef tuple<int, int, int> iii;

class comp {
  public:
    bool operator() (iii &lhs, iii &rhs) {
      return get<0>(lhs) > get<0>(rhs);
    }
};

priority_queue<iii, vector<iii>, comp> graph;
int n = 0;
int sets[1000003];

ll kruskals() {
  set<int> available;
  for (int i = 1; i <= n; i++) {
    sets[i] = i; 
    available.insert(i);
  }

  ll cost = 0;
  while (available.size() > 1) {
    iii c = graph.top();
    graph.pop();
    int a = get<1>(c), b = get<2>(c);

    if (sets[a] != sets[b]) {
      cost += get<0>(c);
      int from = max(sets[a], sets[b]), to = min(sets[a], sets[b]);
      for (int i = 1; i <= n; i++) {
        if (sets[i] == from) sets[i] = to;
      }
      available.erase(available.find(from));
    }
  }

  return cost;
}

int main() {
  string null;
  int tc = 0;
  while (cin >> n) {
    if (tc++ != 0) cout << endl;
    graph = priority_queue<iii, vector<iii>, comp>();
    int a, b, c;
    ll tcost = 0;
    for (int i = 0; i < n-1; i++) {
      cin >> a >> b >> c;
      tcost += c;
    }
    cout << tcost << endl;

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
      cin >> a >> b >> c;
      graph.push(make_tuple(c, a, b));
    }

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
      cin >> a >> b >> c;
      graph.push(make_tuple(c, a, b));
    }

    cout << kruskals() << endl; 
  }
  return 0;
}






