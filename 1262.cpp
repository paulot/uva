#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;


int k, t;
set<string> ans;
bool present[5][30];
char cols[5][6], pass[5];
string in;

bool solve(int col) {
  if (col == 5) {
    in = "";
    for (int i = 0; i < 5; i++) in += pass[i];
    ans.insert(in);
    if (k == ans.size()) return true;
    return false;
  }

  for (int i = 0; i < 6; i++) {
    char cur = cols[col][i];

    if (present[col][cur - 'A']) {
      pass[col] = cur;
      if (solve(col + 1)) return true;
    }
  }
  return false;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> k;
    ans.clear();
    memset(present, 0, sizeof(present));
    for (int i = 0; i < 6; i++) {
      cin >> in;
      for (int j = 0; j < 5; j++)
        present[j][in[j] - 'A'] = true;
    }

    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 5; j++) cin >> cols[j][i];

    for (int i = 0; i < 5; i++) sort(cols[i], cols[i] + 6);

    if (solve(0))
      for (int i = 0; i < 5; i++) cout << pass[i];
    else cout << "NO";
    cout << endl;
  }
  return 0;
}
