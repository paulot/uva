#include <iostream>
#include <cstdio>
#include <cctype>
#include <string>

using namespace std;



void reverse(string &s) {
  for (int i = 0; i < s.size()/2; i++) {
    char t = s[i];
    s[i] = s[s.size()-i-1];
    s[s.size()-i-1] = t;
  }
}

int main() {
  int c;
  string s;
  while ((c = getchar()) != EOF) {
    if (not isspace(c)) {
      s += c;
    } else {
      reverse(s); cout << s;
      s = "";
      cout << (char) c;
    }
  }

  return 0;
}


