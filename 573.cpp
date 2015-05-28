#include <iostream>

using namespace std;

void snail(int wh, double ch, int sh, int f) {
  double curh = 0, fatigue = ch * (f/100.0);
  int day = 0;
  do {
    curh += ch;
    ch -= fatigue;
    if (ch < 0) ch = 0;
    day++;
    if (curh > wh) {
      cout << "success on day " << day << endl;
      return;
    }
    curh -= sh;
    // cout << "curh " << curh << " ch " << ch << endl;
    if (curh < 0) {
      cout << "failure on day " << day << endl;
      return;
    }
  } while (true);
}


int main() {
  while (true) {
    int h, u, d, f;
    cin >> h;
    if (h == 0) return 0;
    cin >> u >> d >> f;
    snail(h, u, d, f);
  }
}
