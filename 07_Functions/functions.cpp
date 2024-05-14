#include <iostream>
using namespace std;

//Simple Function
void sayHello() {
    cout << "Hello from Apna College\n";
}

//Sum of 2 numbers
int sum(int a, int b) {
    return a + b;
}

//Sum of 2 float - Function Overloading
float sum(float x, float y) {
    return x + y;
}

//Product of 2 numbers
int prod(int a, int b) {
    return a + b;
}

//Is Number Odd or Even
void evenOrOdd(int n) {
    if(n % 2 == 0) {
        cout << "Even\n";
    } else {
        cout << "Odd\n";
    }
}

//Factorial of n
int factorial(int n) {
    int fact = 1;
    for(int i=2; i<=n; i++) {
        fact = fact * i;
    }

    return fact;
}

//Prime or Not
bool isPrime(int n) {
    if(n == 0 || n == 1) {
        return false;
    }

    for (int i = 2; i*i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    
    return true;
}

//Binomial Coefficient nCr
int binCoeff(int n, int r) {
    return factorial(n) / (factorial(n-r) * factorial(r));
}

//All primes in range [2, n]
void allPrimes(int n) {
    for(int i=2; i<=n; i++) {
        if(isPrime(i)) {
            cout << i << " ";
        }
    }

    cout << endl;
}

int main() {
    sayHello();
    cout << sum(1, 2) << endl;
    cout << sum(1.0f, 2.0f) << endl;
    cout << prod(1, 2) << endl;
    evenOrOdd(25);
    cout << factorial(5) << endl;
    cout << isPrime(5) << endl;
    cout << binCoeff(4, 2) << endl;
    allPrimes(15);

    return 0;
}

