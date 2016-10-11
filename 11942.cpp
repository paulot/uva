#include <iostream>
#include <algorithm>

using namespace std;

int arr[10], tc;

int main() {
  cin >> tc;
  cout << "Lumberjacks:" << endl;
  while (tc--) {
    for (int i = 0; i < 10; i++) cin >> arr[i];
    if (is_sorted(arr, arr+10) or is_sorted(arr, arr+10, [](int a, int b) -> bool {
          return a > b;
        })) {
      cout << "Ordered" << endl;
    } else {
      cout << "Unordered" << endl;
    }
  }
  return 0;
}
