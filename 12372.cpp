#include <iostream>

int main() {
  int c = 1, n, t1, t2, t3; std::cin >> n;
  while (n-- > 0) {
    std::cin >> t1 >> t2 >> t3;
    if (t1 > 20 || t2 > 20 || t3 > 20)
      std::cout << "Case " << c++ << ": bad" << std::endl;
    else
      std::cout << "Case " << c++ << ": good" << std::endl;
  }
  return 0;
}
