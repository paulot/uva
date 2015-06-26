#include <iostream>
#include <cctype>
#include <map>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, string> is;

map<string, set<string> > fair;
map<string, int> counts;

void rmdup() {
  for (auto &it : fair) {
    for (auto i = it.second.begin(); i != it.second.end();) {
      if (counts[*i] > 1) it.second.erase(i++);
      else ++i;
    }
  }
}

bool comp(const is &a, const is &b) {
  if (a.first == b.first) return a.second < b.second;
  return a.first > b.first;
}

void print() {
  rmdup();

  vector<is> p;
  for (auto &it : fair) p.push_back(make_pair(it.second.size(), it.first));

  sort(p.begin(), p.end(), comp);

  for (int i = 0; i < p.size(); i++) cout << p[i].second << ' ' << p[i].first << endl;



  /*
  for (auto &it : fair) {
    cout << it.first << ' ';
    for (auto &i : it.second) {
      cout << i << ' ';
    }
    cout << endl;
  }
  cout << endl;
  for (auto &it : counts) {
    cout << it.first << ' ' << it.second << endl;
  }
  */
}

int main() {
  string line;
  getline(cin, line);
  while (true) {
    if (line[0] == '0') {
      return 0;
    } else if (line[0] == '1') {
      print();
      fair.clear(); counts.clear();
      getline(cin, line);
    } else if (isupper(line[0])) {
      string team = line;
      getline(cin, line);
      fair[team];
      while (not isupper(line[0]) and line[0] != '1' and line[0] != '1') {
        fair[team].insert(line);
        getline(cin, line);
      }
      for (auto &it : fair[team]) counts[it]++;
    }
  }
}

