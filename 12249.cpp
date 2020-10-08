#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int t, n, order[10];
string scenes[10], best, cur;

void merge(string &suffix) {
  for (int i = min(suffix.size(), cur.size()); i > 0; i--) {
    int j = cur.size() - i, y = 0;
    while (j < cur.size() and y < suffix.size() and cur[j] == suffix[y]) j++, y++;

    if (j == cur.size()){
      cur = cur.substr(0, cur.size() - i) + suffix;
      return;
    }
  }

  cur += suffix;
}

int main() {
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cin >> n;
    best = "";
    for (int i = 0; i < n; i++) cin >> scenes[i];
    for (int i = 0; i < n; i++) order[i] = i;

    do {
      cur = "";
      for (int i = 0; i < n; i++) merge(scenes[order[i]]);
      if (best == "" or cur.size() < best.size()) best = cur;
    } while (next_permutation(order, order + n));

    cout << "Case " << tt << ": " << best.size() << endl;
  }
  return 0;
}
