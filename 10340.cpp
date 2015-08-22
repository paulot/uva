#include <iostream>
#include <string>

using namespace std;

int main() {
  string s1, s2;
  while (cin >> s1 >> s2) {
    int j = 0;
    bool ok = true;
    for (int i = 0; i < s1.size(); i++) {
      while (s1[i] != s2[j] and j < s2.size()) j++;
      if (s1[i] != s2[j]) {
        ok = false;
        break;
      } else {
        j++;
      }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}

  
