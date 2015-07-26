#include <iostream>

using namespace std;

int nums[49], n;

int main() {
  int t = 0;
  while (cin >> n) {
    if (n != 0 and t++ != 0) cout << endl;
    for (int i = 0; i < n; i++) cin >> nums[i];

    for (int i1 = 0; i1 < n-5; i1++)
    for (int i2 = i1+1; i2 < n-4; i2++)
    for (int i3 = i2+1; i3 < n-3; i3++)
    for (int i4 = i3+1; i4 < n-2; i4++)
    for (int i5 = i4+1; i5 < n-1; i5++)
    for (int i6 = i5+1; i6 < n; i6++)
      cout << nums[i1] << ' ' << nums[i2] << ' ' << nums[i3] << ' '
           << nums[i4] << ' ' << nums[i5] << ' ' << nums[i6] << endl;
  }
  return 0;
}
