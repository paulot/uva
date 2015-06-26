#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;
vector<stack<string> > cards;

bool can_move(string &c1, string &c2) {
  return c1[0] == c2[0] or c1[1] == c2[1];
}

bool reduce() {
  for (int i = 1; i < cards.size(); i++) {
    if (i >= 3 and can_move(cards[i].top(), cards[i-3].top())) {
      cards[i-3].push(cards[i].top());
      cards[i].pop();
      if (cards[i].empty()) cards.erase(cards.begin() + i);
      return true;
    } else if (can_move(cards[i].top(), cards[i-1].top())) {
      cards[i-1].push(cards[i].top());
      cards[i].pop();
      if (cards[i].empty()) cards.erase(cards.begin() + i);
      return true;
    }
  }
  return false;
}

void add_card(string &card) {
  stack<string> s;
  s.push(card);
  cards.push_back(s);
  while(reduce());
}

int main() {
  while (true) {
    for (int i = 0; i < 52; i++) {
      string card; cin >> card;
      if (card[0] == '#') return 0;
      add_card(card);
    }

    if (cards.size() == 1)
      cout << cards.size() << " pile remaining: ";
    else
      cout << cards.size() << " piles remaining: ";

    for (int i = 0; i < cards.size(); i++) {
      cout << cards[i].size();
      if (i != cards.size()-1) cout << ' ';
    }
    cout << endl;
    cards.clear();
  }
}















