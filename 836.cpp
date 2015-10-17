#include <iostream>
#include <string>

using namespace std;

int sum[26][26], n, tc;
string in;

void clear() {
  for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++)
    sum[i][j] = 0;
}

int getMax() {
  int m = 0;

  for(int i0 = 0; i0 < n; i0++) for(int j0 = 0; j0 < n; j0++)
  for(int i1 = i0+1; i1 <= n; i1++) for(int j1 = j0+1; j1 <= n; j1++) {
    int csum = sum[i1][j1] + sum [i0][j0] - sum[i1][j0] - sum[i0][j1];
    if (m < csum and (i1-i0)*(j1-j0) == csum) m = csum;
  }
  
  return m;
}

int main() {
  cin >> tc;
  getline(cin, in); getline(cin, in);
  while (tc--) {
    clear();
    int i = 1;
    while (getline(cin, in)) {
      if (in.empty()) {
        break;
      } else {
        n = in.size();
        for (int j = 1; j <= n; j++) 
          sum[i][j] = in[j-1]-'0' + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        i++;
      }
    }
    cout << getMax() << endl;
    if (tc) cout << endl;
  }
  return 0;
}
