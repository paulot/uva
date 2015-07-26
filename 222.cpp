#include <iostream>
#include <map>
#include <algorithm>
#include <iomanip>

using namespace std;

map<double, double> prices;
double dist[51], d, cap, mpg;
int n;

double dfs(int station, double fuel, double cost) {
  if (fuel < 0) return 1e10;
  if (station == n+1) return cost;

  double traveled = (station == n) ? d - dist[n] : (dist[station+1] - dist[station]),
         new_cost = (cap - fuel) * (prices[dist[station]]/100) + 2 + cost;

  double cost1 = dfs(station+1, fuel - traveled/mpg, cost),
         cost2 = (fuel < cap) ?
           cost2 = dfs(station+1, cap - traveled/mpg, new_cost) : 1e10;

  return min(cost1, cost2);
}

int main() {
  int ds = 1;
  while (cin >> d) {
    prices.clear();
    if (d == -1) break;
    double cost;
    cin >> cap >> mpg >> cost >> n;
    dist[0] = 0;
    prices[0] = 0;

    for (int i = 1; i <= n; i++) { cin >> dist[i]; cin >> prices[dist[i]]; }

    sort(dist, dist+n+1);

    cout << "Data Set #" << ds++ << endl;
    cout << "minimum cost = $" << fixed << setprecision(2) << dfs(0, cap, cost) << endl;
  }
  return 0;
}
