#include <iostream>
#include <queue>
#include <string>
#define left 0
#define right 1

using namespace std;

int lens[100000];

int main() {
  int tc; cin >> tc;
  while (tc--) {
    queue<int> cars[2];
    int l, n;
    cin >> l >> n;
    l *= 100;
    for (int i = 0; i < n; i++) {
      string p;
      cin >> lens[i] >> p;
      cars[p == "right"].push(i);
    }

    int trips = 0, pos = left;
    while (not cars[left].empty() or not cars[right].empty()) {
      int len = l;
      while (not cars[pos].empty() and len >= lens[cars[pos].front()]) {
        len -=lens[cars[pos].front()];
        cars[pos].pop();
      }
      pos = (pos+1)%2;
      trips++;
    }
    cout << trips << endl;
  }
  return 0;
}
