#include <iostream>

using namespace std;

int lengths[20], sum, n, t;
bool took[20], ans[20];

void dfs(int p) {
  if (p == t) {
    int csum = 0;
    for (int i = 0; i < t; i++) if (took[i]) csum += lengths[i];
    if (csum > sum and csum <= n) {
      for (int i = 0; i < t; i++) ans[i] = took[i];
      sum = csum;
    }
    return;
  }
  took[p] = true;
  dfs(p+1);
  took[p] = false;
  dfs(p+1);
}

int main() {
  while (cin >> n >> t) {
    for (int i = 0; i < t; i++) { cin >> lengths[i]; took[i] = false; }
    sum = 0;
    dfs(0);
    for (int i = 0; i < t; i++) if (ans[i]) cout << lengths[i] << ' ';
    cout << "sum:" << sum << endl;
  }
  return 0;
}
