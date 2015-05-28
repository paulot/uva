#include <iostream>
#include <string>

using namespace std;

string board[3];

bool is_valid() {
  
  int ow = 0, xw = 0, nx = 0, no = 0;
  for (int i = 0; i < 3; i++) {
    xw += (board[i] == "XXX") ? 1 : 0; 
    ow += (board[i] == "OOO") ? 1 : 0;
    xw += (board[i][0] == 'X' and board[i][1] == 'X' and board[i][2] == 'X') ? 1 : 0;
    ow += (board[i][0] == 'O' and board[i][1] == 'O' and board[i][2] == 'O') ? 1 : 0;
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == 'X') nx++;
      if (board[i][j] == 'O') no++;
    }
  }

  ow += (board[0][0] == 'O' and board[1][1] == 'O' and board[2][2] == 'O') ? 1 : 0;
  ow += (board[0][2] == 'O' and board[1][1] == 'O' and board[2][0] == 'O') ? 1 : 0;
  xw += (board[0][0] == 'X' and board[1][1] == 'X' and board[2][2] == 'X') ? 1 : 0;
  xw += (board[0][2] == 'X' and board[1][1] == 'X' and board[2][0] == 'X') ? 1 : 0;

  if (no > nx) return false;
  if (xw >= 1 and ow >= 1) return false;
  if (xw >= 1 and no >= nx) return false;
  if (ow >= 1 and nx != no) return false;

  if (xw > 0 and no + 1 == nx) return true;
  if (ow > 0 and nx == no) return true;
  if (nx == no or nx == no + 1) return true;

  return false;
}

int main() {
  int n;
  cin >> n;
  for (;n > 0; n--) {
    for (int i = 0; i < 3; i++) cin >> board[i];
    cout << ((is_valid()) ? "yes" : "no") << endl;
  }

  return 0;
}



