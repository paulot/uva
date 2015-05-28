#include <iostream>
#include <string>

using namespace std;

int to_hs(int h, int m, int s, int c) { return (h*3600+m*60+s)*100+c; }

int to_hs(string &t) {
  return to_hs(stoi(t.substr(0,2)), stoi(t.substr(2,2)),
               stoi(t.substr(4,2)), stoi(t.substr(6,2)));
}

void to_dt(double cs) {
  string time = "0000000";
  double err = 0.0000001;
  int dh = cs/864000 + err;
  cs -= dh*864000;
  time[0] = dh;

  int dm = cs/8640 + err;
  cs -= dm*8640;
  time[1] = dm/10; time[2] = dm%10;

  int ds = cs/86.4 + err;
  cs -= 86.4*ds;
  // cout << ds << ' ' << cs  << endl;
  time[3] = ds/10; time[4] = ds%10;

  // cout << "cs0 " << cs << endl;
  cs /= 0.864;

  time[5] = cs/10 + err; time[6] = ((int) (cs+err))%10;
  for (int i = 0; i < time.size(); i++) time[i] += '0';
  cout << time << endl;
}

int main() {
  string time;
  while (cin >> time) to_dt(to_hs(time));

  return 0;
}
