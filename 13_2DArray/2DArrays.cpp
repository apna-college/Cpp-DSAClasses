#include <iostream>
using namespace std;

void printSpiral(int matrix[][4], int n, int m) {
    int scol = 0, srow = 0;
    int ecol = m-1, erow = n-1;

    while(srow <= erow && scol <= ecol) {
        //top
        for(int j=scol; j<=ecol; j++) {
            cout << matrix[srow][j] << " ";
        }

        //right
        for(int i=srow+1; i<=erow; i++) {
            cout << matrix[i][ecol] << " ";
        }

        //bottom
        for(int j=ecol-1; j>=scol; j--) {
            if(srow == erow) {
                break;
            }
            cout << matrix[erow][j] << " ";
        }

        //left
        for(int i=erow-1; i>=srow+1; i--) {
            if(scol == ecol) {
                break;
            }
            cout << matrix[i][scol] << " ";
        }

        srow++; scol++;
        erow--; ecol--;
    }

    cout << endl;
}

void diagonalSum(int mat[][4], int n) { 
    int sum = 0;

    //O(n^2)
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i == j) {
                sum += mat[i][j];
            } else if (i+j == n-1) {
                sum += mat[i][j];
            }
        }
    }
    cout <<"O(N^2) code => sum = " << sum << endl;

    //O(n)
    sum = 0;
    for(int i=0; i<n; i++) {
        sum += mat[i][i];
        if(n-1-i != i)
            sum+= mat[i][n-1-i];
    }
    cout <<"O(N) code => sum = " << sum << endl;
}

bool search(int mat[][4], int n, int m, int key) {
    int i=0, j=m-1;
    while(i < n && j >= 0) {
        if(mat[i][j] == key) {
            cout << "found at (" << i << "," << j << ")\n";
            return true;
        } else if(mat[i][j] > key) {
            //go left
            j--;
        } else {
            //go right
            i++;
        }
    }

    cout << "key NOT found\n";
    return false;
}

void func(int (*ptr)[4]) {
    cout << ptr << endl;
    cout << ptr+1 << endl;

    //address(pointer) of row
    cout << "0th row address" << ptr << endl;
    cout << "1st row address" << (ptr+1) << endl;

    //actual row
    cout << "0th row start" << *ptr << endl;
    cout << "1st row start" << *(ptr+1) << endl;

    //to get j=2 column in i=0 row
    cout << "(0, 2) = " << *(*ptr+2) << endl;

    //to get j=2 column in i=1 row
    cout << "(1, 2) = " << *(*(ptr+1)+2) << endl;

}

int main() {
    int matrix[4][4] = {{1, 2, 3, 4}, 
                         {5, 6, 7, 8},
                         {9, 10, 11, 12},
                         {13, 14, 15, 16}};

    int matrix2[3][4] = {{1, 2, 3, 4}, 
                         {5, 6, 7, 8},
                         {9, 10, 11, 12}};

    printSpiral(matrix, 4, 4);
    //Expected : 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

    printSpiral(matrix2, 3, 4);

    diagonalSum(matrix, 4);

    int mat[4][4] = {{10, 20, 30, 40}, 
                     {15, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50}};

    search(mat, 4, 4, 33);
    search(mat, 4, 4, 100);

    //Pointers & 2D Arrays
    func(matrix);
    return 0;    
}


