#include <iostream>
#include <string>
#include <vector>

using namespace std;

int t, n, ind[40];
string in;
vector<char> ans;

/*
 * The idea for this algorithm is to figure out what is the ending index for each
 * given character. We start from the very end, we know that the character at the
 * very end will be in position (n - 1) % str.size(). From there we insert characters
 * on the answer vector. Frankly, I don't fully understand this.
 */

int main() {
  cin >> t;
  while (t--) {
    cin >> in >> n; n--;
    ans.clear();
    for (int i = in.size(); i > 0; i--) {
      ind[i - 1] = n % i;
      n /= i;
    }

    for (int i = 0; i < in.size(); i++)
      ans.insert(ans.begin() + ind[i], in[i]);

    for (int i = 0; i < ans.size(); i++) cout << ans[i];
    cout << endl;
  }
  return 0;
}
