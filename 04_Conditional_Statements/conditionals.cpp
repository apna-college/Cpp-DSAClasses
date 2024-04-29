#include <iostream>
#include <cmath>
using namespace std;

int main() {
    //Print the largest of 2 numbers
    int a = 3, b = 5;
    if(a >= b) {
        cout << "a is larger" << endl;
    } else {
        cout << "b is larger" << endl;
    }

    //Print if a number is Odd or Even
    int num = 5;
    if(num % 2 == 0) {
        cout << "Number is Even" << endl;
    } else {
        cout << "Number is Odd" << endl;
    }

    //Income Tax Calculator
    int income = 7; //in Lakhs
    float tax;

    if(income < 5) {
        tax = 0;
    } else if(income <= 10) {
        tax = 0.2 * income;
    } else {
        tax = 0.3 * income;
    }

    cout << "Tax = " << (tax * 100000) << endl;

    //Print Largest of 3 Numbers
    int x = 2, y = 3, z = 5;
    if(x >= y && x >= z) {
        cout << "x is largest" << endl;
    }   else if(y >= z) {
        cout << "y is largest" << endl;
    } else {
        cout << "z is largest" << endl;
    }

    //Odd or Even using Ternary Operator
    int num = 25;
    bool isEven = num % 2 == 0 ? true : false;
    
    //Calculator using Switch Statement
    int op = '*';
    int num1 = 4;
    int num2 = 5;

    switch(op) {
        case '+' : cout << "a + b = " << (num1 + num2) << endl;
                    break;
        case '-' : cout << "a - b = " << (num1 - num2) << endl;
                    break;
        case '*' : cout << "a * b = " << (num1 * num2) << endl;
                    break;
        case '/' : cout << "a / b = " << (num1 / num2) << endl;
                    break;
        default : cout << "Invalid Operator" << endl;
    }
    return 0;
}