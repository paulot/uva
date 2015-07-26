#include <iostream>
#include <limits.h>

using namespace std;

bool t_to_r[20][20], r_to_h[20][20], h_to_t[20][20];
int travel[20], rest[20], hotel[20];

int main() {
  int t, r, h;
  while(cin >> t >> r >> h) {
    for (int i = 0; i < t; i++) {
      cin >> travel[i];
      for (int j = 0; j < r; j++) {
        cin >> t_to_r[i][j];
      }
    }
    for (int i = 0; i < r; i++) {
      cin >> rest[i];
      for (int j = 0; j < h; j++)
        cin >> r_to_h[i][j];
    }
    for (int i = 0; i < h; i++) {
      cin >> hotel[i];
      for (int j = 0; j < t; j++)
        cin >> h_to_t[i][j];
    }

    int mt, mr, mh, mp = INT_MAX;
    for (int it = 0; it < t; it++)
    for (int ir = 0; ir < r; ir++)
    for (int ih = 0; ih < h; ih++)
      if (not t_to_r[it][ir] and not r_to_h[ir][ih] and not h_to_t[ih][it] and
          (travel[it] + rest[ir] + hotel[ih] < mp)) {
        mp = travel[it] + rest[ir] + hotel[ih];
        mt = it, mr = ir, mh = ih;
      }
    if (mp != INT_MAX) cout << mt << ' ' << mr << ' ' << mh << ":" << mp << endl;
    else cout << "Don\'t get married!\n";
  }
  return 0;
}
