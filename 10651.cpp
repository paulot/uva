#include <iostream>
#include <string>
#include <cstring>
#define n 12
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define SET_BIT(var, pos) (var |= (1<<(pos)))

using namespace std;

bool can_move_left(int pos, int board) {
  if (pos < 2) return false;
  return CHECK_BIT(board, pos) and CHECK_BIT(board, pos-1) 
    and !CHECK_BIT(board, pos-2);
}

bool can_move_right(int pos, int board) {
  if (pos > n-3) return false;
  return CHECK_BIT(board, pos) and CHECK_BIT(board, pos+1) 
    and !CHECK_BIT(board, pos+2);
}

int move_right(int pos, int board) {
  board &= ~(1 << pos); // Clear the pos marble
  board &= ~(1 << (pos+1)); // Clear the removed marble
  board |= 1 << (pos+2); // Set the new position of the marble
  return board;
}

int move_left(int pos, int board) {
  board &= ~(1 << pos); // Clear the pos marble
  board &= ~(1 << (pos-1)); // Clear the removed marble
  board |= 1 << (pos-2); // Set the new position of the marble
  return board;
}

/**
 * The idea behind this problem is to do a complete search on the
 * solution space. Meaning, for every pebble in the input, we check if it can be moved.
 * If so, we find the number of moves in the new board configuration (after the move
 * was made). I added a memo array so we dont need to re-compute values, but that's
 * not needed for a passing solution.
 */

int tc, board, peb, dp[1<<n];

int solve(int board) {
  // for each board position, try to move right and try to move left
  // return the min of all moves
  if (dp[board] != -1) return dp[board];

  int m = 0;
  for (int i = 0; i < n; i++)
    if (can_move_right(i, board)) m = max(m, 1 + solve(move_right(i, board)));
    else if (can_move_left(i, board)) m = max(m, 1 + solve(move_left(i, board)));
  return dp[board] = m;
}

int main() {
  cin >> tc;
  while (tc--) {
    string in; cin >> in;
    peb = board = 0;
    memset(dp, -1, sizeof dp);
    for (int i = 0; i < in.size(); i++)
      if (in[i] == 'o') board |= 1 << i, peb++;
    cout << peb - solve(board) << endl;
  }
  return 0;
}
