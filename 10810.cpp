#include <iostream>
#define ll unsigned long long

using namespace std;
int arr[500000], cparr[500000], n;

ll check() {
  ll ans = 0;
  for (int i = 0; i < n-1; i++)
  for (int j = i+1; j < n; j++)
    if (arr[i] > arr[j]) ans++;
  return ans;
}

ll merge(int s, int e) {
  int as = s;
  int m = (s+e)/2;
  int me = m+1;
  int cp = 0;
  ll ans = 0;
  while(s <= m and me <= e) {
    if (arr[s] <= arr[me]) cparr[cp++] = arr[s++];
    else {
      ans += (m+1) - s;
      cparr[cp++] = arr[me++];
    }
  }
  while(me <= e) cparr[cp++] = arr[me++];
  while(s <= m) cparr[cp++] = arr[s++];
  for (int i = 0; i < cp; i++) arr[as++] = cparr[i];
  return ans;
}

ll ms(int s, int e) {
  if (s >= e) return 0;
  ll m = (s+e)/2;
  ll a1 = ms(s, m), a2 = ms(m+1, e);
  ll a3 = merge(s, e);
  return a1 + a2 + a3;
}

int main() {
  while (true) {
    cin >> n;
    if (n == 0) return 0;
    for (int i = 0; i < n; i++) cin >> arr[i];
    // int ans = check();
    ll a = ms(0, n-1);
    /*
    if (ans != a) {
      cout << "ANSWERS DONT MATCH, GOT " << a << " EXPECTED " << ans << endl;
    }
    */
    cout << a << endl;
  }
}
