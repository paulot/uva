/**
 * For this problem we have to keep track of two groups. A group and enemies.
 * To do so, we give every element a doppelganger. The idea is that at any given
 * moment an element's doppelganger will be present in the exact opposite set as
 * the element. For instance: if a and b are friends, then a and b are in under the
 * same set and a', b' are under the same set. Hence a' represents the identity
 * of a as an enemy, while a represents its identity as a friend. 
 *
 * Using this scheme it is easy to see that if a and b are enemies, a' will be in
 * the set containing b or b' will be in the set containing a.
 */
#include <cstdio>
#define offset (2*n)
#define twin(a) (offset-a+1)

using namespace std;

int friends[20005], n;

void init() { for (int i = 0; i <= offset+1; i++) friends[i] = i; }
int findSet(int a) { while (friends[a] != a) a = friends[a]; return a; }
void unionSet(int a, int b) { friends[findSet(a)] = findSet(b); }

inline bool areFriends(int a, int b) {
  return findSet(a) == findSet(b) or findSet(twin(a)) == findSet(twin(b));
}

inline bool areEnemies(int a, int b) {
  return findSet(a) == findSet(twin(b)) or findSet(twin(a)) == findSet(b);
}

inline void setFriends(int a, int b) {
  if (areEnemies(a, b)) printf("-1\n");
  else unionSet(a, b), unionSet(twin(a), twin(b));
}

inline void setEnemies(int a, int b) {
  if (areFriends(a, b)) printf("-1\n");
  else unionSet(a, twin(b)), unionSet(twin(a), b);
}

int main() {
  int c, a, b;
  while (scanf("%d", &n) == 1) {
    init();

    while (scanf("%d %d %d\n", &c, &a, &b) == 3) {
      if (c == 0 and a == 0 and b == 0) break;

      switch(c) {
        case 1: setFriends(a, b); break;
        case 2: setEnemies(a, b); break;
        case 3: printf("%d\n", areFriends(a, b)); break;
        case 4: printf("%d\n", areEnemies(a, b)); break;
      }
    }
  }
  return 0;
}
