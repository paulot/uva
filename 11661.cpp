#include <iostream>
#include <string>
#include <climits>

int l;

int main() {
  std::string hwy;
  while (std::cin >> l) {
    if (l == 0) break;
    std::cin >> hwy;
    int lr = -1, ld = -1, m = INT_MAX;
    for (int i = 0; i < hwy.size(); ++i) {
      if (hwy[i] == '.') {
        continue;
      } else if (hwy[i] == 'Z') {
        m = 0;
      } else if (hwy[i] == 'R') {
        lr = i;
        if (ld != -1) m = std::min(m, i - ld);
      } else if (hwy[i] == 'D') {
        ld = i;
        if (lr != -1) m = std::min(m, i - lr);
      }
    }
    std::cout << m << std::endl;
  }
  return 0;
}
