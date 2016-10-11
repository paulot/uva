#include <iostream>

using namespace std;

int a, b, t;

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> b;
    if (a < b) cout << '<' << endl;
    else if (a > b) cout << '>' << endl;
    else if (a == b) cout << '=' << endl;
  }
  return 0;
}
