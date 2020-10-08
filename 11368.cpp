#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;

int n, t, a, b;
vector<ii> dolls;
vector<int> ans;

/**
 * The idea is as follows:
 *  1. Sort the input by height asc, then width desc
 *  2. Make vector or widths
 *  3. For each doll, binary search its width in the array
 *  4. If there is a width bigger, simply replace the bigger width with the new width.
 *  5. If these is no bigger width, add it to the array.
 *  6. Solution is the size of the array.
 *
 * Sorting is done like so:
 * Sort by height first in ascending order. In case of a tie, we want to place the
 * smallest width before. This is done to handle cases where there is a tie in heights.
 * For instance the case: (2,1) (3,1) (4,1) if the sorting places larger widths before,
 * upper bound (in main) will replace the item already placed in the vector.
 *
 * The idea is that we're leveraging the array farmed with widths and maintaining it in order.
 * For each sequence we're maintaining the smallest width of that sequence. This allows
 * us to quickly check if we need to create a new sequence for this or not.
 */

struct lt {
  inline bool operator() (const ii& p1, const ii& p2) {
    return (get<1>(p1) == get<1>(p2)) ? get<0>(p1) < get<0>(p2) : get<1>(p1) > get<1>(p2);
  }
};


int main() {
  cin >> t;
  while (t--) {
    dolls.clear(); ans.clear();
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> a >> b; dolls.push_back(make_pair(a, b)); }
    sort(dolls.begin(), dolls.end(), lt());

    int used = 0;
    for (int i = 0; i < dolls.size(); i++) {
      int cur = get<0>(dolls[i]);
      int idx = upper_bound(ans.begin(), ans.end(), cur) - ans.begin();


      if (idx == ans.size()) {
        ans.push_back(cur);
        used++;
      } else {
        ans[idx] = cur;
      }
    }

    cout << used << endl;
  }
  return 0;
}
