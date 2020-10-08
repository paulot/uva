#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long

using namespace std;

typedef pair<int, char> ic;

struct compare {
  inline bool operator() (const ic& card1, const ic& card2) {
    return card1.first < card2.first;
  }
} compare;

ic white[5], black[5];
int groups[15];
char a, b;

int convert(char a) {
  if (a == 'T') return 10;
  if (a == 'J') return 11;
  if (a == 'Q') return 12;
  if (a == 'K') return 13;
  if (a == 'A') return 14;
  return a - '0';
}

bool isFlush(ic hand[5]) {
  for (int i = 1; i < 5; i++) if (hand[i].second != hand[i-1].second) return false;
  return true;
}

bool isStraight(ic hand[5]) {
  for (int i = 1; i < 5; i++) if (hand[i].first != hand[i-1].first + 1) return false;
  return true;
}

ic getHighCard(ic hand[5]) {
  return hand[4];
}

void group(ic hand[5]) {
  for (int i = 0; i < 5; i++) groups[hand[i].first]++;
}

int getCombo(int num) {
  for (int i = 0; i < 15; i++) if (groups[i] == num) return i;
  return 0;
}

int twoPair() {
  int np = 0, bp = 0;
  for (int i = 0; i < 15; i++) if (groups[i] == 2) { np++; bp = i; }
  return (np == 2) ? bp : 0;
}

ll rolldownScore(ic hand[5]) {
  ll s = 0;
  for (int i = 4; i >= 0; i--) { s *= 100; s += hand[i].first; }
  return s;
}

ll rolldownGroup(int n) {
  ll s = 0;
  for (int i = 14; i >= 0; i--) 
    if (groups[i] == n) { s *= 100; s += i; }

  return s;
}

ll score(ic hand[5]) {
  memset(groups, 0, sizeof(groups));
  group(hand);

  if (isFlush(hand) and isStraight(hand)) return ((ll) 80000000000) + getHighCard(hand).first;
  if (getCombo(4)) return ((ll) 70000000000) + getCombo(4) * 100 + rolldownGroup(1);
  if (getCombo(2) and getCombo(3)) return ((ll) 60000000000) + getCombo(3) * 100 + getCombo(2);
  if (isFlush(hand)) return ((ll) 50000000000) + rolldownScore(hand);
  if (isStraight(hand)) return ((ll) 40000000000) + getHighCard(hand).first;
  if (getCombo(3)) return ((ll) 30000000000) + getCombo(3) * 1000000 + rolldownGroup(1);
  if (twoPair()) return ((ll) 20000000000) + twoPair() * 10000 + getCombo(2) * 100 + rolldownGroup(1);
  if (getCombo(2)) return ((ll) 10000000000) + getCombo(2) * 100000000 + 1 + rolldownGroup(1);
  else return rolldownGroup(1);
}

void battle() {
  ll blackScore = score(black);
  ll whiteScore = score(white);

  if (whiteScore > blackScore) cout << "White wins." << endl;
  else if (blackScore > whiteScore) cout << "Black wins." << endl;
  else cout << "Tie." << endl;
}

int main() {
  while (cin >> a >> b) { black[0] = make_pair(convert(a), b);
    for (int i = 1; i < 5; i++) { cin >> a >> b; black[i] = make_pair(convert(a), b); }
    for (int i = 0; i < 5; i++) { cin >> a >> b; white[i] = make_pair(convert(a), b); }
    sort(white, white + 5, compare);
    sort(black, black + 5, compare);
    battle();
  }
  return 0;
}
