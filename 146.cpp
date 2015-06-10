#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  string s;
  while (true) {
    cin >> s;
    string c = s;
    if (s[0] == '#') return 0;
    next_permutation(s.begin(), s.end());
    if (c >= s) cout << "No Successor" << endl;
    else cout << s << endl;
  }
}
