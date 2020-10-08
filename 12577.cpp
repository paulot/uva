#include <iostream>
#include <string>

int main() {
  std::string in; int i = 1;
  while (std::cin >> in) {
    if (in[0] == '*') break;
    else if (in[0] == 'H')
      std::cout << "Case " << i++ << ": Hajj-e-Akbar" << std::endl;
    else if (in[0] == 'U')
      std::cout << "Case " << i++ << ": Hajj-e-Asghar" << std::endl;
  }
  return 0;
}
