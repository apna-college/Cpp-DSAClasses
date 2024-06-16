#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Simple Recursive Function with Stack Overflow
void func() {
    cout << "function call\n";
    func();
}

//Factorial 
int factorial(int n) {
    if(n == 1) {
        return 1;
    }
    return n * factorial(n-1);
}

//Print Decreasing
void print(int n) {
    if(n == 0) {
        return;
    }

    cout << n << " ";
    print(n-1);
}

//Sum of N Natural Numbers
int sum(int n) {
    if(n == 1) {
        return 1;
    }

    return n + sum(n-1);
}

//Nth Fibonacci
int fibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

//Is Array Sorted
bool isSorted(int arr[], int i, int n) {
    if(i == n-1) {
        return true;
    }

    if(arr[i] > arr[i+1]) {
        return false;
    }

    return isSorted(arr, i+1, n);
}

//First Occurrence
int firstOccur(vector<int> vec, int target, int i) {
    if(i == vec.size()) {
        return -1;
    }

    if(vec[i] == target) {
        return i;
    }

    return firstOccur(vec, target, i+1);
}

//Last Occurrence
int lastOccur(vector<int> vec, int target, int i) {
    if(i == vec.size()) {
        return -1;
    }

    int idxFound = lastOccur(vec, target, i+1);
    
    if(idxFound == -1 && vec[i] == target) {
        return i;
    }

    return idxFound;
}

//X^N
int pow(int x, int n) {
    if(n == 0) {
        return 1;
    }

    int halfPow = pow(x, n/2);
    int halfPowSquare = halfPow * halfPow;
    if(n % 2 == 0) {
        //even
        return halfPowSquare;
    } else {
        return x * halfPowSquare;
    }
}

int main() {
    cout << factorial(5) << endl;

    print(6);
    cout << endl;

    cout << sum(5) << endl;

    cout << fibonacci(6) << endl;

    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 4, 3, 5};
    cout << isSorted(arr1, 0, 5) << endl;
    cout << isSorted(arr2, 0, 5) << endl;

    vector<int> vec = {1, 2, 3, 3, 3, 4};
    cout << firstOccur(vec, 3, 0) << endl;
    cout << lastOccur(vec, 3, 0) << endl;

    cout << pow(2, 10) << endl;
    return 0;    
}


