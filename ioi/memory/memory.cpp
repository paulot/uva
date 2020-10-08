#include <iostream>
#include <vector>
#include "grader.h"
#include "memory.h"

static std::vector<int> cardIndex[51];

void play() {
 char a;

 for (int i = 1; i <= 50; ++i) {
   a = faceup(i);
   cardIndex[a-'A'].push_back(i);
 }

 for (int i = 'A'; i <= 'Y'; ++i) {
   for (int j = 0; j < 2; ++j) {
     faceup(cardIndex[i-'A'][j]);
   }
 }
}
