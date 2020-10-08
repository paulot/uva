#include <iostream>
#include <cstring>
#include <cmath>

#define get(n, i) ((n >> i) % 2)
#define set(n, i) (n | (1 << i))
#define clear(n, i) (n & ~(1 << i))
#define ll long long
#define inf 99999999999

using namespace std;

int a, b, c, t, n, m, p;
ll roads[51][51], shortest[51][51], saved[51], win; 
double in;

ll solve(int cur, ll vis) {
  cout << cur << ' ' << vis << "   " << win << endl;
  if ((vis & win) == win) { cout << "win! " << shortest[cur][0] << endl; return shortest[cur][0]; }
  
  ll best = inf;
  for (int i = 1; i < n; i++) {
    if (roads[cur][i] != -1 and get(vis, i) != 1) {
      best = min(best, roads[cur][i] - saved[i] + solve(i, set(vis, i)));
    }
  }

  cout << "best " << best << endl;
  return best;
}


int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m; n++;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
      roads[i][j] = shortest[i][j] = inf;

    for (int i = 0; i < m; i++) {
      cin >> a >> b >> in;
      c = round(in * 100);
      roads[a][b] = roads[b][a] = c;
      shortest[a][b] = shortest[b][a] = c;
    }
    cin >> p;
    memset(saved, 0, sizeof(saved));
    win = 0;
    for (int i = 0; i < p; i++) {
      cin >> a >> in;
      win = set(win, a);
      c = round(in * 100);
      saved[a] = c;
    }
    for (int i = 0; i < n; i++) shortest[i][i] = 0;

    for (int a = 0; a < n; a++)
      for (int b = 0; b < n; b++)
        for (int c = 0; c < n; c++)
          if (shortest[b][c] > shortest[b][a] + shortest[a][c]) {
            shortest[b][c] = shortest[b][a] + shortest[a][c];
            shortest[c][b] = shortest[b][a] + shortest[a][c];
          }

    cout << endl << endl;

    for (int a = 0; a < n; a++) {
      for (int b = 0; b < n; b++)
        cout << shortest[a][b] << ' ';
      cout << endl;
    } cout << endl;


    cout << solve(0, 1) << endl;
  }
  return 0;
}
