#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;

int main() {
  int tc; cin >> tc;
  string null;
  getline(cin, null); getline(cin, null); 

  while (tc--) {
    map<string, int> count;
    int size = 0;
    while (true) {
      string in; getline(cin, in);
      if (in == "") break;
      count[in]++;
      size++;
    }
    for (auto &it : count) {
      cout << it.first << ' ' << fixed << setprecision(4)
           << (((double) it.second) / size) * 100 << endl;
    }
    if (tc) cout << endl;
  }
  return 0;
}
