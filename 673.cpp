#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  int n;
  cin >> n;
  string null;
  getline(cin, null);

  while (n--) {
    string line;
    getline(cin, line);
    stack<char> s;
    bool left = false;
    for (int i = 0; i < line.size(); i++) {
      // cout << line[i] << ' ' << s.size() << endl;
      if (line[i] != '(' and line[i] != ')' and line[i] != '[' and line[i] != ']') continue;
      if (line[i] == '(' or line[i] == '[') s.push(line[i]);
      else if (line[i] == ')' and not s.empty() and s.top() == '(') s.pop();
      else if (line[i] == ']' and not s.empty() and s.top() == '[') s.pop();
      else {
        cout << "No\n";
        left = true;
        break;
      }
    }
    if (not left) {
      if (s.empty()) cout << "Yes\n";
      else cout << "No\n";
    }
  }
}
