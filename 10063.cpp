#include <string>
#include <iostream>
#include <cstring>

using namespace std;

int t;
char ans[30];
string in;

void permute(int ind) {
  if (ind == in.size()) {
    ans[ind] = '\0';
    puts(ans);
    return;
  }

  for (int i = 0; i <= ind; i++) {
    memmove(ans + (1 + i), ans + i, ind - i);
    ans[i] = in[ind];
    permute(ind + 1);
    memmove(ans + i, ans + (1 + i), ind - i);
  }
}

int main() {
  while (cin >> in) { if(t++) cout << endl; permute(0); }
}
