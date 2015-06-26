#include <iostream>
#include <set>

using namespace std;

int main() {
  while (true) {
    int n; cin >> n;
    if (n == 0) return 0;
    unsigned long long int price = 0;
    multiset<int> urn;
    for (int i = 0; i < n; i++) {
      int d; cin >> d;
      for (int j = 0; j < d; j++) {
        int in; cin >> in;
        urn.insert(in);
      }
      price += *(--urn.end()) - *urn.begin();
      auto it = urn.begin();
      urn.erase(it); it = urn.end();
      urn.erase(--it);
    }
    cout << price << endl;
  }
}

