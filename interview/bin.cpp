#include <string>
#include <iostream>

using namespace std;

string bin(int n) {
  string ans = "";
  
  while (n) {
    ans = ((n % 2 == 1) ? '1' : '0') + ans;
    n >>= 1;
    n &= ~(1 << 31);
  }
  return ans;
}

int main() {
  for (int i = -10; i < 50; i++) {
    cout << bin(i) << endl;
  }
  return 0;
}
