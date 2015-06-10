#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef pair<double, string> ds;

template<typename t>
vector<ds> split(string &str, t (*func)(const string &)) {
  char split_char = ' ';
  istringstream split(str);
  vector<ds> token;

  for (string each; getline(split, each, split_char); token.push_back(make_pair(func(each), each)));
  return token;
}

template<typename t>
vector<t> spliti(string &str, t (*func)(const string &)) {
  char split_char = ' ';
  istringstream split(str);
  vector<t> token;

  for (string each; getline(split, each, split_char); token.push_back(func(each)));
  return token;
}

int stoi2(const string &s) { return stoi(s); }
double stod2(const string &s) { return stod(s); }

int main() {
  int n;
  cin >> n;
  string s;
  getline(cin, s);
  for (int i = 0; i < n; i++) {
    getline(cin, s);
    getline(cin, s);
    vector<int> inds = spliti<int>(s, stoi2);
    getline(cin, s);
    vector<ds> nums = split<double>(s, stod2);
    vector<ds> copy = nums;

    for (int i = 0; i < inds.size(); i++) copy[inds[i]-1] = nums[i];
    for (int i = 0; i < inds.size(); i++) cout << copy[i].second << endl;
    if (i != n-1) cout << endl;
  }
  return 0;
}
