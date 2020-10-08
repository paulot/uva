#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#define get(n, i) ((n / ((int) pow(10, ((int) log10(n)) - i))) % 10)

using namespace std;

bool visited[10], present[10];
int t, num;

bool all_unique(int n) {
  memset(present, 0, sizeof(present));
  while (n) {
    if (present[n % 10]) return false;
    else present[n % 10] = true;
    n /= 10;
  }
  return true;
}

bool is_runaround(int n) {
  memset(visited, 0, sizeof(visited));
  int size = log10(n) + 1, total = 0, pos = 0;

  while (not visited[pos]) { visited[pos] = true;
    pos = (pos + get(n, (pos))) % size;
    total++;
  }

  return total == size and pos == 0;
}

int main() {
  while (cin >> num and num != 0) {
    t++;
    for (int i = num; i < 987654321; i++)
      if (all_unique(i) and is_runaround(i)) { cout << "Case " << t << ": " << i << endl; break; }
  }
  return 0;
}
