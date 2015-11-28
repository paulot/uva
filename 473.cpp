#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;

// dp[start position][end position] = number of tracks to fit in one cd
int tc, n, cds, len, tracks[10000], dp[10000][10000];

int cd_dp[10000][10000];

int solve(int start, int cds_left) {
  if (start >= n or cds_left <= 0) return 0;
  if (cds_left == 1) return dp[start][n-1];
  if (cd_dp[start][cds_left] != -1) return cd_dp[start][cds_left];

  int max_songs = 0;
  for (int end = start; end <= n-cds_left; end++) {
    max_songs = max(max_songs, dp[start][end] + solve(end+1, cds_left-1));
  }
  cd_dp[start][cds_left] = max_songs;
  return max_songs;
}

int main() {
  for (cin >> tc; tc; tc--) {
    string in; stringstream stream;
    cin >> n >> len >> cds;
    getline(cin, in); getline(cin, in); replace(in.begin(), in.end(), ',', ' ');
    stream << in;

    for (int i = 0; i < n; i++) stream >> tracks[i];

    for (int i = 0; i < n; i++)
      for (int j = 0; j <= cds; j++)
        cd_dp[i][j] = -1;

    for (int i = 0; i < n; i++) {
      priority_queue<int> q; int sum = 0;
      for (int j = i; j < n; j++) {
        if (q.empty()) q.push(tracks[j]), sum = tracks[j];
        else if (len - sum >= tracks[j]) q.push(tracks[j]), sum += tracks[j];
        else if (len - sum < tracks[j] and q.top() > tracks[j])
          sum -= q.top(), q.pop(), q.push(tracks[j]), sum += tracks[j];
        dp[i][j] = q.size();
      }
    }

    cout << solve(0, cds) << endl;
    if (tc != 1) cout << endl;
  }
  return 0;
}
