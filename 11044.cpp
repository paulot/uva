#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int n;
  cin >> n;
  for(;n > 0; n--) {
    int a, b;
    cin >> a >> b;
    cout << (int) (ceil((a-2)/3.0) * ceil((b-2)/3.0)) << endl;
  }
  return 0;
}
