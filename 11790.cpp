#include <iostream>

using namespace std;

int heights[100000], widths[100000], lisup[100000], lisdown[100000], n;

int main() {
  int tcn; cin >> tcn;
  for (int tc = 1; tc <= tcn; tc++) {
    cin >> n;
    int lup = 0, ldown = 0;
    for (int i = 0; i < n; i++) cin >> heights[i];
    for (int i = 0; i < n; i++) 
      cin >> widths[i], lisup[i] = lisdown[i] = widths[i], lup = ldown = max(ldown, widths[i]);

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (heights[j] < heights[i] and lisup[i] < lisup[j] + widths[i]) {
          lisup[i] = lisup[j] + widths[i], lup = max(lup, lisup[i]);
        } else if (heights[j] > heights[i] and lisdown[i] < lisdown[j] + widths[i]) {
          lisdown[i] = lisdown[j] + widths[i], ldown = max(ldown, lisdown[i]);
        }
      }
    }

    if (lup >= ldown) 
      cout << "Case " << tc << ". Increasing (" << lup <<
        "). Decreasing ("<< ldown <<")." << endl;
    else 
      cout << "Case " << tc << ". Decreasing (" << ldown <<
        "). Increasing (" << lup << ")." << endl;
  }
}



