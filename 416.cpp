#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n;
bool broken[11];
string vals[10] = { "YYYYYYN", "NYYNNNN", "YYNYYNY", "YYYYNNY", "NYYNNYY",
                    "YNYYNYY", "YNYYYYY", "YYYNNNN", "YYYYYYY", "YYYYNYY" };
string countdown[10];

bool canBeVal(string &str, int val) {
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != vals[val][i]) {
      if (str[i] == 'Y') return false;
      else if (str[i] == 'N') broken[i] = true;
    } else {
      if (str[i] == 'Y' and broken[i]) return false;
    }
  }
  return true;
}

bool validCountdown(int start) {
  for (int j = start, i = 0; j >= 0 and i < n; j--, i++) 
    if (not canBeVal(countdown[i], j)) return false;
  return true;
}

int main() {
  while (cin >> n and n) {
    for (int i = 0; i < n; i++) cin >> countdown[i];

    bool solved = false;
    for (int i = n - 1; not solved and i < 10; i++) {
      memset(broken, 0, sizeof(broken));
      if (validCountdown(i)) solved = true;
    }
    cout << ((solved) ? "MATCH" : "MISMATCH") << endl;
  }
  return 0;
}
