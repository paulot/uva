#include <iostream>
#include <string>

using namespace std;

int sets[30];

int findSet(int a) { return (sets[a] == a) ? a : findSet(sets[a]); }

void unionSet(int a, int b) { sets[findSet(a)] = findSet(b); }

int main() {
  int tc; cin >> tc;
  string line;
  getline(cin, line);
  getline(cin, line);
  while (tc--) {
    getline(cin, line);
    int n = line[0] - 'A';
    for (int i = 0; i <= n; i++) sets[i] = i;

    while (getline(cin, line) and not line.empty()) {
      unionSet(line[0]-'A', line[1]-'A');
    }

    int num = 0;
    for (int i = 0; i <= n; i++) if (sets[i] == i) num++;
    cout << num << endl;
    if (tc) cout << endl;
  }
  return 0;
}



