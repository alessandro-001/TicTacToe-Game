#include "ttt_functions.hpp"
#include <iostream>
#include <vector>

int main() {
    std::cout << "========================================================================" << std::endl;
    std::cout << "TicTacToe game,\nInstructions: Enter a integer starting at index 0 until 2 adding \na whitespace between them, \nEnter row first then the column, \nWin the game doing a tris vertical, horizontal or diagonal \n" << std::endl;
    std::cout << "========================================================================" << std::endl;

    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        //print the current board
        printBoard(board);

        // get player's move
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column, from 0 to 2): ";
        std::cin >> row >> col;

        //check if move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        //make the move
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            // Print the final board
            printBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        //check for tie
        if (checkTie(board)) {
            // Print the final board
            printBoard(board);
            std::cout << "It's a tie!\n";
            break;
        }
        // Switch to the other player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}
