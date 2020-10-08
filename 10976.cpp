#include <iostream>
#include <string>
#include <vector>

using namespace std;

int k, x, y;
vector<string> ans;

int main() {
  while (cin >> k) {
    ans.clear();
    for (int i = k + 1; i <= 2 * k; i++) {
      int b = (i * k) / (i - k);
      if ((i * k) % (i - k) == 0)
        ans.push_back("1/" + to_string(k) + " = 1/" + to_string(b) + " + 1/" + to_string(i));
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  }
  return 0;
}
