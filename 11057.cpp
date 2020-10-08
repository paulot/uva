#include <iostream>
#include <algorithm>

using namespace std;

int n, books[10001], s, t;

int main() {
  while (cin >> n) {
    for (int i = 0; i < n; i++) cin >> books[i];
    sort(books, books + n);
    cin >> s;

    int diff = 1000000, fir = -1, sec = -1, ind;

    for (int i = 0; i < n; i++) {
      ind = lower_bound(books, books + n, s - books[i]) - books;

      if (ind != i and ind != n and books[i] + books[ind] == s and abs(books[i] - books[ind]) < diff) {
        fir = books[i]; sec = books[ind]; diff = abs(fir - sec);
      }
    }
    cout << "Peter should buy books whose prices are " << fir << " and " << sec << "." << endl << endl;
  }
  return 0;
}
