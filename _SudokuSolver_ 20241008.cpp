#include <iostream>
#include <vector>

const int SIZE = 9;

// Function to check if a number can be placed in a given position
bool isSafe(const std::vector<std::vector<int>>& board, int row, int col, int num) {
    for (int x = 0; x < SIZE; x++) {
        if (board[row][x] == num || board[x][col] == num || 
            board[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            return false;
        }
    }
    return true;
}

// Backtracking function to solve the Sudoku
bool solveSudoku(std::vector<std::vector<int>>& board) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= SIZE; num++) {
                    if (isSafe(board, row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board[row][col] = 0; // backtrack
                    }
                }
                return false; // no number can be placed
            }
        }
    }
    return true; // puzzle solved
}

// Function to print the Sudoku board
void printBoard(const std::vector<std::vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

// Function to read Sudoku puzzle from user
void readBoard(std::vector<std::vector<int>>& board) {
    std::cout << "Enter the Sudoku puzzle (use 0 for empty cells):\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            std::cin >> board[i][j];
        }
    }
}

int main() {
    std::vector<std::vector<int>> board(SIZE, std::vector<int>(SIZE, 0));

    readBoard(board);

    std::cout << "Solving the Sudoku...\n";
    if (solveSudoku(board)) {
        std::cout << "Solved Sudoku:\n";
        printBoard(board);
    } else {
        std::cout << "No solution exists.\n";
    }

    return 0;
}