#include <iostream>
#include <set>
#include <iterator>

using namespace std;

set<int> scores;
int n;

int main() {
  for (int i = 0; i <= 20; i++) { scores.insert(i); scores.insert(i * 2); scores.insert(i * 3); }
  scores.insert(50);

  while (cin >> n and n > 0) {
    int p = 0, c = 0;

    for (auto it1 = scores.begin(); it1 != scores.end(); it1++)
    for (auto it2 = scores.begin(); it2 != scores.end(); it2++)
    for (auto it3 = scores.begin(); it3 != scores.end(); it3++)
      if (*it1 + *it2 + *it3 == n) p++;

    for (auto it1 = scores.begin(); it1 != scores.end(); it1++)
    for (auto it2 = it1; it2 != scores.end(); it2++)
    for (auto it3 = it2; it3 != scores.end(); it3++)
      if (*it1 + *it2 + *it3 == n) c++;

    if (c == 0 and p == 0) cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
    else {
      cout << "NUMBER OF COMBINATIONS THAT SCORES " << n <<" IS " << c << '.' << endl;
      cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << p << '.' << endl;
    }

    cout << "**********************************************************************" << endl;
  }

  cout << "END OF OUTPUT" << endl;
  return 0;
}



