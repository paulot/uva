#include <iostream>
#include <string>

using namespace std;

int t;
string in;

int main() {
  cin >> t;
  for (int b = 0; b < t; b++) {
    cin >> in;
    if (in == "1" or in == "4" or in == "78") cout << '+' << endl;
    else if (in.size() >= 2 and in[in.size()-2] == '3' and in[in.size()-1] == '5') cout << '-' << endl;
    else if (in[0] == '9' and in[in.size() - 1] == '4') cout << '*' << endl;
    else cout << '?' << endl;
  }
  return 0;
}
