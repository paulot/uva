#include <queue>
#include <iostream>
#include <string>
#include <cmath>
#define left 0
#define right 1

using namespace std;

typedef pair<int, int> ii;

queue<ii> cars[2];
int ans[10001];
int pos, curtime;
int cap, t, nc;

void switch_side() {
  pos = abs(pos-1);
  curtime += t;
}

void pop_cars() {
  int ccar = (cars[left].empty()) ? cars[right].front().first :
             (cars[right].empty()) ? cars[left].front().first :
             min(cars[left].front().first, cars[right].front().first);
  curtime = max(ccar, curtime);

  for (int i = 0; (not cars[pos].empty()) and i < cap and curtime >= cars[pos].front().first; i++) {
    ans[cars[pos].front().second] = curtime + t;
    cars[pos].pop();
  }
  switch_side();
}

int main() {
  int n; cin >> n;
  while (n--) {
    cin >> cap >> t >> nc;

    cars[left]= queue<ii>();
    cars[right] = queue<ii>();
    for (int i = 0; i < nc; i++) {
      int at; string p;
      cin >> at >> p;
      if (p == "left") cars[left].push(make_pair(at, i));
      else cars[right].push(make_pair(at, i));
    }

    pos = left, curtime = 0;
    while (not cars[left].empty() or not cars[right].empty()) pop_cars();

    for (int i = 0; i < nc; i++) cout << ans[i] << endl;
    if (n) cout << endl;
  }
}
