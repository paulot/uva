#include <iostream>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int t, n, bags[21], sum;
bool dp[201];
string in;

int main() {
  cin >> t;
  getline(cin, in);
  while (t--) {
    memset(dp, 0, sizeof(dp));
    getline(cin, in);
    sum = 0, n = 0;
    stringstream ss(in);
    while (ss >> bags[n]) sum += bags[n], n++;
    n--;
    if (sum % 2 != 0) cout << "NO" << endl;
    else {
      dp[0] = true;
      for (int i = 0; i < n; i++)
        for (int s = sum / 2 - bags[i]; s >= 0; s--)
          if (dp[s]) dp[s + bags[i]] = true;
      cout << ((dp[sum / 2]) ? "YES" : "NO") << endl;
    }
  }
  return 0;
}
