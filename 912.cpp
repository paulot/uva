#include <iostream>

using namespace std;

char sets[100];
char num1[100], num2[100];
int findSet(int a) { return (sets[a] == a) ? a : findSet(sets[a]); }
bool isLet(int a) { return a >= 'A' and a <= 'Z'; }
bool unionSet(int a, int b) {
  int as = findSet(a), bs = findSet(b);
  if (as == bs) return true;
  if (isLet(as) and isLet(bs)) return false;
  if (isLet(as) or isLet(bs)) {
    if (isLet(as)) sets[bs] = as;
    else sets[as] = bs;
  }
  return true;
}

int main() {
  int n;
  bool f = true;
  while (cin >> n) {
    if (not f) cout << endl;
    f = false;
    for (int i = 0; i < 100; i++) sets[i] = i;

    for (int i = 0; i < n; i++) cin >> num1[i];
    for (int i = 0; i < n; i++) {
      cin >> num2[i];
      if (not isLet(num1[i]) and not isLet(num2[i])) unionSet(num1[i], num2[i]);
    }

    /*
    for (int i = 0; i < n; i++) cout << num1[i];
    cout << endl;
    for (int i = 0; i < n; i++) cout << num2[i];
    cout << endl;

    for (int i = '1'; i <= '9'; i++)
      cout << sets[i];
    cout << endl;
    */

    for (int i = 0; i < n; i++) {
      // cout << "comparing " << num1[i] << ' ' << num2[i] << endl;
      if (not isLet(num1[i]) or not isLet(num2[i])) {
        unionSet(num2[i], num1[i]);
      }
    }

    for (int i = 0; i < n; i++) {
      if (isLet(num1[i]) and isLet(num2[i]) and num1[i] != num2[i]) {
        cout << "NO\n";
        goto end;
      }
      else if (not isLet(num1[i]) or not isLet(num2[i])) {
        if (isLet(num1[i]) and num1[i] != findSet(num2[i])) {
          cout << "NO\n";
          goto end;
        } else if (isLet(num2[i]) and num2[i] != findSet(num1[i])) {
          cout << "NO\n";
          goto end;
        }
      }
    }

    cout << "YES\n";
    for (int i = '1'; i <= '9'; i++)
      if (sets[i] != i)
        cout << (char) i << ' ' << (char) findSet(sets[i]) << endl;
end:

    int a;

  }
  return 0;
}
