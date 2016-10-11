#include <iostream>
#include <string>
#include <vector>

using namespace std;

string song[] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to",
                 "Rujia", "Happy", "birthday", "to", "you"};

vector<string> peeps;
int n;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) { string in; cin >> in; peeps.push_back(in); }
  for (int i = 0; i < ((peeps.size() % 16 == 0) ? peeps.size() : ((peeps.size() / 16) + 1) * 16); i++)
    cout << peeps[i % peeps.size()] << ": " << song[i % 16] << endl;
  return 0;
}
