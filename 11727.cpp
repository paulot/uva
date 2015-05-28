#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int s[3];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[0] >> s[1] >> s[2];
    sort(begin(s), end(s));
    cout << "Case " << i + 1 << ": " << s[1] << endl;
  }
  return 0;
}
