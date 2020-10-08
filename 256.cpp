#include <iostream>
#include <cstdio>
#include <string>
#define sq(n) ((n)*(n))

using namespace std;

int in;

void gen(int n) {
  int maxint = 0, p = 1;
  for (int i = 0; i < n; i++) { maxint *= 10; maxint += 9; }
  for (int i = 0; i < n / 2; i++) p *= 10;
  string format = "%0" + to_string(n) + "d\n";

  for (int i = 0; i <= maxint; i++) {
    int f = i / p, s = i % p;
    if (sq(f + s) == i) printf(format.c_str(), i);
  }
}

int main() {
  while (cin >> in) gen(in);
  return 0;
}
