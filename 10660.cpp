#include <iostream>
#include <cstring>
#include <limits.h>
#include <cstdlib>
#define getr(n) (n / 5)
#define getc(n) (n % 5)

using namespace std;

int pop[25][25], a, b, c, t, n;

int dist(int f, int s) {
  return (abs(getr(f) - getr(s)) + abs(getc(f) - getc(s)));
}

int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    memset(pop, 0, sizeof(pop));
    for (int i = 0; i < n; i++) { cin >> a >> b >> c; pop[a][b] = c; }

    int best[5], bestDist = INT_MAX;

    for (int a = 0; a < 25; a++) for (int b = a + 1; b < 25; b++)
    for (int c = b + 1; c < 25; c++) for (int d = c + 1; d < 25; d++)
    for (int e = d + 1; e < 25; e++) {
      int cur = 0;
      for (int i = 0; i < 25; i++) { 
        int minDist = min(min(min(dist(i, a), dist(i, b)), min(dist(i, c), dist(i, d))), dist(i, e));
        cur += minDist * pop[getr(i)][getc(i)];
      }

      if (cur < bestDist) {
        bestDist = cur;
        best[0] = a; best[1] = b; best[2] = c; best[3] = d; best[4] = e;
      }
    }

    for (int i = 0; i < 5; i++) { cout << best[i]; if (i != 4) cout << ' '; }
    cout << endl;
  }
  return 0;
}
