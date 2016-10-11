#include <iostream>
#include <string>

using namespace std;

string bla;
int i = 1;

int main() {
  while (cin >> bla and bla != "#") {
    if (bla == "HELLO") cout << "Case " << i << ": ENGLISH" << endl;
    else if (bla == "HOLA") cout << "Case " << i << ": SPANISH" << endl;
    else if (bla == "HALLO") cout << "Case " << i << ": GERMAN" << endl;
    else if (bla == "BONJOUR") cout << "Case " << i << ": FRENCH" << endl;
    else if (bla == "CIAO") cout << "Case " << i << ": ITALIAN" << endl;
    else if (bla == "ZDRAVSTVUJTE") cout << "Case " << i << ": RUSSIAN" << endl;
    else cout << "Case " << i << ": UNKNOWN" << endl;
    i++;
  }
  return 0;
}
