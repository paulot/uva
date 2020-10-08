#include <iostream>
#include <string>

unsigned char bytes[101];

int main() {
  int t; std::cin >> t;
  std::string code;

  for (int ii = 1; ii <= t; ++ii) {
    for (int i = 0; i < 101; ++i) bytes[i] = 0;
    std::cin >> code;

    int ptr = 0;
    for (int i = 0; i < code.size(); ++i) {
      if (code[i] == '>') ptr = (ptr + 1) % 100;
      else if (code[i] == '<') ptr = (ptr == 0) ? 99 : ptr - 1;
      else if (code[i] == '+') ++bytes[ptr];
      else if (code[i] == '-') --bytes[ptr];
    }

    std::cout << "Case " << ii << ":";
    for (int i = 0; i < 100; ++i) {
      printf(" %02X", bytes[i]);
    }
    std::cout << std::endl;
  }
  return 0;
}
