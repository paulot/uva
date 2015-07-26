#include <iostream>
#include <cmath>
#include <limits.h>
#define N 1025

using namespace std;

/*
 Second option is to attack this problem backwards:
 Create an array int killed[1024][1024].
 For each n rat population at coordinate (x, y),
 add the value of array killed[i][j] with the
 number of rats in (x, y) that will be killed if a bomb is placed in (i, j) 
 and (i, j) is within the
 square-bombing radius (i.e. |i − x| ≤ d and |j − y| ≤ d). 
 This pre-processing takes O(n × d2)
 operations.
 */

int main() {
  int killed[1025][1025], tc; cin >> tc;
  while(tc--) {
    int d, n;
    cin >> d >> n;
    for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      killed[i][j] = 0;

    for (int ii = 0; ii < n; ii++) {
      int x, y, p; cin >> x >> y >> p;
      for (int i = ((x-d < 0) ? 0 : x-d); i < ((x+d > N) ? N : x+d+1); i++)
        for (int j = ((y-d < 0) ? 0 : y-d); j < ((y+d > N) ? N : y+d+1); j++)
          killed[i][j] += p;
    }

    int m = INT_MIN, x = 0, y = 0;

    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (killed[i][j] > m) {
          m = killed[i][j], x = i, y = j;
        }

    cout << x << ' ' << y << ' ' << m << endl;
  }
  return 0;
}
