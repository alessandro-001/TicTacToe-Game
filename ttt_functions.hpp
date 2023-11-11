#ifndef TTT_FUNCTIONS_HPP
#define TTT_FUNCTIONS_HPP

#include <vector>

void printBoard(const std::vector<std::vector<char>>& board);
bool checkWin(const std::vector<std::vector<char>>& board, char player);
bool checkTie(const std::vector<std::vector<char>>& board);

#endif 
