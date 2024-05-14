#include <iostream>
using namespace std;

//Convert Binary to Decimal
void binToDecimal(int n) {
    int res = 0;
    int p = 1;
    while(n > 0) {
        int lastDig = n % 10;
        res += lastDig * p;
        p = p * 2;
        n = n / 10;
    }
    cout << "Decimal form = " << res << "\n";
}

//Convert Decimal to Binary
void decToBinary(int n) {
    int res = 0;
    int p = 1;
    while(n > 0) {
        int rem = n % 2;
        res += rem * p;
        p = p * 10;
        n = n / 2;
    }
    cout << "Binary form = " << res << "\n";
}

int main() {
    binToDecimal(101);
    decToBinary(5);
    return 0;
}

