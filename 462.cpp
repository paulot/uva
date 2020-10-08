#include <iostream>
#include <string>

using namespace std;

string cards[13];
int suits[30];
int suitEnum[4] = { 'S' - 'A', 'H' - 'A', 'D' - 'A', 'C' - 'A' };


int rule1() {
  int total = 0;
  for (int i = 0; i < 13; i++) {
    if (cards[i][0] == 'A') total += 4;
    if (cards[i][0] == 'K') total += 3;
    if (cards[i][0] == 'Q') total += 2;
    if (cards[i][0] == 'J') total += 1;
  }
  return total;
}

int rule234() {
  int total = 0;
  for (int i = 0; i < 13; i++) {
    if (cards[i][0] == 'K' and suits[cards[i][1] - 'A'] == 1) total -= 1;
    if (cards[i][0] == 'Q' and suits[cards[i][1] - 'A'] <= 2) total -= 1;
    if (cards[i][0] == 'J' and suits[cards[i][1] - 'A'] <= 3) total -= 1;
  }
  return total;
}

int rule567() {
  int total = 0;
  for (int i = 0; i < 4; i++) {
    if (suits[suitEnum[i]] == 2) total += 1;
    if (suits[suitEnum[i]] == 1) total += 2;
    if (suits[suitEnum[i]] == 0) total += 2;
  }
  return total;
}

bool hasCard(char card, char suit) {
  for (int i = 0; i < 13; i++) if (cards[i][0] == card and cards[i][1] == suit) return true;
  return false;
}

bool isStopped(char suit) {
  if (hasCard('A', suit)) return true;
  if (hasCard('K', suit) and suits[suit - 'A'] >= 2) return true;
  if (hasCard('Q', suit) and suits[suit - 'A'] >= 3) return true;
  return false;
}

bool allStopped() {
  char csuits[] = { 'D', 'H', 'C', 'S' };
  for (int i = 0; i < 4; i++) if (not isStopped(csuits[i])) return false;
  return true;
}

char mostCards() {
  char csuits[] = { 'S', 'H', 'D', 'C' };
  char most;
  int num = 0;
  for (int i = 0; i < 4; i++) if (suits[csuits[i] - 'A'] > num) { most = csuits[i]; num = suits[csuits[i] - 'A']; }
  return most;
}

int main() {
  while (cin >> cards[0]) {
    for (int i = 1; i < 13; i++) cin >> cards[i];
    for (int i = 0; i < 30; i++) suits[i] = 0;
    for (int i = 0; i < 13; i++) suits[cards[i][1] - 'A']++;

    if (rule1() + rule234() >= 16 and allStopped()) cout << "BID NO-TRUMP" << endl;
    else if (rule1() + rule234() + rule567() >= 14) cout << "BID " << mostCards() << endl;
    else cout << "PASS" << endl;
  }
  return 0;
}
