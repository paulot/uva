#include <iostream>
#define sq(a) ((a)*(a))

using namespace std;

struct circle {
  double x, y, r;
};

bool intercept(circle &c1, circle &c2) {
  long double r1 = sq(c1.r - c2.r), r2 = sq(c1.r + c2.r);
  long double dist = sq(c1.x - c2.x) + sq(c1.y - c2.y);
  return dist >= r1 and dist <= r2;
}

int sets[101], n;
circle circles[101];

int findSet(int a) { while(sets[a] != a) a = sets[a]; return a; }
void unionSet(int a, int b) {
  int sa = findSet(a), sb = findSet(b);
  for (int i = 0; i < n; i++)
    if (sets[i] == sa) sets[i] = sb;
}


int main() {
  while (cin >> n) {
    if (n == -1) return 0;
    for (int i = 0; i < n; i++) sets[i] = i;
    for (int i = 0; i < n; i++) {
      cin >> circles[i].x >> circles[i].y >> circles[i].r;
      for (int j = 0; j < i; j++)
        if (intercept(circles[j], circles[i])) unionSet(j, i);
    }

    int mcount = 0;
    for (int i = 0; i < n; i++) {
      int count = 0;
      for (int j = 0; j < n; j++)
        if (sets[j] == i) count++;
      mcount = max(count, mcount);
    }

    if (mcount == 1)
      cout << "The largest component contains " << mcount << " ring." << endl;
    else
      cout << "The largest component contains " << mcount << " rings." << endl;
  }
}
