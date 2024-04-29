#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n = 10;
    //Print numbers from 1 to n
    // for(int i=1; i<=n; i++) {
    //     cout << i << " ";
    // }
    // cout << endl;

    //Print numbers from n to 1 (reverse order)
    // for(int i=n; i>0; i--) {
    //     cout << i << " ";
    // }
    // cout << endl;

    //Print Sum of first N natural numbers
    // int sum = 0;
    // for(int i=1; i<=n; i++) {
    //     sum += i;
    // }

    // cout << "Sum from 1 to n = " << sum << endl;

    //Square Pattern using For Loop
    // for(int i=1; i<=4; i++) {
    //     cout << "****" << endl;
    // }

    //Sum of Digits of a Number
    // int digitSum = 0;
    // int num = 12345;

    // while(num > 0) {
    //     digitSum += num % 10;
    //     num /= 10;
    // }

    // cout << "sum of digits = " << digitSum << endl;

    //Sum of Odd Digits of a Number
    // int oddDigSum = 0;
    // int num = 12345;
    // while(num > 0) {
    //     int lastDig = num % 10;
    //     if(lastDig % 2 != 0) {
    //         oddDigSum += lastDig;
    //     }
    //     num /= 10;
    // }

    // cout << "sum of odd digits = " << oddDigSum << endl;

    //Print a number's Digits in Reverse
    // int num = 12345;
    //
    // while(num > 0) {
    //     cout << num % 10 << " ";
    //     num /= 10;
    // }
    // cout << endl;

    //Reverse the given number & print the result
    // int num = 12345;
    // int res = 0;

    // while(num > 0) {
    //     int lastDig = num % 10;
    //     res = res * 10 + lastDig;
    //     num /= 10;
    // }
    // cout << res << endl;

    //Check if a number is Prime or not
    int num = 49;
    bool isPrime = true;

    //Solution 1
    for(int i=2; i<num-1; i++) {
        if(num % i == 0) {
            isPrime = false;
            break;
        }
    }
    cout << isPrime << endl;

    //Solution 2 (slightly better) : #include <cmath>
    isPrime = true;
    for(int i=2; i<=sqrt(num); i++) {
        if(num % i == 0) {
            isPrime = false;
            break;
        }
    }
    cout << isPrime << endl;
    return 0;
}