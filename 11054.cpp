#include <iostream>
#include <cmath>
#define ll unsigned long long

using namespace std;

int arr[100000], n;

int main() {
  int n;
  while (cin >> n and n != 0) {
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll time = 0;
    for (int i = 0; i < n-1; i++) {
      if (arr[i] == 0) continue;
      for (int j = i+1; j < n and arr[i]; j++) {
        if (arr[i] > 0 and arr[j] < 0) {
          if (arr[i] <= abs(arr[j]))
            time += arr[i] * (j-i), arr[j] += arr[i], arr[i] = 0;
          else 
            time += abs(arr[j]) * (j-i), arr[i] += arr[j], arr[j] = 0;
        } else if (arr[i] < 0 and arr[j] > 0) {
          if (abs(arr[i]) <= arr[j])
            time += abs(arr[i]) * (j-i), arr[j] += arr[i], arr[i] = 0;
          else 
            time += arr[j] * (j-i), arr[i] += arr[j], arr[j] = 0;
        }
      }
    }
    cout << time << endl;
  }
  return 0;
}


