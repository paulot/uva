#include <map>
#include <iostream>
#include <string>

using namespace std;

string orig = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
string actu = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";

int geti(char c) {
  for (int i = 0; i < orig.size(); i++)
    if (orig[i] == c) return i;
  return -1;
}

int main() {
  string in;
  while(getline(cin, in)) {
    for (int i = 0; i < in.size(); i++) {
      if (in[i] == ' ') cout << ' ';
      else cout << actu[geti(in[i])];
      // cout << "goti " << geti(in[i]) << endl;
    }
    cout << endl;
  }

  return 0;
}

