#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

/*
 * The basic idea of this solution is to use the n^2 solution
 * to the lis problem, but maintain the several different faces
 * of each cube.
 */

using namespace std;

int lis[500][6], back[500][6][2], cubes[500][6], n;
string sides[6] = { "front", "back", "left", "right", "top", "bottom" };

int main() {
  int tc = 1;
  while (cin >> n and n != 0) {
    if (tc > 1) cout << endl;
    for (int i = 0; i < n; i++) {
      for (int f = 0; f < 6; f++) {
        cin >> cubes[i][f];
        lis[i][f] = 1;
        back[i][f][0] = i; back[i][f][1] = 0;
      }
    }
    
    int m = 1, ei = 0, ef = 0;
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        for (int fi = 0; fi < 6; fi++) for (int fj = 0; fj < 6; fj++) {
          int op = (fj % 2) ? fj - 1 : fj + 1;
          if (cubes[i][fi] == cubes[j][op] and lis[i][fi] < lis[j][fj] + 1) {
            lis[i][fi] = lis[j][fj] + 1;
            back[i][fi][0] = j;
            back[i][fi][1] = fj;
            if (lis[i][fi] > m) {
              m = lis[i][fi];
              ei = i; ef = fi;
            }
          }
        }
      }
    }

    vector<string> ans;

    while (back[ei][ef][0] != ei) {
      int oei = ei;
      stringstream s;
      s << ei+1 << ' ' << sides[ef];
      ans.push_back(s.str());
      ei = back[ei][ef][0], ef = back[oei][ef][1];
    }
    stringstream s;
    s << ei+1 << ' ' << sides[ef];
    ans.push_back(s.str());

    cout << "Case #" << tc++ << endl << ans.size() << endl;
    for(int i = ans.size()-1; i >= 0; i--)
      cout << ans[i] << endl;
  }
}
