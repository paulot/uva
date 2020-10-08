#include <iostream>
#include <string>

int main() {
  int n, t, balance = 0; std::cin >> n;
  std::string in;
  while (n-- > 0) {
    std::cin >> in;
    if (in[0] == 'r') {
      std::cout << balance << std::endl;
    } else {
      std::cin >> t;
      balance += t;
    } 
  }
  return 0;
}
