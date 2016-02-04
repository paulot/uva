#include <iostream>
#include <cstring>

using namespace std;

char map[27][27];
bool visited[27][27];
int n, test = 1;

void fill(int i, int j) {
  visited[i][j] = true;
  if (map[i-1][j] == '1' and not visited[i-1][j]) fill(i-1, j);
  if (map[i][j-1] == '1' and not visited[i][j-1]) fill(i, j-1);
  if (map[i+1][j] == '1' and not visited[i+1][j]) fill(i+1, j);
  if (map[i][j+1] == '1' and not visited[i][j+1]) fill(i, j+1);
  if (map[i-1][j-1] == '1' and not visited[i-1][j-1]) fill(i-1, j-1);
  if (map[i+1][j-1] == '1' and not visited[i+1][j-1]) fill(i+1, j-1);
  if (map[i+1][j+1] == '1' and not visited[i+1][j+1]) fill(i+1, j+1);
  if (map[i-1][j+1] == '1' and not visited[i-1][j+1]) fill(i-1, j+1);
}

int main() {
  while (cin >> n) {
    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));

    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> map[i][j];

    int tcount = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (map[i][j] == '1' and not visited[i][j]) tcount++, fill(i, j);

    cout << "Image number " << test++ << " contains " << tcount << " war eagles." << endl;
  }
  return 0;
}
