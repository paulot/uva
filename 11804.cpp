#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

string names[10];
map <string, int> defense, attack;

int main() {
  int tc; cin >> tc;
  for (int tcn = 1; tcn <= tc; tcn++) {
    int maxd = 0;
    for (int i = 0; i < 10; i++) { 
      cin >> names[i]; cin >> attack[names[i]] >> defense[names[i]];
      maxd += defense[names[i]];
    }

    sort(names, names+10);

    int md = 0, ma = 0, an[5];
    for (int i1 = 0; i1 < 6; i1++) 
    for (int i2 = i1+1; i2 < 7; i2++) 
    for (int i3 = i2+1; i3 < 8; i3++) 
    for (int i4 = i3+1; i4 < 9; i4++) 
    for (int i5 = i4+1; i5 < 10; i5++) {
      int a = attack[names[i1]]+attack[names[i2]]+attack[names[i3]]
              +attack[names[i4]]+attack[names[i5]];
      int d = maxd - (defense[names[i1]]+defense[names[i2]]
        +defense[names[i3]]+defense[names[i4]]+defense[names[i5]]);

      if (ma < a) {
        ma = a; md = d;
        an[0] = i1, an[1] = i2, an[2] = i3, an[3] = i4, an[4] = i5;
      } else if (ma == a and d > md) {
        ma = a; md = d;
        an[0] = i1, an[1] = i2, an[2] = i3, an[3] = i4, an[4] = i5;
      }
    }

    bool picked[10] = {0,0,0,0,0,0,0,0,0,0};
    cout << "Case " << tcn << ":\n";
    cout << "(";
    for (int i = 0; i < 5; i++) {
      cout << names[an[i]]; picked[an[i]] = true;
      if (i == 4) cout << ")\n";
      else cout << ", ";
    }
    cout << "("; int np = 0;
    for (int i = 0; i < 10; i++) {
      if (not picked[i]) {
        cout << names[i];
        np++;
        if (np != 5) cout << ", ";
        else cout << ")\n";
      }
    }
  }
}
