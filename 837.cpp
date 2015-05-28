#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

typedef tuple<double, double, double> iii;

double coef(vector<iii> &lines, double x) {
  double c = 1;
  for (int i = 0; i < lines.size(); i++) {
    if (x >= get<0>(lines[i]) and x < get<1>(lines[i])) {
      c *= get<2>(lines[i]);
    }
  }
  return c;
}


int main() {
  double d = 0.000001;
  int t;
  cin >> t;

  while(t--) {
    int n;
    vector<double> xvals;
    vector<iii> lines;
    cin >> n;

    for (int i = 0; i < n; i++) {
      double x1,y1,x2,y2,c;
      cin >> x1 >> y1 >> x2 >> y2 >> c;
      xvals.push_back(x1); xvals.push_back(x2);
      lines.push_back(make_tuple(min(x1,x2), max(x1,x2), c));
    }
    
    sort(xvals.begin(), xvals.end());

    cout << xvals.size() + 1 << endl;
    printf("%s %.3f %.3f\n", "-inf", xvals[0], 1.0);
    for (int i = 0; i < xvals.size()-1; i++) {
      printf("%.3f %.3f %.3f\n", xvals[i], xvals[i+1], coef(lines, xvals[i] + d));
    }
    printf("%.3f %s %.3f\n",  xvals[xvals.size()-1], "+inf", 1.0);
    if (t != 0) cout << endl;
  }


  return  0;
}

