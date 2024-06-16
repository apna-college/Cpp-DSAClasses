#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void changeArr(int arr[], int n, int i) {
    if(i == n) {
        printArr(arr, n);
        return;
    }

    arr[i] = i+1;
    changeArr(arr, n, i+1);
    arr[i] -= 2;
}

void allSubsets(string str, int i, string subset) {
    if(i == str.size()) {
        cout << subset << endl;
        return;
    }

    char ch = str[i];
    allSubsets(str, i+1, subset);
    allSubsets(str, i+1, subset+ch);
}

void allPermutations(string str, string ans) {
    if(str.size() == 0) {
        cout << ans << endl;
        return;
    }

    for(int i=0; i<str.size(); i++) {
        string newStr = str.substr(0, i) + str.substr(i+1, i+str.size());
        allPermutations(newStr, ans+str[i]);
    }
}

void printBoard(vector<vector<char>> board) {
    int n = board.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "---------------\n";
}

bool isSafe(vector<vector<char>> board, int row, int col) {
    int n = board.size();
    //vertical
    for(int j=0; j<col; j++) {
        if(board[row][j] == 'Q') {
            return false;
        }
    }

    //horizontal
    for(int i=0; i<row; i++) {
        if(board[i][col] == 'Q') {
            return false;
        }
    }

    //diagonal left
    for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }

    //diagonal right
    for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}


int nQueens(vector<vector<char>> board, int row) {
    int n = board.size();
    if(row == n) {
        printBoard(board);
        return 1;
    }

    int count = 0;
    for(int j=0; j<n; j++) {
        if(isSafe(board, row, j)) {
            board[row][j] = 'Q';
            count += nQueens(board, row+1);
            board[row][j] = '.';
        }
    }

    return count;
}

int gridWays(int i, int j, int n, int m) {
    if(i == n-1 && j == m-1) {
        return 1;
    }

    if(i >= n || j >= m) {
        return 0;
    }

    int totWays = 0;
    
    //go right
    totWays += gridWays(i, j+1, n, m);

    //go down
    totWays += gridWays(i+1, j, n, m);

    return totWays;
}

bool isSafe(int sudoku[9][9], int row, int col, int val) {
    //same col
    for(int i=0; i<9; i++) {
        if(sudoku[i][col] == val) {
            return false;
        }
    }

     //same row
    for(int j=0; j<9; j++) {
        if(sudoku[row][j] == val) {
            return false;
        }
    }

    //same 3x3 grid
    int sr = (row/3) * 3;
    int sc = (col/3) * 3;

    for(int i=sr; i<sr+3; i++) {
        for(int j=sc; j<sc+3; j++) {
            if(sudoku[i][j] == val) {
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int sudoku[9][9], int row, int col) {
    cout << "row = " << row << " , col = " << col << endl;
    if(row == 9) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }

        return true;
    } 

    int nextRow = row;
    int nextCol = col + 1;

    if(nextCol == 9) {
        nextRow = row+1;
        nextCol = 0;
    }

    if(sudoku[row][col] != 0) {
        return sudokuSolver(sudoku, nextRow, nextCol);
    }

    for(int digit=1; digit<=9; digit++) {
        if(isSafe(sudoku, row, col, digit)) {
            sudoku[row][col] = digit;
            if(sudokuSolver(sudoku, nextRow, nextCol)) {
                return true;
            }
            sudoku[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int arr[5];
    int n = 5;
    changeArr(arr, n, 0);
    printArr(arr, n);

    string str = "abc";
    string ans = "";
    allSubsets(str, 0, ans);
    cout << "--------------------------\n";

    allPermutations(str, ans);
    cout << "--------------------------\n";

    int n = 4;
    vector<vector<char>> board;
    
    for(int i=0; i<n; i++) {
        vector<char> newRow;
        for(int j=0; j<n; j++) {
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

    int count = nQueens(board, 0);
    cout << "total ways : " << count << endl;

    
    cout << gridWays(0, 0, 3, 3) << endl;

    int sudoku[9][9] = {{0, 0, 8, 0, 0, 0, 0, 0, 0}, 
                        {4, 9, 0, 1, 5, 7, 0, 0, 2},
                        {0, 0, 3, 0, 0, 4, 1, 9, 0},
                        {1, 8, 5, 0, 6, 0, 0, 2, 0},
                        {0, 0, 0, 0, 2, 0, 0, 6, 0},
                        {9, 6, 0, 4, 0, 5, 3, 0, 0},
                        {0, 3, 0, 0, 7, 2, 0, 0, 4},
                        {0, 4, 9, 0, 3, 0, 0, 5, 7},
                        {8, 2, 7, 0, 0, 9, 0, 1, 3}};

    sudokuSolver(sudoku, 0, 0);
    return 0;    
}


