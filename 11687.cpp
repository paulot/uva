#include <string>
#include <iostream>

int main() {
  std::string in, tmp;
  while(std::cin >> in) {
    if (in[0] == 'E') break;
    int i = 1;
    tmp = std::to_string(in.size());
    while (tmp != in) {
      in = tmp;
      tmp = std::to_string(tmp.size());
      ++i;
    }
    std::cout << i << std::endl;
  }
  return 0;
}
