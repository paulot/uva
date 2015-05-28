#include <iostream>

using namespace std;


int main() {
  int w, h, n;
  while (true) { cin >> w >> h >> n;
    bool field[501][501];

    if (w == 0 and h == 0 and n == 0) return 0;
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        field[i][j] = true;
      }
    }


    for (; n > 0; n--) {
      int x1,y1,x2,y2,tx1,ty1,tx2,ty2;
      cin >> tx1 >> ty1 >> tx2 >> ty2;
      x1 = min(tx1,tx2); y1 = min(ty1,ty2);
      x2 = max(tx1,tx2); y2 = max(ty1,ty2);

      for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
          field[i][j] = false;
        }
      }
    }

    int ans = 0;
    for (int i = 1; i <= h; i++)
    for (int j = 1; j <= w; j++)
      if (field[i][j]) ans++;

    if (ans == 0) cout << "There is no empty spots." << endl;
    else if (ans == 1) cout << "There is one empty spot." << endl;
    else cout << "There are " << ans << " empty spots." << endl;
  }
  return 0;
}

