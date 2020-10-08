#include <iostream>

using namespace std;

int ds[100];

void init() {
  for (int i = 0; i < 100; i++) ds[i] = i;
}

int find(int i) {
  if (ds[i] == i) return i;
  return ds[i] = find(ds[i]);
}

void union_set(int a, int b) {
  ds[find(b)] = find(a);
}
