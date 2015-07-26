#include <iostream>
#include <string>

using namespace std;
string format;
string dict[100];
int fn, dn;

void dfs(int fi, string str) {
  if (fi == format.size()) {
    cout << str << endl;
    return;
  }

  if (format[fi] == '#') {
    for (int i = 0; i < dn; i++) dfs(fi+1, str+dict[i]);
  } else {
    for (int i = 0; i <= 9; i++) dfs(fi+1, str+((char)(i+'0')));
  }
}

int main() {
  while (cin >> dn) {
    cout << "--\n";
    for (int i = 0; i < dn; i++) cin >> dict[i];
    cin >> fn;
    for (int i = 0; i < fn; i++) {
      cin >> format;
      dfs(0, "");
    }
  }
  return 0;
}


