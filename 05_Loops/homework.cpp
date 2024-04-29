#include <iostream>
using namespace std;

int main() {
    //Qs : Factorial of a number n
    int n = 6;
    int fact = 1;
    for(int i=1; i<=n; i++) {
        fact *= i;
    }

    cout << "factorial of " << n << " = " << fact << "\n";
    
    //Qs : Multiplication Table of n
    n = 8;
    for(int i=1; i<=10; i++) {
        cout << (n * i) << " ";
    }
    cout << endl;

    //Qs : Check for Armstrong Number
    n = 371;
    int num = n;
    int cubeSum = 0;

    while(num > 0) {
        int lastDig = num % 10;
        cubeSum += lastDig * lastDig * lastDig;
        num /= 10;
    }

    if(n == cubeSum) {
        cout << "Armstrong number\n";
    } else {
        cout << "NOT an Armstrong number\n";
    }

    //Qs : Print Primes from 2 to N
    int N = 15;
    for(int i=2; i<=N; i++) {
        int curr = i; //current number to check for
        bool isPrime = true;
        for(int j=2; j*j<=i; j++) {
            if(curr % j == 0) {
                isPrime = false;
            }
        }

        if(isPrime) {
            cout << curr << " ";
        }
    }
    cout << endl;

    //Qs : Print N Fibonacci Numbers
    n = 10;
    int first = 0, sec = 1;
    cout << first << " " << sec << " ";

    for(int i=2; i<n; i++) {
        int third = first + sec;
        cout << third << " ";
        first = sec;
        sec = third;
    }

    cout << "\n";
    return 0;    
}


