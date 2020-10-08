#include <iostream>
#include <set>

using namespace std;

template <class T>
class PriorityQueue {
  public:
    PriorityQueue() {}

    void insert(int priority, T &item) {
      this->queue.insert(make_pair(-priority, item));
    }

    T pop() {
      if (this->queue.size() >= 1) {
        T item = (*this->queue.begin()).second;
        this->queue.erase(this->queue.begin());
        return item;
      } else {
        throw length_error("Set is empty");
      }
    }

  private:
    set<pair<int, T> > queue;
};

int main() {
  PriorityQueue<int> bla;
  for (int i = 0; i < 100; i++) {
    bla.insert(-i, i);
  }
  for (int i = 0; i < 100; i++) {
    cout << bla.pop() << endl;
  }
  return 0;
}
