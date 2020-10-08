#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;

int row[9], tc, placed, soln = 1, sc, sr;

bool canPlace(int c, int r) {
  if (row[c] != 0) return false; // There is something already in that column
  // Check if row is clear
  for (int i = 1; i <= 8; i++)
    if (row[i] != 0 and (row[i] == r or abs(r - row[i]) == abs(c - i))) return false;
  return true;
}

void place(int col) {
  if (placed == 8) {
    printf("%2d      ", soln++); for (int i = 1; i <= 8; i++) { cout << row[i]; if (i != 8) cout << ' '; }
    cout << endl;
  } else if (col == sc) place(col + 1);
  else {
    for (int r = 1; r <= 8; r++)
      if (canPlace(col, r)) {
        placed++;
        row[col] = r;
        place(col + 1);
        row[col] = 0;
        placed--;
      }
  }
}

int main() {
  cin >> tc;
  while (tc--) {
    soln = placed = 1;
    cin >> sr >> sc;
    row[sc] = sr;
    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
    place(1);
    if (tc != 0) cout << endl;
    memset(row, 0, sizeof(row));
    /*
    for (int i = 1; i <= 8; i++) cout << row[i] << endl;
    for (int i = 1; i <= 8; i++) {
      for (int j = 1; j <= 8; j++)
        cout << canPlace(i, j) << ' ';
      cout << endl;
    }
    */
  }
  return 0;
}
