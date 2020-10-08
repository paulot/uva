#include <iostream>

using namespace std;

int median(int a[], int n) {
  if (n % 2 == 0) return (a[n/2] + a[n/2 - 1]) / 2;
  else return a[n/2];
}

double medianOfTwo(int a[], int b[], int n) {
  if (n == 0) return -1;
  if (n == 1) return (a[0] + b[0]) / 2.0;
  if (n == 2) return (max(a[0], b[0]) + min(a[1], b[1])) / 2.0;

  int m1 = median(a, n), m2 = median(b, n);
  if (m1 == m2) return m1;
  if (m1 < m2) return (n % 2 == 0) ? medianOfTwo(a + n / 2 - 1, b, n - n / 2 + 1) :
                                     medianOfTwo(a + n / 2, b, n - n / 2);
  else return (n % 2 == 0) ? medianOfTwo(a, b + n / 2 - 1, n - n / 2 + 1) :
                             medianOfTwo(a, b + n / 2, n - n / 2);
}

int main() {
 // int ar1[] = {1, 2, 3, 6};
 // int ar2[] = {4, 6, 8, 10};
 int ar1[] = {1, 5, 6, 8};
 int ar2[] = {2, 4, 80, 90};
 int n1 = sizeof(ar1)/sizeof(ar1[0]);
 int n2 = sizeof(ar2)/sizeof(ar2[0]);
 cout << medianOfTwo(ar1, ar2, n1) << endl;
 return 0;
}



















































double medianOfTwo2(int a[], int b[], int n) {
  if (n <= 0) return -1;
  if (n == 1) return ((double) a[0] + b[0]) / 2;
  if (n == 2) return ((double) max(a[0], b[0]) + min(a[1], b[1])) / 2;

  int m1 = median(a, n), m2 = median(b, n);
  if (m1 == m2) return m1;
  else if (m1 < m2) return (n % 2 == 0) ? medianOfTwo(a + n / 2 - 1, b, n - n / 2 + 1) :
                                          medianOfTwo(a + n / 2, b, n - n / 2);
  else return (n % 2 == 0) ? medianOfTwo(b + n / 2 - 1, a, n - n / 2 + 1) :
                             medianOfTwo(b + n / 2, a, n - n / 2);

}
