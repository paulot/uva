#include <iostream>
#include <cstring>


using namespace std;

bool visited[105][105];
char map[105][105];
int m, n;

void fill(int i, int j) {
  visited[i][j] = true;
  if (map[i][j-1] == '@' and not visited[i][j-1]) fill(i, j-1);
  if (map[i][j+1] == '@' and not visited[i][j+1]) fill(i, j+1);
  if (map[i-1][j] == '@' and not visited[i-1][j]) fill(i-1, j);
  if (map[i-1][j+1] == '@' and not visited[i-1][j+1]) fill(i-1, j+1);
  if (map[i-1][j-1] == '@' and not visited[i-1][j-1]) fill(i-1, j-1);
  if (map[i+1][j] == '@' and not visited[i+1][j]) fill(i+1, j);
  if (map[i+1][j-1] == '@' and not visited[i+1][j-1]) fill(i+1, j-1);
  if (map[i+1][j+1] == '@' and not visited[i+1][j+1]) fill(i+1, j+1);
}

int main() {
  while (cin >> m >> n and m != 0) {
    memset(visited, 0, sizeof(visited));
    memset(map, 0, sizeof(map));
    int tcount = 0;
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) cin >> map[i][j];
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++)
      if (map[i][j] == '@' and not visited[i][j]) tcount++, fill(i, j);

    cout << tcount << endl;
  }
  return 0;
}
