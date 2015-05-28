#include <iostream>
#include <cstdio>

using namespace std;

int dp[10000001];


/*
int cl(int n) {
  if (n == 1) return 1;
  if (dp[n] != 0) return dp[n];
  n = (n % 2) ? (3*n+1) : n/2;
  dp[n] = 1+cl(n);
  return dp[n];
}
*/

int cl(int n) {
  int l = 1;
  while (n != 1) n = (n % 2) ? (3*n+1) : n/2, l++;
  return l;
}

int mcl(int a, int b) {
  int m = 0;
  for (; a <= b; a++) m = max(m, cl(a));
  return m;
}

int main() {
  int a,b;
  while (scanf("%d %d\n", &a, &b) == 2) {
    printf("%d %d %d\n", a, b, mcl(min(a,b), max(a,b)));
  }
  return 0;
}


