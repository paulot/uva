#include <iostream>

int main() {
  int caseNum = 1, n, tmp;
  while (std::cin >> n) {
    if (n == 0) break;
    int balance = 0;
    while (n-- > 0) {
      std::cin >> tmp;
      if (tmp == 0) --balance;
      else ++balance;
    }
    std::cout << "Case " << caseNum++ << ": " << balance << std::endl;
  }
  return 0;
}
