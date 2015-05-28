#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main() {
  string null;
  int nt;
  cin >> nt;
  for (;nt > 0; nt--) {
    int n;
    map<char, int> table;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int v;
      char c;
      cin >> c >> v;
      table[c] = v;
    }
    cin >> n;
    getline(cin, null);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      string line;
      getline(cin, line);
      for (int j = 0; j < line.size(); j++) {
        // cout << line[j] << ' ' << table[line[j]] << endl;;
        ans += table[line[j]];
      }
    }
    cout << ans/100 << '.' << setfill('0') << setw(2) << ans%100 << '$' << endl;
  }


  return 0;
}



    
