#include <iostream>
#include <cstring>

using namespace std;

int spaces, n, first, last, pieces[15][2], tmp;
bool taken[15];

bool canSolve(int filled, int matching) {
  if (filled == spaces) {
    if (matching == last) return true;
    else return false;
  }

  for (int i = 0; i < n; i++) {
    if (not taken[i] and (pieces[i][0] == matching or pieces[i][1] == matching)) {
      int toMatch = (pieces[i][0] == matching) ? pieces[i][1] : pieces[i][0];
      taken[i] = true;
      if (canSolve(filled + 1, toMatch)) return true;
      taken[i] = false;
    }
  }

  return false;
}

int main() {
  while (cin >> spaces and spaces) {
    cin >> n;
    cin >> tmp >> first;
    cin >> last >> tmp;
    memset(taken, 0, sizeof(taken));
    for (int i = 0; i < n; i++) cin >> pieces[i][0] >> pieces[i][1];
    cout << ((canSolve(0, first)) ? "YES" : "NO") << endl;
  }
  return 0;
}
