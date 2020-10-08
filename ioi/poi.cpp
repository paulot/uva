#include <iostream>

int n, t, p, problem_pts[2001], student_pts[2001], student_num_tasks[2001],
    rank;
bool solved[2001][2001];

int main() {
  std::cin >> n >> t >> p;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= t; ++j) {
      std::cin >> solved[i][j];
      problem_pts[j] += !solved[i][j];
      student_num_tasks[i] += solved[i][j];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= t; ++j) {
      if (solved[i][j]) {
        student_pts[i] += problem_pts[j];
      }
    }
  }

  int more = 1;
  for (int i = 1; i <= n; ++i) {
    if (i == p)
      continue;
    if (student_pts[i] > student_pts[p]) {
      ++more;
    } else if (student_pts[i] == student_pts[p] &&
               student_num_tasks[i] > student_num_tasks[p]) {
      ++more;
    } else if (student_pts[i] == student_pts[p] &&
               student_num_tasks[i] == student_num_tasks[p] && i < p) {
      ++more;
    }
  }
  std::cout << student_pts[p] << ' ' << more << std::endl;
  return 0;
}
