#include <iostream>
#include <algorithm>

using namespace std;

int n, r, d, morning[101], evening[101];

int main() {
  while (cin >> n >> d >> r and n and d and r) {
    for (int i = 0; i < n; i++) cin >> morning[i];
    for (int i = 0; i < n; i++) cin >> evening[i];
    sort(morning, morning + n, greater<int>());
    sort(evening, evening + n);

    int overtime = 0;
    for (int i = 0; i < n; i++) 
      if (morning[i] + evening[i] > d) overtime += morning[i] + evening[i] - d;
    cout << overtime * r << endl;
  }
  return 0;
}
