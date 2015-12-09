#include <iostream>
#include <string>

using namespace std;

/**
 * I had to look up how to solve this problem, it turns out it's a lot simpler
 * than I thought. We want to run a depth first search, such that all traversed
 * paths are palindromes. So we define a function that will take a start node and
 * an end node, it will return the largest palindromic path from start to end.
 *
 * In this function, we can check for every node that we can go to from our starting
 * node and every node that we can end. Meaning, we want to find paths such that
 * path[start][i] == path[j][end]. This will ensure that all traversed paths are
 * palindromic. Once traversing such path, we recursively call the function to
 * find the palindromic path that is inside the current path.
 */

int tc, n;
char paths[51][51];
string dp[51][51];

string solve(int start, int end) {
  if (start > end) return "*";
  if (start == end) return "";
  if (dp[start][end] != "-") return dp[start][end];

  string ans, mid; ans += paths[start][end];
  for (int i = start + 1; i < n; i++) {
    if (paths[start][i] != '*') {
      for (int j = end - 1; j >= 0; j--) {
        if (paths[j][end] != '*' and paths[start][i] == paths[j][end]) {
          mid = solve(i, j);
          if (mid != "*") {
            mid = paths[start][i] + mid + paths[j][end];
            if (ans.size() < mid.size() or (ans.size() == mid.size() and mid < ans))
              ans = mid;
          }
        }
      }
    }
  }

  return dp[start][end] = ans;
}

int main() {
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> paths[i][j], dp[i][j] = "-";

    string sol = solve(0, n-1);
    if (sol != "*") cout << sol << endl;
    else cout << "NO PALINDROMIC PATH" << endl;
  }
  return 0;
}
