#include <iostream>
#include <cmath>
#include <map>
#include <string>
#define sq(a) ((a)*(a))
#define ss 0.000001
#define s 0.001
#define ll unsigned long long

using namespace std;

unsigned int sides[6];

ll dist(int xa, int ya, int xb, int yb) {
  return sq(xb-xa)+sq(yb-ya);
}

bool isort(int xa, int ya, int xb, int yb, int xc, int yc) {
  return (xb-xa)*(xb-xc)+(yb-ya)*(yb-yc) == 0;
}

bool ispar(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
  double ab = (ya-yb)/((double)(xa-xb)), cd = (yc-yd)/((double)(xc-xd));
  return ab == cd or fabs(ab-cd) <= ss;
  // return ab == cd or fabs((ya-yb)/((double)(xa-xb)+ss) - (yc-yd)/((double)(xc-xd)+ss)) <= s;
}

bool ispar2(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
  return ispar(xa, ya, xb, yb, xc, yc, xd, yd) 
    and ispar(xa, ya, xc, yc, xb, yb, xd, yd);

  // return fabs((ya-yb)/((double)(xa-xb)+ss) - (yc-yd)/((double)(xc-xd)+ss)) <= s
  //   and fabs((ya-yc)/((double)(xa-xc)+ss) - (yb-yd)/((double)(xb-xd)+ss)) <= s;
}

bool isp2(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
  return ispar2(xa, ya, xb, yb, xc, yc, xd, yd) || ispar2(xa, ya, xc, yc, xd, yd, xb, yb) || 
         ispar2(xa, ya, xd, yd, xb, yb, xc, yc); 
}

bool isp(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
  return ispar(xa, ya, xb, yb, xc, yc, xd, yd) || ispar(xa, ya, xc, yc, xd, yd, xb, yb) || 
         ispar(xa, ya, xd, yd, xb, yb, xc, yc); 
}

bool isr(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
  return isort(xa,ya,xb,yb,xc,yc) and isort(xb,yb,xc,yc,xd,yd) and 
         isort(xc,yc,xd,yd,xa,ya);
}

bool isra(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
  return isr(xa, ya, xb, yb, xc, yc, xd, yd) or isr(xb, yb, xc, yc, xa, ya, xd, yd) or 
         isr(xc, yc, xa, ya, xb, yb, xd, yd);
}

bool issames(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
  return dist(xa,ya,xb,yb) == dist(xb,yb,xc,yc) 
    and dist(xb,yb,xc,yc) == dist(xc,yc,xd,yd)
    and dist(xb,yb,xc,yc) == dist(xd,yd,xa,ya);
}

bool allsame(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
  return issames(xa, ya, xb, yb, xc, yc, xd, yd) 
    or issames(xb, yb, xc, yc, xa, ya, xd, yd) 
    or issames(xc, yc, xa, ya, xb, yb, xd, yd);
}

string check(int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
  if (allsame(xa, ya, xb, yb, xc, yc, xd, yd)
      and isra(xa, ya, xb, yb, xc, yc, xd, yd)) return "Square";
  if (isra(xa, ya, xb, yb, xc, yc, xd, yd)) return "Rectangle";
  if (isp2(xa, ya, xb, yb, xc, yc, xd, yd)) 
    return (allsame(xa, ya, xb, yb, xc, yc, xd, yd)) ? "Rhombus" : "Parallelogram";
  if (isp(xa, ya, xb, yb, xc, yc, xd, yd)) 
    return "Trapezium";

  return "Ordinary Quadrilateral";
}

int main() {
  int n;
  cin >> n;
  for (int t = 1; t <= n; t++) {
    int xa, ya, xb, yb, xc, yc, xd, yd;
    cin >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
    cout << "Case " << t << ": " << check(xa, ya, xb, yb, xc, yc, xd, yd) << endl;
  }

  return 0;
}

/*
ll sf(ll n) { return n * 100000; }
ll gf(ll n) { return n/100000; }
ll gs(ll n) { return n%100000; }
ll flip(ll n) { return sf(gs(n))+gf(n); }

ll slope(int xa, int ya, int xb, int yb) {
  return sf(ya - yb)+(xa - xb);
}
  ll slopes[6];
  slopes[0] = slope(xa,ya,xb,yb); slopes[1] = slope(xb,yb,xc,yc);
  slopes[2] = slope(xc,yc,xd,yd); slopes[3] = slope(xd,yd,xa,ya);
  slopes[4] = slope(xa,ya,xc,yc); slopes[5] = slope(xb,yb,xd,yd);
  */
