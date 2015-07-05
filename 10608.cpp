#include <iostream>

using namespace std;

int friends[30001], sizes[30001];

int findSet(int a) { while(a != friends[a]) a = friends[a]; return a; }
void unionSet(int a, int b) {
  int sa = findSet(a), sb = findSet(b);
  if (sa != sb) friends[sa] = sb;
}

int main () {
  int tc; cin >> tc;
  while (tc--) {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) friends[i] = i, sizes[i] = 0;

    for (int i = 0; i < m; i++) {
      int a, b; cin >> a >> b; a--; b--;
      unionSet(a, b);
    }

    for (int i = 0; i < n; i++) friends[i] = findSet(i);

    int largest = 0;
    for (int i = 0; i < n; i++) {
      sizes[friends[i]]++;
      largest = max(largest, sizes[friends[i]]);
    }
    cout << ((m) ? largest : 0) << endl;
  }
  return 0;
}




