#include <iostream>

using namespace std;

enum cell {empty = 0, rook, wall};

int board[4][4], n;

bool can_place(int i, int j) {
  if (board[i][j] != empty) return false;
  int row = j+1;
  while (board[i][row] != wall and row < n) if (board[i][row++] == rook) return false;
  row = j-1;
  while (board[i][row] != wall and row >= 0) if (board[i][row--] == rook) return false;
  int col = i+1;
  while (board[col][j] != wall and col < n) if (board[col++][j] == rook) return false;
  col = i-1;
  while (board[col][j] != wall and col >= 0) if (board[col--][j] == rook) return false;
  return true;
}

int place() {
  int max_rooks = 0;
  for (int i = 0; i < n; i++)
  for (int j = 0; j < n; j++)
    if (can_place(i, j)) {
      board[i][j] = rook;
      int rooks = 1 + place();
      max_rooks = max(max_rooks, rooks);
      board[i][j] = empty;
    }
  return max_rooks;
}

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      char in; cin >> in;
      board[i][j] = (in == '.') ? empty : wall;
    }
    /*
    for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++) {
      cout << board[i][j] << ' ';
    } cout << endl;}
    */

    if (n != 0)
      cout << place() << endl;
  }
  return 0;
}
