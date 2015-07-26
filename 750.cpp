#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

bool ucol[9];
int row[9];
int tc, sol;

bool is_gucci(int r, int c) {
  for (int i = 1; i <= 8; i++)
    if (row[i] != 0 and r != i and row[i] != c and
        abs(r-i) == abs(c-row[i])) return false;
  return true;
}

void dfs(int r) {
  if (r == 9) {
    // We got an answer
    printf("%2d      ", sol++);
    for (int i = 1; i <= 8; i++) {
      cout << row[i];
      if (i != 8) cout << ' ';
    }
    cout << endl;
    return;
  }
  if (row[r] == 0) {
    for (int c = 1; c <= 8; c++) {
      if (not ucol[c] and is_gucci(r, c)) {
        row[r] = c;
        ucol[c] = true;
        dfs(r+1);
        row[r] = 0;
        ucol[c] = false;
      }
    }
  } else dfs(r+1);
}
int main() {
  int n; cin >> n;
  for (tc = 1; tc <= n; tc++) {
    for (int i = 1; i <= 8; i++) {
      row[i] = 0;
      ucol[i] = false;
    }
    int r, c; cin >> c >> r;
    sol = 1;
    row[r] = c;
    ucol[c] = true;

    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    dfs(1);
    if (tc != n) cout << endl;
  }
  return 0;
}
