#include <iostream>

using namespace std;

int main() {
  int n;
  while (true) {
    cin >> n;
    if (n == 0) return 0;
    int in;
    int arr[101];
    for (int i = 0; i < 101; i++) arr[i] = 0;

    int mi = 0;
    for (int i = 0; i < n; i++) {
      cin >> in;
      arr[in]++;
      mi = max(mi, in);
    }

    for (int i = 0; i < 101; i++) {
      while (arr[i]) {
        cout << i;
        arr[i]--;
        if (not arr[i] and i == mi){} else cout << ' ';
      }
    }
    cout << endl;
  }
}
