#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

char alph[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M',
               'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
               '0','1','2','3','4','5','6','7','8','9','.',',','?',
               '\'','!','/','(',')','&',':',';','=','+','-','_','"',
               '@'};
string morse[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                  ".---","-.-",".-..","--","-.","---",".--.","--.-",".-.",
                  "...","-","..-","...-",".--","-..-","-.--","--..","-----",
                  ".----","..---","...--","....-",".....","-....","--...","---..","----.",
                  ".-.-.-","--..--","..--..",".----.","-.-.--","-..-.","-.--.","-.--.-",".-...",
                  "---...","-.-.-.","-...-",".-.-.","-....-","..--.-",".-..-.",".--.-."};

map<string, char> decode;

int main() {
  for (int i = 0; i < 53; i++) decode[morse[i]] = alph[i];
  int n;
  cin >> n;
  string null;
  getline(cin, null);
  for (int i = 1; i <= n; i++) {
    cout << "Message #" << i << endl;
    string line;
    char c;
    char last;
    while (true) {
      if (not cin.get(c) or c == '\n') {
        cout << decode[line];
        break;
      } else if (c == ' ') {
        if (last == ' ') cout << ' ';
        else cout << decode[line];
        line = "";
      } else {
        line += c;
      }
      last = c;
    }
    cout << endl;
    if (i < n) cout << endl;
  }

  // for (int i = 0; i < 53; i++) cout << morse[i]<<endl;

  return 0;
}

