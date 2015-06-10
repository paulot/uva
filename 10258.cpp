#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

typedef struct {
  int num;
  int ptime;
  int nsolved;
  int ptry[10];
  bool solved[10];
  bool p;
} cont;

cont contestants[101];

void init(cont &c, int n) {
  c.num = n; c.ptime = 0; c.nsolved = 0;
  c.p = false;
  for (int i = 0; i < 10; i++) c.ptry[i] = 0;
  for (int i = 0; i < 10; i++) c.solved[i] = false;
}

void init_contestants() {
  for (int i = 0; i < 101; i++) init(contestants[i], i);
}

void print(cont &c) {
  if (c.p) cout << c.num << ' ' << c.nsolved << ' ' << c.ptime << endl;
}

bool compare(const cont &lhs, const cont &rhs) {
  if (lhs.nsolved != rhs.nsolved) return lhs.nsolved > rhs.nsolved;
  if (lhs.ptime != rhs.ptime) return lhs.ptime < rhs.ptime;
  return lhs.num < rhs.num;
}

void try_problem(cont &contestant, int pnum, int time, char outcome) {
  contestant.p = true;
  if (contestant.solved[pnum]) return;
  if (outcome == 'C') {
    contestant.solved[pnum] = true, contestant.ptime += time;
    contestant.ptime += contestant.ptry[pnum]; contestant.nsolved++;
  } else if (outcome == 'I') {
    contestant.ptry[pnum] += 20;
  }
}

void parse(string &str) {
  size_t pos = str.find(' ');
  int ind = stoi(str.substr(0, pos));
  size_t npos = str.find(' ', pos+1);
  int pnum = stoi(str.substr(pos, npos-pos));
  pos = str.find(' ', npos+1);
  int time = stoi(str.substr(npos, pos-npos));
  char outcome = str[str.size()-1];

  try_problem(contestants[ind], pnum, time, outcome);
}

void psol() {
  sort(begin(contestants), end(contestants), compare);
  for (int i = 0; i <= 100; i++) print(contestants[i]);
}

int main() {
  init_contestants();
  int tc; cin >> tc;
  string null, line;
  getline(cin, null);
  getline(cin, null);
  while (getline(cin, line)) {
    if (line.empty()) {
      psol();
      init_contestants();
      cout << endl;
      continue;
    }
    parse(line);
  }
  psol();
  return 0;
}
