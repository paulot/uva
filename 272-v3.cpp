#include <iostream>
#include <cstdio>


using namespace std;

int main() {
  int opend = false, opens = false;
  char c;
  cin.unsetf(ios_base::skipws);
  while (cin >> c) {
    if (c == '"' and not opend) { cout <<  "``"; opend = true; }
    else if (c == '"' and opend) { cout <<  "\'\'"; opend = false; }
    else cout << c;
  }

  return 0;
}
