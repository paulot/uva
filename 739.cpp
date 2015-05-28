#include <iostream>

using namespace std;

int get_code(char c) {
  switch (c) {
    case 'B': case 'P': case 'F': case 'V': 
      return 1;
    case 'C': case 'S': case 'K': case 'G': case 'J': case 'Q': case 'X': case 'Z':
      return 2;
    case 'D': case 'T':
      return 3;
    case 'L':
      return 4;
    case 'M': case 'N':
      return 5;
    case 'R':
      return 6;
    default:
      return -1;
  }
}

string encode(string &s) {
  string ans;
  for (int i = 1; i < s.size(); i++) {
    int c = get_code(s[i]);
    if (get_code(s[i]) == get_code(s[i-1]) or c == -1) continue;
    ans += c+'0';
  }
  if (ans.size() < 3) {
    int cs = ans.size();
    for (int i = 0; i < 3-cs; i++) ans += '0';
  } else {
    ans.resize(3);
  }
  string a = s[0]+ans;
  return a;
}

int main() {
  string bla;
  printf("%9s%s%21s%s\n", "", "NAME", "", "SOUNDEX CODE");
  while (cin >> bla) printf("%9s%s%*s%s\n", "", bla.c_str(), (35-10-bla.size()), "", encode(bla).c_str());
  cout << "                   END OF OUTPUT" << endl;

  return 0;
}
