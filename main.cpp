#include "ttt_functions.hpp"
#include <iostream>
#include <vector>

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';

    while (true) {
        // Print the current state of the board
        printBoard(board);

        // Get the player's move
        int row, col;
        std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        std::cin >> row >> col;

        // Check if the move is valid
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            std::cout << "Invalid move. Try again.\n";
            continue;
        }

        // Make the move
        board[row][col] = currentPlayer;

        // Check for a win
        if (checkWin(board, currentPlayer)) {
            // Print the final board
            printBoard(board);
            std::cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        // Check for a tie
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
