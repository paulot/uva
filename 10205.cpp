#include <iostream>
#include <string>

using namespace std;

int deals[101][53], n, tc;

void printCard(int card[2]) {
  if (card[0] <= 10) cout << card[0] << ' ';
  else {
    if (card[0] == 11) cout << "Jack ";
    else if (card[0] == 12) cout << "Queen ";
    else if (card[0] == 13) cout << "King ";
    else if (card[0] == 14) cout << "Ace ";
  } cout << "of ";

  if (card[1] == 1) cout << "Clubs" << endl;
  else if (card[1] == 2) cout << "Diamonds" << endl;
  else if (card[1] == 3) cout << "Hearts" << endl;
  else if (card[1] == 4) cout << "Spades" << endl;
}

int main() {
  cin >> tc;
  while (tc--) {
    cin >> n;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= 52; j++) cin >> deals[i][j];

    int deck1[53][2], deck2[53][2], p = 1;
    for (int s = 1; s <= 4; s++) for (int i = 2; i <= 14; i++) { deck1[p][0] = i; deck1[p][1] = s; p++; }

    int (*oldDeck)[2] = deck1, (*newDeck)[2] = deck2, (*tmp)[2];
    int shuffle;

    string line; getline(cin, line);

    while (getline(cin, line) and line.size() > 0) {
      shuffle = stoi(line);
      for (int i = 1; i <= 52; i++) {
        newDeck[i][0] = oldDeck[deals[shuffle][i]][0];
        newDeck[i][1] = oldDeck[deals[shuffle][i]][1];
      }
      tmp = newDeck;
      newDeck = oldDeck;
      oldDeck = tmp;
    }

    for (int i = 1; i <= 52; i++) {
      printCard(oldDeck[i]);
    }

    if (tc) cout << endl;
  }
  return 0;
}
