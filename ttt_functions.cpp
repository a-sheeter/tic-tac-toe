#include <iostream>
#include <vector>
#include <stdlib.h>

// welcome and rules
void welcome() {
  std::cout << "Welcome to Tic-Tac-Toe!\n";
  std::cout << "=======================\n";
  std::cout << "Rules: Each player takes a turn choosing which square they want to place their X or O in. Once one player has three of their markers in a row, either horizontally, vertically, or diagonally, that player wins! Good luck!\n\n"; 
}

std::vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

// draw the board
void draw() {
 
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
 
    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";
 
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |      \n";
 
    std::cout << "\n";
}

//figuring out player markers
int first_user_choice = 0;
char player_one_marker;
char player_two_marker; 

void player_markers() {
  std::cout << "Player One, will you be 1) X's or 2) O's?\n";
  std::cin >> first_user_choice;
  if (first_user_choice == 1) {
    player_one_marker = 'X';
    player_two_marker = 'O';
  } else {
    player_one_marker = 'O';
    player_two_marker = 'X';
  }
  std::cout << "Excellent! Player One, you will be " <<     player_one_marker << "'s, and Player Two will be " << player_two_marker << "'s! Let's Play!\n";
  std::cout << "=======================\n";
}

// the game
  int player_turns = 9;
  int player_one_move;
  int player_two_move;
  bool winner = false;

  // winning combinations
  std::vector<std::vector<int>> check_if_winner = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8}, {0,4,8}, {2,4,6}};

  // check if winner
  void final_winner() {
      for (int i = 0; i < check_if_winner.size(); i++) {
        int first_num = check_if_winner[i][0];
        int second_num = check_if_winner[i][1];
        int third_num = check_if_winner[i][2];
    if (board[first_num] == board[second_num] && board[second_num] == board[third_num])
     {
      winner = true;
      std::cout << "We have a winner! ";
      if (board[0] == player_one_marker) {
        std::cout << "Congratulations, Player One!\n";
      } else {
        std::cout << "Congratulations, Player Two!\n";
      }
      exit(0);
    }
  }
  }

  // check if tie
  void check_if_tie() {
    if (player_turns == 0 && winner == false){
    std::cout << "No one won. Play Again!\n";
    exit(0);
  }
  }

  // mechanics of the game
  void game() {
  while (player_turns > 0 && winner == false) {

    std::cout << "Player One, it's your turn! In which spot would you to place your " << player_one_marker << "?\n";
    std::cin >> player_one_move;
    board[player_one_move-1] = player_one_marker;
    player_turns--;

    draw();
    final_winner();
    check_if_tie();

    std::cout << "Player Two, it's your turn! In which spot would you like to player your " << player_two_marker << "?\n";
    std::cin >> player_two_move;
    board[player_two_move-1] = player_two_marker;
    player_turns--;

    draw();
    final_winner();
    check_if_tie();
  } 
  }

  
