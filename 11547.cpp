#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (;n > 0; n--) {
    double t;
    cin >> t;
    cout << (((int) abs((((t*567/9)+7492)*235/47)-498)) % 100)/10 << endl;
  }
  return 0;
}
