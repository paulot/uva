#include <iostream>
#include <algorithm>

using namespace std;

int lisup[100000], lisdown[100000], dpup[100000], dpdown[100000], arr[100000], n;
int lenup, lendown;

int main() {
  while (cin >> n) {
    for (int i = 1; i <= n; i++) cin >> arr[i], dpup[i] = dpdown[i] = 0;
    lenup = 0, lendown = 0;
    for (int i = 1; i <= n; i++) {
      int place = lower_bound(dpup+1, dpup+lenup+1, arr[i]) - dpup;
      dpup[place] = arr[i]; lisup[i] = place;
      lenup = max(lenup, place);
    }

    for (int i = n; i >= 1; i--) {
      int place = lower_bound(dpdown+1, dpdown+lendown+1, arr[i]) - dpdown;
      dpdown[place] = arr[i]; lisdown[i] = place;
      lendown = max(lendown, place);
    }

    int len = 1;
    for (int i = 1; i <= n; i++) {
      int candidate = (min(lisdown[i], lisup[i]) > 1) ?
        min(lisdown[i], lisup[i]) * 2 - 1 :
        1;
      len = max(len, candidate);
    }

    cout << len << endl;
  }
}
