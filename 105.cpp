#include <iostream>
#include <cstring>

using namespace std;

int heights[10002], big, n, l, h, r;

int main() {
  memset(heights, 0, sizeof(heights));
  while (cin >> l >> h >> r) { n++;
    big = max(big, r);
    for (int i = l; i < r; i++) heights[i] = max(heights[i], h);
  }
  int lh = 0;
  for (int i = 0; i < big;) {
    while (heights[i] == lh and i <= big) i++;

    cout << i << ' ';
    lh = heights[i];
    cout << lh;
    if (i != big) cout << ' ';
  }
  cout << endl;

  // for (int i = 0; i <= big; i++) cout << i << ' ' << heights[i] << endl;


  return 0;
}
