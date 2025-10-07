#include <iostream>
#include <vector>
using namespace std;

int N;

// Function to print the chessboard configuration
void printSolution(vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(vector<vector<int>>& board, int row, int col) {
    int i, j;

    // Check this column on upper side
    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

// Recursive utility function to solve N-Queens
bool solveNQueensUtil(vector<vector<int>>& board, int row) {
    // Base case: all queens placed
    if (row == N) {
        printSolution(board);
        return true;
    }

    bool res = false;
    for (int col = 0; col < N; col++) {
        // Check if queen can be placed at (row, col)
        if (isSafe(board, row, col)) {
            board[row][col] = 1;  // Place queen

            // Recurse for next row
            res = solveNQueensUtil(board, row + 1) || res;

            // Backtrack: remove queen
            board[row][col] = 0;
        }
    }

    return res;
}

// Main solver function
void solveNQueens() {
    vector<vector<int>> board(N, vector<int>(N, 0));

    if (!solveNQueensUtil(board, 0))
        cout << "No solution exists for N = " << N << endl;
}

// Driver code
int main() {
    cout << "Enter the value of N: ";
    cin >> N;
    solveNQueens();
    return 0;
}
