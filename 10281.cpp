#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

int get_sec(int h, int m, int s) { return h*3600+m*60+s; }
int get_sec(string &str_time) {
  int i = 0, time[3];
  string word;
  stringstream stream(str_time);
  while (getline(stream, word, ':')) time[i++] = stoi(word);
  return get_sec(time[0], time[1], time[2]);
}

double get_dist(int sec1, int sec2, double speed) {
  int sec = sec2-sec1;
  return (sec/3600.0) * speed;
}

int main() {
  string line;
  char c;

  int lc = 0;
  double cs = 0, td = 0;
  while ((cin >> line).get(c)) {
    switch (c) {
      case '\n':
        cout << line << ' ' << fixed << setprecision(2) 
             << td + get_dist(lc, get_sec(line), cs) << " km" << endl;
        break;
      default:
        td += get_dist(lc, get_sec(line), cs);
        lc = get_sec(line);
        cin >> cs;
        break;
    }
  }

  return 0;
}
