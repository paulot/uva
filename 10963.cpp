#include <iostream>

int main() {
  int tc, w, t1, t2, e;
  std::cin >> tc;
  while (tc-- > 0) {
    std::cin >> w;
    --w; std::cin >> t1 >> t2;
    e = t1 - t2;
    bool possible = true;
    while (w-- > 0) {
      std::cin >> t1 >> t2;
      if (t1 - t2 != e) possible = false;
    }
    if (possible) std::cout << "yes" << std::endl;
    else std::cout << "no" << std::endl;
    if (tc) { std::cout << std::endl; }
  }
  return 0;
}
