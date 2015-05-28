#include <iostream>
#include <string>
#include <algorithm>
#define ll unsigned long long

using namespace std;

ll fac[22];
void fill() { fac[0] = 1; for (int i = 1; i <= 20; i++) fac[i] = fac[i-1]*i; }

int get_ind(int len, ll &rem) {
  if (rem == 0) return 0;
  // cout << "rem " << rem << endl;
  int i = 1;
  for (; i <= len; i++) {
    // cout << "calc " << i*fac[len-1] << endl;
    if (i*fac[len-1] > rem) break;
  }
  rem -= (i-1)*fac[len-1];
  return i-1;
}

void get_perm(string &s, ll perm) {
  for (int i = 0; i < s.size(); i++) {
    sort(s.begin()+i, s.end());
    int j = get_ind(s.size()-i, perm);
    j += i;
    // cout << s << ' ' << perm  << ' ' << j<< endl;
    // cout << "swapping " << i << ' ' << j << endl;

    char t = s[j]; s[j] = s[i]; s[i] = t;
    // cout << j << endl;
  }

  cout << s << endl;
}


int main() {
  fill();
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    ll perm; string let;
    cin >> let >> perm;
    // cout << get_ind(let.size()-1, perm) << endl;
    get_perm(let, perm);
    // sort(let.begin()+2, let.end());
    // cout << let << endl;
  }

  return 0;
}
