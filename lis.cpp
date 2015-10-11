#include <iostream>

using namespace std;

int l[100], arr[100], n;

int lis() {
  for (int i = 1; i < n; i++) 
    for (int j = 0; j < i; j++) 
      if (arr[i] > arr[j] and l[i] < l[j]+1)
        l[i] = l[j]+1;

  int m = 0;
  for (int i = 0; i < n; i++) 
    m = max(m, l[i]);
  return m;
}

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> arr[i], l[i] = 1;
    cout << lis() << endl;
  }
  return 0;
}

