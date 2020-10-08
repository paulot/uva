#include <string>
#include <iostream>
#include <sstream>
#define sind 25
#define get(p, i) ((p >> i) % 2)

using namespace std;

int t, n, m, sets[120][26];
string line, ans;

bool possible(int p) {
  for (int i = 0; i < m; i++) {
    int rcount = 0;
    for (int j = 0; j < sets[i][sind]; j++)
      if (get(p, sets[i][j])) rcount++;
    if ((rcount == 0 or rcount == sets[i][sind]) and sets[i][sind] != 1) return false;
  }

  return true;
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    getline(cin, line);
    for (int i = 0; i < m; i++) {
      getline(cin, line);
      stringstream stream(line);
      int j = 0, in;
      while (stream >> in) sets[i][j++] = in - 1;
      sets[i][sind] = j;
    }

    bool solved = false;
    for (int i = 1; i < (2 << (n - 1)); i++) if (possible(i)) { solved = true; break; }
    if (solved) ans += 'Y';
    else ans += 'N';
  }
  cout << ans;
  return 0;
}

/*
    for (int i = 0; i < m; i++) {
    } cout << endl;
    */
