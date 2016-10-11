#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int from, to;
  while (cin >> from >> to and from != -1 and to != -1)
    cout << min(abs(from - to), (min(from, to) - max(from, to) + 100) % 100) << endl;
  return 0;
}
