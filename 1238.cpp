#include <iostream>
#include <string>
#include <sstream>

using namespace std;

char op[31] = { ' ' };
int nums[31], n;
string line;


int main() {
  while (getline(cin, line)) {
    stringstream ss; ss << line;
    int i = 0; ss >> nums[i++];
    while (ss >> op[i] >> nums[i]) i++;
    n = i;



    for (int i = 0; i < n; i++) cout << nums[i] << ' ';
    cout << endl;
    for (int i = 0; i < n; i++) cout << op[i] << ' ';
    cout << endl;
  }
  return 0;
}
    
