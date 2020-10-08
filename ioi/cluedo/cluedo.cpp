#include <iostream>

#include "grader.h"
#include "cluedo.h"


static bool ww[11] = {1,1,1,1,1,1,1,1,1,1,1}, ll[11] = {1,1,1,1,1,1,1,1,1,1,1};

void Solve() {
  int r;
  for (int m = 1; m <= 6;) {
    bool bypass = false;
    for (int l = 1; m <= 6 && l <= 10 && !bypass;) {
      if (!ll[l]) {
        ++l;
        continue;
      }
      for (int w = 1; m <= 6 && l <= 10 && w <= 6 && !bypass;) {
        if (!ww[w]) {
          ++w;
          continue;
        }
        r = Theory(m, l, w);

        if (r == 3) {
          ww[w] = false;
        }

        if (r == 2) {
          ll[l] = false;
          break;
        }

        if (r == 1) {
          bypass = true;
          break;
        }

        if (r == 0) {
          for (int i = 0; i < 11; ++i) {
            ww[i] = true;
            ll[i] = true;
          }
          return;
        }
        ++w;
      }
      ++l;
    }
    ++m;
  }
}
