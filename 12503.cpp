#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main() {
  int tc, n, ins[101];
  cin >> tc;
  while (tc--) {
    cin >> n; memset(ins, 0, sizeof(ins));
    int pos = 0;

    for (int i = 1; i <= n; i++) {
      string in;
      cin >> in;
      if (in == "LEFT") pos--, ins[i] = -1; 
      else if (in == "RIGHT") pos++, ins[i] = 1;
      else { int j; cin >> in >> j; pos += ins[j]; ins[i] = ins[j]; }
    }
    cout << pos << endl;
  }
  return 0;
}
