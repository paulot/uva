#include <iostream>
#include <string>
#include <cstdio>

int val(const std::string& w) {
  int sum = 0;
  for (int i = 0; i < w.size(); ++i) {
    if (!std::isalpha(w[i])) {
      continue;
    }

    sum += std::tolower(w[i]) - 'a' + 1;
  }
  while (sum/10 != 0) {
    int newsum = 0;
    for (int tmp = sum; tmp > 0; newsum += tmp%10, tmp /= 10);
    sum = newsum;
  }
  return sum;
}

int main() {
  std::string w1, w2;
  while(std::getline(std::cin, w1)) {
    std::getline(std::cin, w2);
    int v1 = val(w1), v2 = val(w2);
    if (v1 == v2) {
      printf("100.00 %%\n");
    } else if (v1 > v2) {
      printf("%.2f %%\n", 100 * ((double) v2) / v1);
    } else {
      printf("%.2f %%\n", 100 * ((double) v1) / v2);
    }
  }
  return 0;
}
