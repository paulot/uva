#include <iostream>
#include <string>

using namespace std;

char deck[4][13][2], dealer, pos[4] = { 'S', 'W', 'N', 'E' }, suits[4] = { 'C', 'D', 'S', 'H' };
string order = "23456789TJQKAN";
int dealerPos;


int main() {
  while (cin >> dealer) { if (dealer == '#') return 0;
    if (dealer == 'S') dealerPos = 0;
    if (dealer == 'W') dealerPos = 1;
    if (dealer == 'N') dealerPos = 2;
    if (dealer == 'E') dealerPos = 3;
    for (int i = 0; i < 13; i++)
      for (int player = 1; player <= 4; player++)
        for (int j = 0; j < 2; j++) cin >> deck[(dealerPos + player) % 4][i][j];

    for (int player = 0; player < 4; player++) {
      cout << pos[player] << ": ";
      bool printed[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
      int np = 0;
      for (int suit = 0; suit < 4; suit++) {
        for (int j = 0; j < 13; j++) {
          char match = 'N';
          int pos = -1;
          for (int i = 0; i < 13; i++) {
            if (not printed[i] and suits[suit] == deck[player][i][0] and order.find(match) > order.find(deck[player][i][1])) {
              pos = i; match = deck[player][i][1];
            }
          }
          if (match != 'N') { cout << suits[suit] << match; printed[pos] = true; np++; if (np != 13) cout << ' '; }
        }
      }
      cout << endl;
    }
  }
  return 0;
}
