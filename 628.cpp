#include <iostream>
#include <string>

using namespace std;


string words[101], pattern;
int n, np;

void bt(string c, int loc) {
  if (loc == pattern.size()) cout << c << endl;
  else if (pattern[loc] == '0') for (int i = 0; i < 10; i++) bt(c + ((char) ('0' + i)), loc + 1);
  else for (int i = 0; i < n; i++) bt(c + words[i], loc + 1);
}

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> words[i];
    cin >> np; cout << "--" << endl;
    for (int i = 0; i < np; i++) { cin >> pattern; bt("", 0); }
  }
  return 0;
}
