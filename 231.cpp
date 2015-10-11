#include <iostream>

using namespace std;

int mis[100000], lis[100000], n;

int main() {
  int in, tc = 1;
  while (cin >> in and in != -1) {
    if (tc != 1) cout << endl;
    int n = 0; mis[n] = in; lis[n++] = 1;
    while (cin >> in and in != -1)
      mis[n] = in, lis[n++] = 1;

    int m = 1;
    for (int i = 1; i < n; i++)
      for (int j = 0; j < i; j++)
        if (mis[i] <= mis[j] and lis[i] < lis[j]+1)
          lis[i] = lis[j]+1, m = max(lis[i], m);

    cout << "Test #" << tc++ << ':' << endl;
    cout << "  maximum possible interceptions: " << m << endl;
  }
  return 0;
}

