#include <stack>
#include <iostream>
#include <string>

using namespace std;

stack<int> b;
stack<int> a;

void populate_a(int n) {
  a = stack<int>();
  for (int i = n; i >= 1; i--) a.push(i);
}

bool can_get(int num) {
  if (b.empty() and not a.empty()) {
    b.push(a.top()); a.pop();
  }
  while(b.top() != num and not a.empty()) {
    b.push(a.top()); a.pop();
  }
  if (b.top() == num) {
    b.pop();
    return true;
  } else {
    return false;
  }
}

int main() {
  int j = 0;
  while(true) {
    int n; cin >> n;
    if (j++ != 0) cout << endl;
    if (n == 0) return 0;
    string null;


    bool in_block = true;
    while (in_block) {
      populate_a(n);
      bool left_loop = false;

      for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == 0) {
          in_block = false;
          left_loop = true;
          break;
        }
        if (not can_get(a)) {
          cout << "No\n";
          getline(cin, null);
          left_loop = true;
          break;
        }
      }
    if (not left_loop) cout << "Yes\n";
    }
  }
}


