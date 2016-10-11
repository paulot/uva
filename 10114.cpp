#include <iostream>
#include <cstring>

using namespace std;

int duration, n, m;
double total_loan, down_pay, dep[101], car_value, d;

/**
 * It is entirely unclear from the problem statement how the depreciation is calculated and
 * how it is applied to the price of the car. Moreover, it is unclear that one of the values coming
 * in is the down payment, rather than the monthly payment for the car. After this is cleared,
 * the problem is quite simple and easy.
 */

int main() {
  while (cin >> duration >> down_pay >> total_loan >> n and duration > 0) {
    for (int i = 0; i < n; i++) {
      cin >> m >> d;
      for (int j = m; j < 101; j++) dep[j] = d;
    }
    double monthly_pay = total_loan / duration; 
    car_value = (total_loan + down_pay) * (1 - dep[0]);
    int month = 0;

    while (total_loan > car_value) {
      month++;
      total_loan -= monthly_pay;
      car_value *= 1 - dep[month];
    }
    if (month == 1) cout << month << " month" << endl;
    else cout << month << " months" << endl;
  }
  return 0;
}
