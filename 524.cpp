#include <iostream>
#include <cmath>

using namespace std;

int nums[17];
bool used[17];
int n;

bool is_prime(int num) {
  for (int i = 2; i <= sqrt(num)+1; i++) if (num % i == 0) return false;
  return num != 0;
}

void dfs(int p) {
  if (p == n-1 and is_prime(nums[0]+nums[p])) {
    for (int i = 0; i < n; i++) { cout << nums[i]; if (i != n-1) cout << ' '; }
    cout << endl;
    return;
  } else if (p+1 < n) {
    for (int i = 2; i <= n; i++) {
      if (not used[i] and is_prime(i + nums[p])) {
        used[i] = true;
        nums[p+1] = i;
        dfs(p+1);
        used[i] = false;
      }
    }
  }
}

int main() {
  int tc = 1;
  while (cin >> n) {
    if (tc != 1) cout << endl;
    for (int i = 0; i <= n; i++) used[i] = false;
    cout << "Case " << tc++ << ':' << endl;
    nums[0] = 1;
    dfs(0);
    if (n == 1) cout << 1 << endl;
  }
  return 0;
}
