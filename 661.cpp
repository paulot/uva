#include <iostream>

using namespace std;

bool state[20];
int n, m, c, consumption[20];

int total_cons() {
  int ans = 0;
  for (int i = 0; i < n; i++)
    ans += (state[i]) ? consumption[i] : 0;
  return ans;
}

int main() {
  int s = 1;
  while (true) {
    for (int i = 0; i < 20; i++) {
      state[i] = 0;
      consumption[i] = 0;
    }

    cin >> n >> m >> c;
    if (n == 0) return 0;

    cout << "Sequence " << s++ << endl;

    for (int i = 0; i < n; i++) {
      int c;
      cin >> c;
      consumption[i] = c;
    }


    int max_cons = 0;
    bool blown = false;
    for (int i = 0; i < m; i++) {
      int s;
      cin >> s;
      state[s-1] = !state[s-1];
      int cons = total_cons();
      max_cons = max(max_cons, cons);

      if (cons > c) {
        blown = true;
      }
    }
    if (not blown) {
      cout << "Fuse was not blown." << endl;
      cout << "Maximal power consumption was " << max_cons << " amperes." << endl;
    } else {
      cout<< "Fuse was blown." << endl;
    }
    cout << endl;
  }

  return 0;
}
