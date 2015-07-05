#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int set[10000];
int findSet(int a) { return (set[a] == a) ? a : findSet(set[a]); }
void unionSet(int a, int b) { set[findSet(a)] = findSet(b); }
bool isConnected(int a, int b) { return findSet(a) == findSet(b); }

int main() {
  string line;
  int tc; cin >> tc;
  while (tc--) {
    int n; cin >> n; getline(cin, line);
    for (int i = 0; i <= n; i++) set[i] = i;
    char op; int a, b, s = 0, f = 0;
    
    while (getline(cin, line) and not line.empty()) {
      stringstream stream(line); stream >> op >> a >> b;
      if (op == 'q') { 
        if (isConnected(a, b)) s++;
        else f++;
      } else unionSet(a, b);
    }
    cout << s << "," << f << endl;
    if (tc) cout << endl;
  }
  return 0;
}
