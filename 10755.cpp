#include <iostream>
#include <cstring>
#include <limits.h>
#define ll long long

using namespace std;

/**
 * The idea when solving this problem is the following:
 * For each garbage piece, we want the value of the piece to be the
 * sum of all the garbage pieces from the origin to that particular piece.
 * So the value of the piece at x, y, z will be the sum of (0,0,0), (0,0,1) ...
 * (x, y, z). Basically representing the cuboid with start at (0,0,0) and end at (x,y,z).
 *
 * Then, it's a matter of iterating through all start and end points and finding the max
 * value. Note that we can fix one of the dimensions and look for endpoints in other dimensions.
 */

int t, X, Y, Z;
ll garbage[22][22][22];

int main() {
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    if (tt) cout << endl;
    cin >> X >> Y >> Z;
    ll maxGarbage = LLONG_MIN;
    for (int x = 1; x <= X; x++)
      for (int y = 1; y <= Y; y++)
        for (int z = 1; z <= Z; z++) {
          cin >> garbage[x][y][z];
          maxGarbage = max(maxGarbage, garbage[x][y][z]);
          garbage[x][y][z] += garbage[x][y-1][z];
          garbage[x][y][z] += garbage[x][y][z-1];
          garbage[x][y][z] -= garbage[x][y-1][z-1];
        }

    if (maxGarbage <= 0) { cout << maxGarbage << endl; continue; }
    ll ans = 0;

    for (int y1 = 1; y1 <= Y; y1++)
      for (int z1 = 1; z1 <= Z; z1++)
        for (int y2= y1; y2 <= Y; y2++)
          for (int z2 = z1; z2 <= Z; z2++) {
            ll cur = 0;
            for (int x = 1; x <= X; x++) {
              ll p = garbage[x][y2][z2] - garbage[x][y1 - 1][z2] - garbage[x][y2][z1 - 1] + garbage[x][y1 - 1][z1 - 1];
              cur = max(0ll, cur + p);
              ans = max(ans, cur);
            }
          }
    cout << ans << endl;
  }
  return 0;
}







      /*
    for (int f = 1; f <= z; f++) {
      for (int j = 1; j <= y; j++) {
        for (int i = 1; i <= x; i++) {
          cout << garbage[f][j][i] << ' ';
        }
        cout << endl;
      }cout << endl;
    }

    cout << endl;
    for (int f = 1; f <= z; f++) {
      for (int j = 1; j <= y; j++) {
        for (int i = 1; i <= x; i++) {
          cout << sum[f][j][i] << ' ';
        }
        cout << endl;;
      }cout << endl;
    }
    */
