#include <iostream>
#include <queue>
#include <functional>

int rates[101], weights[2001], r, w, cars[2001];

int main() {
  unsigned long long revenue = 0;
  std::priority_queue<int> spots;
  std::cin >> r >> w;
  for (int i = 1; i <= r; ++i) {
    spots.push(-i);
    std::cin >> rates[i];
  }
  for (int i = 1; i <= w; ++i) {
    std::cin >> weights[i];
  }

  std::queue<int> arrivals;
  int car;
  for (int i = 0; i < 2*w; ++i) {
    std::cin >> car;
    if (car > 0) {
      // adding a car
      if (spots.empty()) {
        // no spot for this car
        arrivals.push(car);
      } else {
        // There is a spot
        int spot = spots.top() * -1;
        spots.pop();
        cars[car] = spot;
        revenue += weights[car] * rates[spot];
      }
    } else {
      // removing a car
      car = car * -1;
      int spot = cars[car];

      if (!arrivals.empty()) {
        // another car needs this spot
        car = arrivals.front();
        arrivals.pop();
        cars[car] = spot;
        revenue += weights[car] * rates[spot];
      } else {
        spots.push(-spot);
      }
    }
  }
  std::cout << revenue << std::endl;
  return 0;
}
