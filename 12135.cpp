#include <iostream>
#include <cstring>
#include <queue>
#include <bitset>
#define set(num, x) num |= 1 << x
#define clear(num, x) num &= ~(1 << x)
#define apply(num, swt) num ^= swt

using namespace std;

/**
 * The idea of this problem is to do a breath first search keeping track
 * of the current state of the bulbs in a bitmask and using dp to speed up
 *
 * So in our bfs, we first push the initial state, and we keep running it until
 * there are no more states for us to visit. For our current state, we apply
 * every single switch possible. If any switch leads to a solution we have not yet
 * explored, we add that to the queue.
 *
 * This implementation can be faster by using a set instead of a queue, and checking
 * if the element is already in the set before adding.
 */

typedef pair<int, int> ii;

int tc, n, m, q, switches[41], dp[1<<15];

int main() {
  cin >> tc;
  for (int z = 1; z <= tc; z++) {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
      int k, x; cin >> k; switches[i] = 0;
      for (int j = 0; j < k; j++) {
        cin >> x; set(switches[i], x);
      }
    }

    memset(dp, -1, sizeof dp);
    queue<ii> states;
    states.push(make_pair(0, 0)); // Push initial state
    while (not states.empty()) {
      int cstate = states.front().first, nsteps = states.front().second;
      states.pop();
      if (dp[cstate] != -1) continue;
      dp[cstate] = nsteps;

      for (int i = 0; i < m; i++) {
        apply(cstate, switches[i]);
        if (dp[cstate] == -1) states.push(make_pair(cstate, nsteps + 1));
        apply(cstate, switches[i]);
      }
    }

    cout << "Case " << z << ":" << endl;
    cin >> q;
    for (int i = 0; i < q; i++) {
      string query; cin >> query; bitset<16> bla(query);
      cout << dp[bla.to_ulong()] << endl;
    }
    cout << endl;
  }
  return 0;
}
