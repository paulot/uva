#include <iostream>
#include <deque>
#include <string>

using namespace std;

deque<string> deck;
int tc;

int val(string &card) {
  if (card[0] >= '2' and card[0] <= '9') return card[0] - '0';
  return 10;
}

int main() {
  cin >> tc;
  for (int t = 1; t <= tc; t++) {
    deck.clear();
    string in;
    for (int i = 0; i < 52 - 25; i++) { cin >> in; deck.push_front(in); } 
    
    int y = 0;
    for (int i = 0; i < 3; i++) {
      string card = deck.front(); deck.pop_front();
      y += val(card);
      for (int j = 0; j < 10 - val(card); j++) deck.pop_front();
    }
    for (int i = 0; i < 25; i++) { cin >> in; deck.push_front(in); } 
    for (int i = 0; i < y - 1; i++) deck.pop_back();
    cout << "Case " << t << ": " << deck.back() << endl;
  }
  return 0;
}
