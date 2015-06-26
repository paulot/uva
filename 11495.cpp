#include <iostream>

using namespace std;

int arr[100001], cp[100001], n;


int merge(int start, int end) {
  int m = (start+end)/2, mi = m+1;
  int s = start, e = end, c = 0;
  int ans = 0;

  while (s <= m and mi <= e) {
    if (arr[s] <= arr[mi]) cp[c++] = arr[s++];
    else {
      ans += (m+1)-s;
      ans %= 2;
      cp[c++] = arr[mi++];
    }
  }
  while (s <= m) cp[c++] = arr[s++];
  while (mi <= e) cp[c++] = arr[mi++];
  s = start;
  for (int i = 0; i < (end-start)+1; i++) arr[s++] = cp[i];
  return ans;
}

      

int ms(int s, int e) {
  if (s >= e) return 0;
  int mid = (s+e)/2;
  int a1 = ms(s,mid), a2 = ms(mid+1, e);
  int a3 = merge(s, e);
  return (a1 + a2 + a3)%2;
}

int main() {
  while(true) {
    cin >> n;
    if (n == 0) return 0;
    for (int i = 0; i < n; i++) cin >> arr[i];
    // cout << ms(0, n-1) << endl;
    cout << ((ms(0, n-1)) ? "Marcelo" : "Carlos") << endl;
  }
}
