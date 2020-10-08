#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int t, n, d, dist[102];
char type;
bool used[102], small[102];
string in;

int main() {
  scanf("%d\n", &t);
  for (int tt = 1; tt <= t; tt++) {
    memset(used, 0, sizeof(used));
    memset(small, 0, sizeof(used));
    scanf("%d %d\n", &n, &d);
    for (int i = 1; i <= n; i++) {
      cin >> in;
      sscanf(in.c_str(), "%c-%d", &type, &dist[i]);
      small[i] = type == 'S';
    }
    dist[n+1] = d;

    int maxGap = 0, lastDist = 0;
    bool tookSmall = false;
    for (int i = 1; i <= n + 1; i++) {
      if (tookSmall and small[i]) {
        tookSmall = false;
      } else {
        maxGap = max(maxGap, dist[i] - lastDist);
        lastDist = dist[i];
        tookSmall = small[i];
        used[i] = true;
      }
    }

    // Go back
    for (int i = n; i >= 0; i--) {
      if (small[i] and used[i]) continue;

      maxGap = max(lastDist - dist[i], maxGap);
      lastDist = dist[i];
    }
    cout << "Case " << tt << ": " << maxGap << endl;
  }
  return 0;
}
