#include <iostream>
#include <sstream>

using namespace std;

int nums[1001];

int main() {
  int n; cin >> n;
  string str;
  while (n--) {
    int s; cin >> s;
    getline(cin, str);
    
    int gmin = 10e6;
    for (int i = 0; i < s; i++) {
      nums[i] = 0;
      getline(cin, str);
      stringstream stream(str);
      int num;
      while (stream >> num) nums[i]++;
      gmin = min(gmin, nums[i]);
    }

    bool p = false;
    for (int i = 0; i < s; i++) {
      if (nums[i] == gmin) {
        if (p) cout << ' ';
        cout << i + 1;
        p = true;
      }
    }
    cout << endl;
  }
  return 0;
}
