#include <iostream>
#define ll long long

using namespace std;

int f(ll n) {
  int sum = 0;
  while (n != 0) { sum += n%10; n/=10; }
  return sum;
}

int g(ll n) {
  int last = f(n);
  while (f(last) != last) { last = f(last); }
  return last;
}

int main() {
  ll n;
  while (cin >> n and n != 0) cout << g(n) << endl;
  return 0;
}
