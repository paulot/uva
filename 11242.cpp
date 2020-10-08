#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

int front[11], nf, back[11], nb, nr;
double ratios[200];

int main() {
  while (cin >> nf and nf) { cin >> nb;
    for (int i = 0; i < nf; i++) cin >> front[i];
    for (int i = 0; i < nb; i++) cin >> back[i];
    nr = 0;
    for (int i = 0; i < nf; i++) for (int j = 0; j < nb; j++) {
      ratios[nr++] = ((double) back[j]) / front[i];
    }

    sort(ratios, ratios + nr);

    int best = 0;
    for (int i = 1; i < nr; i++) best = max(best, (int) round(((ratios[i] / ratios[i - 1]) * 100)));
    printf("%.2f\n", (best / 100.0));
  }
  return 0;
}
