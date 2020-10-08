#include <iostream>
#include <string>
#include <deque>
#include <cstdio>

using namespace std;

deque<char> deck[2], pile;
string in;

int cover(char card, int toCover) {
  char played;
  int num = 0;
  int winner = (toCover + 1) % 2;
  if (card == 'J') num = 1;
  else if (card == 'Q') num = 2;
  else if (card == 'K') num = 3;
  else if (card == 'A') num = 4;
  for (int i = 0; i < num; i++) {
    if (deck[toCover].empty()) { return ((toCover + 1) % 2) + 2; }

    played = deck[toCover].front(); deck[toCover].pop_front();
    pile.push_front(played);
    if (played == 'J' or played == 'Q' or played == 'K' or played == 'A') {
      return cover(played, (toCover + 1) % 2); 
    }
  }
  return winner;
}

void play() {
  int i = 1;
  while (true) {
    if (deck[i].empty()) { printf("%d%3d\n", ((i + 1) % 2) + 1, deck[(i + 1) % 2].size()); return; }

    char card = deck[i].front(); deck[i].pop_front();
    pile.push_front(card);

    if (card == 'J' or card == 'Q' or card == 'K' or card == 'A') {
      int winner = cover(card, (i + 1) % 2);

      if (winner >= 2) {
        printf("%d%3d\n", winner - 1, deck[winner - 2].size());
        return;
      }

      while (not pile.empty()) { deck[winner].push_back(pile.back()); pile.pop_back(); }
      i = winner;
    } else {
      i = (i + 1) % 2;
    }
  }
}

int main() {
  cout.width(3);
  while (cin >> in) {
    if (in == "#") return 0;
    deck[0].clear(); deck[1].clear(); pile.clear();
    deck[1].push_front(in[1]);
    cin >> in;
    deck[0].push_front(in[1]);

    for (int i = 0; i < 25; i++) {
      for (int j = 1; j >= 0; j--) {
        cin >> in;
        deck[j].push_front(in[1]);
      }
    }

    play();
  }
}
