#include <iostream>
#include <limits.h>

using namespace std;

int moves, bottles[3][3];

void swap(int b, int i, int j) {
  int t = bottles[b][i];
  bottles[b][i] = bottles[b][j];
  bottles[b][j] = t;
}

int main() {
  while (cin >> bottles[0][0] >> bottles[0][1] >> bottles[0][2]) {
    for (int i = 1; i < 3; i++) for (int j = 0; j < 3; j++) cin >> bottles[i][j];
    swap(0, 1, 2);
    swap(1, 1, 2);
    swap(2, 1, 2);

    moves = INT_MAX;
    int picked[3];
    for (int a = 0; a < 3; a++) {
      for (int b = 0; b < 3; b++) { if (a == b) continue;
        for (int c = 0; c < 3; c++) { if (c == b or c == a) continue;
          int cmoves = bottles[1][a] + bottles[2][a] + bottles[0][b] + bottles[2][b] +
                       bottles[0][c] + bottles[1][c];
          if (cmoves < moves) {
            moves = cmoves;
            picked[0] = a; picked[1] = b; picked[2] = c;
          }
        }
      }
    }
    for (int i = 0; i < 3; i++)
      if (picked[i] == 0) cout << 'B';
      else if (picked[i] == 2) cout << 'G';
      else cout << 'C';

    cout << ' ';
    cout << moves << endl;
  }
  return 0;
}
