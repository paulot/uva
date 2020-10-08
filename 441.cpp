#include <iostream>

using namespace std;

int j, k, s[14];

int main() {
  while (cin >> k and k) {
    if (j++ > 0) cout << endl;
    for (int i = 0; i < k; i++) cin >> s[i];
    for (int a1 = 0; a1 < k; a1++) for (int a2 = a1 + 1; a2 < k; a2++)
    for (int a3 = a2 + 1; a3 < k; a3++) for (int a4 = a3 + 1; a4 < k; a4++)
    for (int a5 = a4 + 1; a5 < k; a5++) for (int a6 = a5 + 1; a6 < k; a6++)
      cout << s[a1] << ' ' << s[a2] << ' ' << s[a3] << ' ' << s[a4] << ' ' << s[a5] << ' ' << s[a6] << endl;
  }
  return 0;
}

