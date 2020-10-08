#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, bags[10001];
bool taken[10001];
vector<vector<int> > ans;

int main() {
  int t = 0;
  while (cin >> n and n) {
    if (t++) cout << endl;
    for (int i = 0; i < n; i++) cin >> bags[i];
    sort(bags, bags + n); 
    bags[n] = -1;
    memset(taken, 0, sizeof(taken));
    ans.clear();


    int numSame = 1, cur = 1;
    for (int i = 1; i <= n; i++) {
      if (bags[i] == bags[i - 1]) cur++;
      else {
        numSame = max(cur, numSame);
        cur = 1;
      }
    }

    cout << numSame << endl;
    for (int i = 0; i < numSame; i++) {
      for (int j = i; j < n; j += numSame) {
        if (i != j) cout << ' ';
        cout << bags[j];
      }
      cout << endl;
    }
  }
  return 0;
}
