#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> shags;

int main() {
  int n;
  cin >> n;

  string country, null;
  for (;n > 0; n--) {
    cin >> country;
    shags[country]++;
    getline(cin, null);
  }
  for (auto &it : shags)
    cout << it.first << ' ' << it.second << endl;
  return 0;
}

