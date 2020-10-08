#include <string>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;

int in, t, n, m, sets[120];
string line;

int main() {
  for (cin >> t; t--;) {
    cin >> n >> m;
    getline(cin, line);
    memset(sets, 0, sizeof(sets));
    for (int i = 0; i < m; i++) {
      getline(cin, line);
      stringstream stream(line);
      while (stream >> in) sets[i] |= 1 << (in - 1);
    }

    bool solved = false;
    for (int i = 1; i < (2 << (n - 1)) and not solved; i++) {
      bool valid = true;
      for (int j = 0; j < m and valid; j++) 
        valid &= ((i & sets[j]) != 0 and (i & sets[j]) != sets[j]) or __builtin_popcount(sets[j]) == 1;
      solved |= valid;
    }

    putchar((solved) ? 'Y' : 'N');
  }
  return 0;
}
