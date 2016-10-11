#include <iostream>
#define inf 10e8

using namespace std;

int n, b, h, w, cap[19], weeks[19][14];

bool valid(int hotel) {
  for (int i = 0; i < w; i++) if (weeks[hotel][i] >= n) return true;
  return false;
}

int main() {
  while (cin >> n >> b >> h >> w) {
    for (int i = 0; i < h; i++) {
      cin >> cap[i];
      for (int j = 0; j < w; j++) cin >> weeks[i][j];
    }

    int price = inf;

    for (int i = 0; i < h; i++) {
      if (n * cap[i] <= b and valid(i)) price = min(price, n*cap[i]);
    }

    if (price == inf) cout << "stay home" << endl;
    else cout << price << endl;
  }
  return 0;
}

