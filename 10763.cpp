#include <iostream>
#include <map>
#define ll unsigned long long

using namespace std;

ll get_pair(int a, int b) {
  return (((ll) a) << 19) + b;
}

int main() {
  int n;
  while (cin >> n and n != 0) {
    map<ll, int> counts;
    for (int i = 0; i < n; i++) {
      int a, b; cin >> a >> b;
      ll dest = get_pair(b, a);
      if (counts.find(dest) != counts.end()) {
        counts[dest]--; 
        if (counts[dest] == 0) counts.erase(dest);
      } else {
        counts[get_pair(a, b)]++;
      }
    }
    cout << ((counts.empty()) ? "YES" : "NO") << endl;
  }
  return 0;
}
