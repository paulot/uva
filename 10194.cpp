#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> split(string &str) {
  char split_char = '#';
  istringstream split(str);
  vector<string> token;

  for (string each; getline(split, each, split_char); token.push_back(each));
  return token;
}

typedef struct {
  string name;
  int wins, ties, losses;
  int gd;
  int gs;
  int gp;
  int points;
} team;

team init_team(string n) {
  team t;
  t.name = n, t.wins = 0, t.gd = 0, t.gp = 0, t.points = 0, t.ties = 0, t.losses = 0;
  return t;
}

bool compareTeams(const team &lhs, const team &rhs) {
  if (lhs.points != rhs.points) return lhs.points > rhs.points;
  if (lhs.wins != rhs.wins) return lhs.wins > rhs.wins;
  if (lhs.gd != rhs.gd) return lhs.gd > rhs.gd;
  if (lhs.gs != rhs.gs) return lhs.gs > rhs.gs;
  if (lhs.gp != rhs.gp) return lhs.gp < rhs.gp;
  return lhs.name < rhs.name;
}

int main() {
  int tc;
  string null;
  cin >> tc;
  getline(cin, null);
  while (tc--) {
    string tname;
    getline(cin, tname);
    vector<team> teams;
    map<string, int> inds;

    // Get the teams
    int n; cin >> n;
    getline(cin, null);
    for (int i = 0; i < n; i++) {
      string t; getline(cin, t);
      inds[t] = i;
      team ct = init_team(t);
      teams.push_back(ct);
    }

    // Get the games played and modify the vector
    cin >> n;
    getline(cin, null);
    for (int i = 0; i < n; i++) {
      string g; getline(cin, g);
      g[g.find('@')] = '#';
      vector<string> game = split(g);


      // Increase the number of games played
      teams[inds[game[0]]].gp++;
      teams[inds[game[3]]].gp++;

      // Increase the number of goals for and the goal differential
      teams[inds[game[0]]].gs += stoi(game[1]);
      teams[inds[game[3]]].gs += stoi(game[2]);

      teams[inds[game[0]]].gd += stoi(game[1]) - stoi(game[2]);
      teams[inds[game[3]]].gd += stoi(game[2]) - stoi(game[1]);

      // Increase number of wins
      if (stoi(game[1]) > stoi(game[2])) {
        teams[inds[game[0]]].wins++;
        teams[inds[game[3]]].losses++;
        teams[inds[game[0]]].points += 3;
      } else if (stoi(game[1]) < stoi(game[2])) {
        teams[inds[game[3]]].wins++;
        teams[inds[game[0]]].losses++;
        teams[inds[game[3]]].points += 3;
      } else {
        teams[inds[game[3]]].ties++;
        teams[inds[game[0]]].ties++;
        teams[inds[game[0]]].points += 1;
        teams[inds[game[3]]].points += 1;
      }
    }

    // Sort and print the result
    sort(teams.begin(), teams.end(), compareTeams);
    cout << tname << endl;
    for (int i = 0; i < teams.size(); i++) {
      cout << i+1 << ") " << teams[i].name << ' ' <<
        teams[i].points << "p, " << teams[i].gp << "g (" <<
        teams[i].wins << '-' << teams[i].ties << '-' << 
        teams[i].losses << "), " << teams[i].gd << "gd (" <<
        teams[i].gs-1 << '-' << teams[i].gs - teams[i].gd-1 << ')' << endl;
    }
    if (tc != 0) cout << endl;
  }
  return 0;

}
