#include <iostream>
#include <stack>
#include <string>

using namespace std;

int n;
string line, null;

int get_prec(char c) {
  if (c == '*' or c == '/') return 100;
  if (c == '+' or c == '-') return 10;
  return 1;
}

void empty(stack<char> &s, char c) {
  while (not s.empty() and get_prec(s.top()) >= get_prec(c)) {
    cout << s.top();
    s.pop();
  }
}

void parse(bool stop) {
  stack<char> s;
  while (true) {
    getline(cin, line);
    if (line.size() == 0) break;
    char c = line[0];

    if (c == ')' and stop) {
      empty(s, c);
      return;
    }
    if (c == '(') {
      parse(true);
      continue;
    }
    if (get_prec(c) == 1) {
      cout << c;
    }
    else {
      empty(s, c);
      s.push(c);
    }
  }

  while (not s.empty()) {
    cout << s.top();
    s.pop();
  }
  cout << endl;
}



int main() {
  cin >> n;
  getline(cin, null);
  getline(cin, null);

  while (n--) {
    parse(false);
    if (n) cout << endl;
  }
  return 0;
}
