#include <iostream>
#include <string>
#include <set>
#include <map>

int numCourses, numCategories;

int main() {

  while (std::cin >> numCourses) {
    if (numCourses == 0) break;
    std::cin >> numCategories;
    std::set<std::string> courses;
    std::string course;
    for (int i = 0; i < numCourses; ++i) {
      std::cin >> course;
      courses.insert(course);
    }
    bool valid = true;

    while (numCategories-- > 0) {
      int n, m;
      std::cin >> n >> m;
      while (n-- > 0) {
        std::cin >> course;
        if (courses.find(course) != courses.end()) {
          --m;
        }
      }
      if (m > 0) {
        valid = false;
      }
    }
    if (valid) {
      std::cout << "yes\n";
    } else {
      std::cout << "no\n";
    }
  }
  return 0;
}
