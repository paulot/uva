#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

set<int> a, b, r1, r2;
int n, m, in;

int main() {
  while (cin >> n >> m and (n != 0 or m != 0)) {
    a.clear(); b.clear(); r1.clear(); r2.clear();
    for (int i = 0; i < n; i++) { cin >> in; a.insert(in); } 
    for (int i = 0; i < m; i++) { cin >> in; b.insert(in); } 
    // a - b
    set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(r1, r1.end()));
    // b - a
    set_difference(b.begin(), b.end(), a.begin(), a.end(), inserter(r2, r2.end()));
    cout << min(r1.size(), r2.size()) << endl;
  }
  return 0;
}
