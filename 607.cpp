#include <iostream>
#include <limits.h>
#define sq(x) ((x)*(x))

using namespace std;

/*
 * Explanation:
 * The idea behind this algorithm is to iterate through the ranges of
 * topics that form lectures. Hence, for every interval of congruent
 * topics, we check if that forms a possible lecture. If so, we take
 * the number of classes we found up to the current lecture and add 1.
 * If that value is smaller than the value we currently have for it, we
 * replace it according to the rules specified in the problem.
 *
 * Hence, we let i be the topic position that we're looking at. Our dp array
 * will be:
 *    classes[i] = min number of lectures taking in account topics until pos i
 *    costs[i] = min cost taking in account the number of lectures and topics
 *               until position i.
 *
 * The nested loop does the following:
 * let i be the end position that we'll be looking at
 * let j be the start position of the current lecture we are looking at
 *  j...i then j......i
 * hence, j grows more distant from i, as we want to stop when the distance is
 * large enough that we cannot form a lacture.
 *
 * The dp relationship in the double loop is as follows:
 * if the number of classes we have ending at the final point of this lecture (aka i) is
 * larger than the number of classes ending at the begining of this lecture (aka j), we
 * set the number of lectures at i to the number of lectures at j + 1 (+1 because we
 * need to take in account the current lecture)
 *
 * if they are the same update the cost of the lecture accordingly.
 */

int l, c, n, tc, sums[100000], costs[100000], classes[100000];

int get_cost(int from, int to) {
  int total = l - (sums[to] - sums[from]);
  return (total > 10) ? sq(total-10) : (total == 0) ? 0 : -c;
}

int main() {
  while (cin >> n and n != 0) {
    if (tc) cout << endl;
    cin >> l >> c;
    for (int i = 1; i <= n; i++) cin >> sums[i], sums[i] += sums[i-1], costs[i] = classes[i] = INT_MAX;

    classes[0] = costs[0] = 0;
    for (int i = 1; i <= n; i++)
      for (int j = i-1; j >= 0 and sums[i] - sums[j] <= l; j--)
        if (classes[i] > classes[j] + 1) classes[i] = classes[j]+1, costs[i] = costs[j] + get_cost(j, i);
        else if (classes[i] == classes[j] + 1) costs[i] = min(costs[i], costs[j] + get_cost(j, i));

    cout << "Case " << ++tc << ":" << endl;
    cout << "Minimum number of lectures: "<< classes[n] << endl;
    cout << "Total dissatisfaction index: " << costs[n] << endl;
  }
  return 0;
}
