#include <iostream>
#include <cmath>
#include <map>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

class arr {
  private:
    int nums[100000], index, n, count_size, window;
    vector<map <int, int> > partitions;

  public:
    arr(int n) {
      this->n = n;
      window = ((int) sqrt(n)) + 1;
      index = 0;
      count_size = 0;
      partitions.push_back(map <int, int> ());
    };
    void add(int num) {
      nums[index++] = num;
      partitions.back()[num]++; count_size++;

      if (count_size == window) {
        count_size = 0;
        partitions.push_back(map <int, int> ());
      }
    }
    void print() {
      cout << "window " << window << endl;
      for (int i = 0; i < n; i++)
        cout << nums[i] << ' ';
      cout << endl;

      for (int i = 0; i < partitions.size(); i++) {
        cout << "(";
        for (auto & it : partitions[i]) {
          cout << "(" << it.first << ':' << it.second << ')';
        }
        cout << ") ";
      }
      cout << endl;
    }
};


int main() {
  int n, q;
  while (cin >> n) {
    if (n == 0) return 0;
    cin >> q;

    arr in(n);

    for (int i = 0; i < n; i++) {
      int a; cin >> a; in.add(a);
    }

    in.print();
    return 0;
  }
  return 0;
}









