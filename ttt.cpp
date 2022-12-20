#include <iostream>
#include <vector>
#include "ttt_functions.hpp"

/*
1. two players that input into the same terminal
2. 3x3 game board will need to be represented using a data structure, like a vector or array
3. There are 8 winning combinations.
*/

int main() {
  welcome();
  player_markers();
  draw();
  game();

}

