#include <iostream>
#include <cmath>

using namespace std;

int count(int digits[], int num) {
  int n = 0;
  while(num) { digits[num%10]++;
    if (digits[num%10] > 1) return 0;
    num /= 10; n++;
  }
  return n;
}

int validate(int a, int b) {
  int digits[10] = {0,0,0,0,0,0,0,0,0,0};
  int size = count(digits, a) + count(digits, b);
  return (size == 10) ? size : (size == 9 and digits[0]) ? 0 : size;
}

void find(int n) {
  int count = 0;
  for (int i = 1234 ; i < 98765/n+2; i++) {
    int size = validate(i * n, i);
    if (size == 9) { 
      count++;
      cout << i*n << " / 0" << i << " = " << n << endl;
    } else if (size == 10) {
      count++;
      cout << i*n << " / " << i << " = " << n << endl;
    }
  }
  if (count == 0) cout << "There are no solutions for " << n << ".\n";
}

int main() {
  int n, tc = 0;
  while (cin >> n) {
    if (n != 0 and tc++ != 0) cout << endl;
    if (n != 0) find(n);
  }
  return 0;
}
