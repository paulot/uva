#include <iostream>

using namespace std;

int up[100000], down[100000], arr[100000], n;

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> arr[i];
    int start = 0; up[0] = start;
    for (int i = 1; i < n; i++) {
      if (arr[i] > arr[i-1]) {
        up[i] = start;
      } else {
        start = i;
        up[i] = i;
      }
    }
    start = n-1; down[((n >= 1) ? n-1 : 0)] = start;
    for (int i = n-2; i >= 0; i--) {
      if (arr[i] > arr[i+1]) {
        down[i] = start;
      } else {
        start = i;
        down[i] = i;
      }
    }
    for (int i = 0; i < n; i++) cout << up[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++) cout << down[i] << ' ';
    cout << endl;
    int len = 1;
    for (int i = 0; i < n; i++) {
      int lup = i - up[i];
      int ldown = down[i] - i;
      int candidate = (min(lup, ldown) > 1) ? min(lup, ldown) * 2 + 1 : 1;
      len = max(len, candidate);
    }
    cout << len << endl;
  }
  return 0;
}
