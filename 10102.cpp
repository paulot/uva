#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

char grid[1000][1000];
int m, in;

int main() {
  while (cin >> m) {
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) cin >> grid[i][j];

    int best = 0;
    for (int si = 0; si < m; si++) for (int sj = 0; sj < m; sj++) {
      if (grid[si][sj] == '1') {
        int mdist = 999999999;
        for (int ei = 0; ei < m; ei++) for (int ej = 0; ej < m; ej++) {
          if (grid[ei][ej] == '3') mdist = min(mdist, abs(ei - si) + abs(ej - sj));
        }
        best = max(best, mdist);
      }
    }
    cout << best << endl;
  }
  return 0;
}
