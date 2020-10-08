#include <iostream>
#include <string>

char one[] = "one";

bool isOne(const std::string& word) {
  int mistakes = 0;

  for (int i = 0; i < word.size(); i++) {
    if (word[i] != one[i]) ++mistakes;
  }
  return mistakes <= 1;
}

int main() {
  int n;
  std::cin >> n;
  std::string word;
  while (n-- > 0) {
    std::cin >> word;
    if (word.size() == 3) {
      if (isOne(word)) std::cout << 1 << std::endl;
      else std::cout << 2 << std::endl;
    } else {
      std::cout << 3 << std::endl;
    }
  }
}
