#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <limits.h>
#define INVALID INT_MIN

using namespace std;
typedef vector<int> vi;

class segment_tree {
  private:
    vi tree;
    int *arr, n;
    int *orig;
    int length;
    void build(int node, int s, int e) {
      if (s == e) tree[node] = arr[s];
      else {
        int left = 2 * node, right = 2 * node + 1;
        build(left, s, (s+e)/2); build(right, (s+e)/2 + 1, e);
        tree[node] = max(tree[left], tree[right]);
      }
    };
    // s and e are the query interval, indicating the interval represented by node
    int query(int node, int s, int e, int i, int j) {
      if (i > e || j < s) return INVALID; 
      if (s >= i && e <= j) return tree[node];
      int left = query(2*node, s, (s+e)/2, i, j), 
          right = query(2*node+1, (s+e)/2 + 1, e,i, j);
      return max(left, right);
    };

  public:
    segment_tree(int orig[], int arr[], int n) {
      length = (int)(2 * pow(2.0, floor((log((double)n) / log(2.0)) + 1)));
      tree.resize(length, 0);
      this->arr = arr; this->n = n;
      this->orig = orig;
      build(1, 0, n-1);
    };

    int getMax(int i, int j) {
      // Adjust the boundaries
      int cstart = 0, cend = 0;
      while (i > 0 and i <= j and orig[i] == orig[i-1]) i++, cstart++;
      while (j >= i and j < n-1 and orig[j] == orig[j+1]) j--, cend++;

      return (j < i) ? max(cstart, cend) : max(max(query(1, 0, n-1, i, j), cstart), cend);
    };

    void print() {
      for (int i = 0; i < tree.size(); i++) cout << tree[i] << ' ';
      cout << endl;
    };
};

int main() {
  int n, q;
  while (cin >> n) {
    if (n == 0) return 0;
    cin >> q;
    int orig[100000];
    int arr[100000];
    map<int, int> count;

    for (int i = 0; i < n; i++) {
      int a; cin >> a; count[a]++; orig[i] = a;
    }
    for (int i = 0; i < n; i++) arr[i] = count[orig[i]];

    segment_tree tree(orig, arr, n);

    for (int i = 0; i < q; i++) {
      int a, b; cin >> a >> b;
      cout << tree.getMax(a-1, b-1) << endl;
    }
  }
  return 0;
}
