#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grader.h"
#include "cluedo.h"

static int M,L,W,gotit,cnt,maxcnt;

int Theory(int m, int l, int w) {
   ++cnt;
   if (m < 1 || m > 6 || l < 1 || l > 10 || w < 1 || w > 6) exit(92);
   if (rand()%2 && m != M) return 1;
   else if (rand()%2 && l != L) return 2;
   else if (rand()%2 && w != W) return 3;
   else if (m != M) return 1;
   else if (l != L) return 2;
   else if (w != W) return 3;
   gotit = 1;
   return 0;
}

int main(){
   while (3 == scanf("%d%d%d",&M,&L,&W)) {
      cnt = gotit = 0;
      Solve();
      if (cnt > maxcnt) maxcnt = cnt;
      if (!gotit) {
         printf("NO\n");
         return 91;
      }
   }
   printf("OK %d\n",maxcnt);
   return 0;
}
