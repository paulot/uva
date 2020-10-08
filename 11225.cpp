#include <iostream>
#include <string>

using namespace std;

int nOudlers, points, t, n, needed[4] = { 56, 51, 41, 36 };
string in;

bool isOudler(string &str) {
  return str == "fool" or str == "twenty-one of trumps" or str == "one of trumps";
}

int point(string &str) {
  if (str.find("king") != string::npos or isOudler(str)) return 9;
  if (str.find("queen") != string::npos) return 7;
  if (str.find("knight") != string::npos) return 5;
  if (str.find("jack") != string::npos) return 3;
  return 1;
}

int main() {
  cin >> t;
  for (int tc = 1; tc <= t; tc++) {
    cin >> n;
    nOudlers = points = 0;
    getline(cin, in);
    for (int i = 0; i < n; i++) {
      getline(cin, in);
      points += point(in);
      nOudlers += isOudler(in);
    }
    points /= 2;
    cout << "Hand #" << tc << endl;
    if (points < needed[nOudlers]) cout << "Game lost by " << needed[nOudlers] - points << " point(s)." << endl;
    else cout << "Game won by " << points - needed[nOudlers] << " point(s)." << endl;

    if (tc != t) cout << endl;
  }
  return 0;
}
