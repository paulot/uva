#include <iostream>
#include <cstdio>
#include <limits.h>

using namespace std;

char bins[100][5];
char chars[150];

int get_min(int n) {
  int ind = 0, changes = INT_MAX;
  for (int i = 0; i < n; i++) {
    int cchanges = 0;
    for (int j = 0; j < n; j++) {
      for (int ii = 0; ii < 5; ii++) if (bins[i][ii] != bins[j][ii]) cchanges++;
    }
    if (cchanges < changes) {
      changes = cchanges;
      ind = i;
    }
  }
  return ind;
}

int main() {
  char c1, c2, c3, c4, c5, w1, w2, w3, w4, w5;
  while(true) {
    int city = 0;
    while(scanf("%c/%c,%c/%c,%c/%c,%c/%c,%c/%c\n",
          &c1, &w1, &c2, &w2, &c3, &w3, &c4, &w4, &c5, &w5) == 10) {
      chars[c1] = w1; chars[c2] = w2; chars[c3] = w3; chars[c4] = w4; chars[c5] = w5;
      bins[city][0] = chars['r']; bins[city][1] = chars['o'];
      bins[city][2] = chars['y']; bins[city][3] = chars['g'];
      bins[city][4] = chars['b'];
      city++;
    }
    if (c1 == 'e') cout << get_min(city) + 1 << endl;
    if (c1 == '#') return 0;
  }
}
