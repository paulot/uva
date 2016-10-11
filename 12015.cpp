#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
  int tc; cin >> tc;
  for (int t = 1; t <= tc; t++) {
    map<int, vector<string> > ranks;
    string in; int val;
    int max_rank = -1;
    for (int i = 0; i < 10; i++) {
      cin >> in >> val;
      ranks[val].push_back(in);
      max_rank = max(max_rank, val);
    }
    cout << "Case #" << t << ":" << endl;
    for (int i = 0; i < ranks[max_rank].size(); i++) {
      cout << ranks[max_rank][i] << endl;
    }
  }
  return 0;
}
