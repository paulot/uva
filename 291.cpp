#include <iostream>
#include <string>

using namespace std;

bool con[6][6] = {{0,0,0,0,0,0},
                  {0,0,1,1,0,1},
                  {0,1,0,1,0,1},
                  {0,1,1,0,1,1},
                  {0,0,0,1,0,1},
                  {0,1,1,1,1,0}};
bool sel[6][6];

bool done() {
  for (int i = 1; i < 6; i++)
  for (int j = 1; j < 6; j++)
    if (i != j and not sel[i][j]) return false;
  return true;
}


void branch(int start, string ans) {
  if (done()) { cout << ans << endl; return; }

  for (int i = 1; i < 6; i++) {
    if (i != start and con[start][i] and not sel[start][i]) {
      sel[start][i] = true;
      sel[i][start] = true;
      branch(i, ans + (char) (i + '0'));
      sel[i][start] = false;
      sel[start][i] = false;
    }
  }
}

int main() {
  for (int i = 0; i < 6; i++)
  for (int j = 0; j < 6; j++)
    sel[i][j] = not con[i][j];
  string s = "1";
  branch(1, s);
  // done();
  return 0;
}


