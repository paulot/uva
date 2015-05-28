#include <iostream>
#include <string>
#include <vector>
#include <tuple>

using namespace std;


int main() {
  int n, p, crep = 1;
  string null;

  while (true) {
    cin >> n >> p;
    if (n == 0 and p == 0) return 0;
    if (crep != 1) cout << endl;
    getline(cin, null);
    for (int i = 0; i < n; i++) getline(cin, null);

    double mprice;
    int comp = -1;
    string name;
    for (int i = 0; i < p; i++) {
      string pname;
      double price;
      int mr;
      getline(cin, pname);
      cin >> price >> mr;
      if (mr > comp or (mr == comp and mprice > price)) {
        comp = mr;
        name = pname;
        mprice = price;
      }


      getline(cin, null);
      for (int j = 0; j < mr; j++) getline(cin, null);
    }

    cout << "RFP #" << crep++ << endl << name << endl;
  }

  return 0;
}
