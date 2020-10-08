#include <iostream>
#include <set>

using namespace std;

int t, ps[] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}, n, nums[20];
bool taken[20];
set<int> primes(ps, ps + 16);

void solve(int c) {
  if (c == n) {
    if (primes.find(nums[n-1] + nums[0]) != primes.end()) {
      for (int i = 0; i < n; i++) {
        cout << nums[i];
        if (i != n - 1) cout << ' ';
      } cout << endl;
    }
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (not taken[i] and primes.find(i + nums[c - 1]) != primes.end()) {
      taken[i] = true;
      nums[c] = i;
      solve(c + 1);
      taken[i] = false;
    }
  }
}

int main() {
  nums[0] = 1; taken[1] = true;
  while (cin >> n) { t++;
    if (t != 1) cout << endl;
    cout << "Case " << t << ":" << endl;
    solve(1);
  }
  return 0;
}
