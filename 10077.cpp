#include <iostream>
#include <string>

using namespace std;

typedef pair<int, int> ii;
ii frac;
string trav;

int gcd(int a, int b) {
  if (a == b) return a;
  return (a > b) ? gcd(a-b, b) : gcd(a, b-a);
}

void search(ii node, ii left, ii right) {
  // cout << "node " << node.first << ' ' << node.second << endl;
  if (node.first == frac.first and node.second == frac.second) {
    cout << trav << endl;
    return;
  }

  double num = ((double) node.first) / node.second;
  double fnum = ((double) frac.first) / frac.second;
  // cout << "num " << num << " fnum " << fnum << endl;
  if (num > fnum) {
    ii new_node = make_pair(node.first+left.first, node.second+left.second);
    int div = gcd(new_node.first, new_node.second);
    new_node.first /= div; new_node.second /= div;
    trav += 'L';
    return search(new_node, left, node);
  } else {
    ii new_node = make_pair(node.first+right.first, node.second+right.second);
    int div = gcd(new_node.first, new_node.second);
    new_node.first /= div; new_node.second /= div;
    trav += 'R';
    return search(new_node, node, right);
  }
}

int main() {
  ii l = make_pair(0, 1), r = make_pair(1, 0), n = make_pair(1, 1);
  while (cin >> frac.first >> frac.second) {
    if (frac.first == 1 and frac.second == 1) return 0;
    trav = "";
    search(n, l, r);
  }
  return 0;
}



