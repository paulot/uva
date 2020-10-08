#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#define sq(a) ((a) * (a))
#define distance(i, j) (sqrt(sq(computer[i][0]-computer[j][0])+sq(computer[i][1]-computer[j][1])))
#define get(n, i) ((n >> i) % 2)
#define set(n, i) (n | (1 << i))
#define clear(n, i) (n & ~(1 << i))
#define ll unsigned long long

using namespace std;

int computer[10][2], connect[10], n, t = 1, nextc[10][600];
double dp[10][600];

double solve(int cur, int visited) {
  // cout << cur <<  ' ' << __builtin_popcount(visited) << ' ' << visited << ' ' << get(visited, 1) << endl;
  if (__builtin_popcount(visited) == n) return 0;
  if (nextc[cur][visited] != -1) return dp[cur][visited];

  double best = 999999999999, tmp;
  int nex;
  for (int i = 0; i < n; i++) {
    if (get(visited, i) == 0) {
      tmp = 16 + distance(cur, i) + solve(i, set(visited, i));

      if (tmp < best) {
        best = tmp;
        nex = i;
      }
    }
  }
  // cout << "best " << best << endl;
  nextc[cur][visited] = nex;
  return dp[cur][visited] = best;
}

int main() {
  while (cin >> n and n) {
    memset(nextc, -1, sizeof(nextc));
    for (int i = 0; i < n; i++) cin >> computer[i][0] >> computer[i][1];
    cout << "**********************************************************" << endl;
    cout << "Network #" << t++ << endl;
    int i = 0, vis = 1;
    double sol = 999999999999, tmp;
    for (int j = 0; j < n; j++) {
      tmp = solve(j, set(0, j));
      if (sol > tmp) {
        sol = tmp;
        i = j;
        vis = set(0, j);
      }
    }

    while (nextc[i][vis] != -1) {
      int ni = nextc[i][vis];
      int nvis = set(vis, ni);
      printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", computer[i][0], computer[i][1],
              computer[ni][0], computer[ni][1], 16 + distance(i, ni));
      i = ni;
      vis = nvis;
    }
    printf("Number of feet of cable required is %.2f.\n", sol);
  }
  return 0;
}

