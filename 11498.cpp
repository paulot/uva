#include <iostream>

using namespace std;

int main() {
  while (true) {
    int tc;
    cin >> tc; 
    if (tc == 0) break;
    int dx, dy;
    cin >> dx >> dy;

    int x, y;
    for (int i = 0; i < tc; i++) {
      cin >> x >> y;
      if (x == dx or y == dy) cout << "divisa\n";
      else if (x > dx and y > dy) cout << "NE\n";
      else if (x < dx and y > dy) cout << "NO\n";
      else if (x > dx and y < dy) cout << "SE\n";
      else if (x < dx and y < dy) cout << "SO\n";
    }
  }
  return 0;
}
