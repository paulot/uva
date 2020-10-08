#include "memory.h"
#include "grader.h"
#include <stdio.h>
#include <stdlib.h>

static char card[51];
static int up[2], is_up[51], candy[25], candies, moves;

char faceup(int C){
   int c0, c1;
   if (C < 1 || C > 50 || is_up[C]) {
      printf("alalal %d  \n", C);
      exit(92);
   }
   is_up[C] = 1;
   up[moves%2] = C;
   moves++;
   if (moves%2 == 0) {
      c0 = card[ up[0] ] - 'A';
      c1 = card[ up[1] ] - 'A';
      if (c0==c1 && !candy[c0]) {
         candy[c0] = 1;
         ++candies;
      }
      is_up[ up[0] ] = is_up[ up[1] ] = 0;
   }
   return card[C];
}

void playgame(){
   int i;
   for (i=1;i<=50;i++) {
      card[i] = getchar();
   }
   moves = candies = 0;
   play();
   if (candies != 25) {
      printf("not enough candies %d\n", candies);
      exit(91);
   }
}

int main(){
   playgame();
   printf("OK %d\n",moves);
   return 0;
}
