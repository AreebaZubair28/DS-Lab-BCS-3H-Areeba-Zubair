#include <iostream>
#include <cmath>
using namespace std;

#define MAX 20   

int board[MAX];  
int solutionCount = 0;

void printSolution(int N) {
    cout << "Solution " << ++solutionCount << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << "------------------" << endl;
}

bool isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return false;
    }
    return true;
}

void solveNQueens(int row, int N) {
    if (row == N) {
        printSolution(N);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row] = col;       
            solveNQueens(row + 1, N); 
        }
    }
}

int main() {
    int N;
    cout << "Enter value of N: ";
    cin >> N;

    if (N > MAX) {
        cout << "N too large! Please use N <= " << MAX << endl;
        return 0;
    }

    solveNQueens(0, N);

    if (solutionCount == 0)
        cout << "No solutions exist for N = " << N << endl;
    else
        cout << "Total solutions for N = " << N << " : " << solutionCount << endl;

    return 0;
}
