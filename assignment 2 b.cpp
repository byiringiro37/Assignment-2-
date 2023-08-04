#include <iostream>

const int b_rows = 6;
const int b_cols = 7;
const char empty = ' ';
const char p1_tkn = 'X';
const char p2_tkn = 'O';

// Function to display the game board in the console
void displayBoard(char board[b_rows][b_cols]) {
    // std::cout << "-----------------------------\n";
    for (int row = b_rows - 1; row >= 0; --row) {
        std::cout << "| ";
        for (int col = 0; col < b_cols; ++col) {
            std::cout << board[row][col] << " | ";
        }
        // std::cout << "\n-----------------------------\n";
        std::cout << "\n";
    }
    std::cout << "\n\n| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n";
}

// Function to check if a player has won the game
bool checkWin(char board[b_rows][b_cols], char token) {
    // Check for horizontal wins
    for (int row = 0; row < b_rows; ++row) {
        for (int col = 0; col <= b_cols - 4; ++col) {
            if (board[row][col] == token && board[row][col + 1] == token &&
                board[row][col + 2] == token && board[row][col + 3] == token) {
                return true;
            }
        }
    }

    // Check for vertical wins
    for (int row = 0; row <= b_rows - 4; ++row) {
        for (int col = 0; col < b_rows; ++col) {
            if (board[row][col] == token && board[row + 1][col] == token &&
                board[row + 2][col] == token && board[row + 3][col] == token) {
                return true;
            }
        }
    }

    // TODO: Check for diagonal wins
 // Diagonally (from top-left to bottom-right)
    for (int rows = 0; rows <= b_rows - 4; rows++) {
        for (int cols = 0; cols <= b_cols - 4; cols++) {
            if (board[rows][cols] == token && board[rows + 1][cols + 1] == token &&
                board[rows + 2][cols + 2] == token && board[rows + 3][cols + 3] == token) {
                return true;
            }
        }
    }

    // Diagonally (from top-right to bottom-left)
    for (int rows = 0; rows <= b_rows - 4; rows++) {
        for (int cols = 3; cols < b_cols; cols++) {
            if (board[rows][cols] == token && board[rows + 1][cols - 1] == token &&
                board[rows + 2][cols - 2] == token && board[rows + 3][cols - 3] == token) {
                return true;
            }
        }
    }
    return false;
}

// Function to drop a token into a column
bool dropToken(char board[b_rows][b_cols], int col, char token) {
    for (int row = 0; row < b_rows; ++row) {
        if (board[row][col] == empty) {
            board[row][col] = token;
            return true;
        }
    }
    return false;
}

int main() {
    char board[b_cols][b_cols];
    for (int i = 0; i < b_rows; ++i) {
        for (int j = 0; j < b_cols; ++j) {
            board[i][j] = empty;
        }
    }

    bool isPlayer1Turn = true;

    std::cout << "Welcome to Power4!\n";
    displayBoard(board);

    int move;
    while (true) {
        char token = isPlayer1Turn ? p1_tkn : p2_tkn;
        int currentPlayer = isPlayer1Turn ? 1 : 2;

        std::cout << "Player " << currentPlayer << "'s Turn (" << token << "). Enter column number (1-7): ";
        std::cin >> move;
        // Convert move to zero-based index
        move--;

        if (move >= 0 && move < b_cols && board[b_rows - 1][move] == empty) {
            if (dropToken(board, move, token)) {
                displayBoard(board);

                if (checkWin(board, token)) {
                    std::cout << "\nCONGRATULATIONS! PLAYER " << currentPlayer << " YOU WIN!\n";
                    break;
                }

                bool isBoardFull = true;
                for (int col = 0; col < b_cols; ++col) {
                    if (board[b_rows - 1][col] == empty) {
                        isBoardFull = false;
                        break;
                    }
                }

                if (isBoardFull) {
                    std::cout << "It's a draw! The board is full.\n";
                    break;
                }

                isPlayer1Turn = !isPlayer1Turn; // Switch turns
            } else {
                std::cout << "Invalid move! Column is already full. Try again.\n";
            }
        } else {
            std::cout << "Invalid move! Please choose a valid column (1-7).\n";
        }
    }

    return 0;
}