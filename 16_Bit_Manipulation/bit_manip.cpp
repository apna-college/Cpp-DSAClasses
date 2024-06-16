#include <iostream>
#include <vector>
using namespace std;

bool isPowerOf2(int num) {

    if((num & (num-1)) == 0) {
        return true;
    } else {
        return false;
    }
}

void updateIthBit(int num, int i, int val) {
    num = num & ~(1 << i);

    int mask = val << i;
    num = num | mask;

    cout << num << endl;
}

void clearLastIBits(int num, int i) {
    int mask = (~0) << i;
    num = num & mask;

    cout << num << endl;
}

void clearBitsInRange(int num, int i, int j) {
    int a = (~0) >> (j+1);
    int b = (1 << i) - 1;
    int mask = a | b;
    num = num & mask;

    cout << num << endl;
}

int countSetBits(int num) {
    int count = 0;
    
    while(num > 0) {
        if(num & 1) {
            count++;
        }
        num = num >> 1;
    }

    cout << count << endl;
    return count;
}

//calculate x^n
int fastExponentiation(int x, int n) {
    int ans = 1;

    while(n > 0) {
        int lastBit = n & 1;
        if(lastBit)
            ans = ans * x;

        x = x*x;
        n = n >> 1;
    }

    cout << ans << endl;
    return ans;
}

int main() {
    /* Binary Operators - AND, OR, XOR */
    int x = 3, y = 5;
    
    cout << (x & y) << endl;
    cout << (x | y) << endl;
    cout << (x ^ y) << endl;

    //Binary NOT
    cout << ~0 << endl;
    cout << ~6 << endl;

    //Binary Shift
    cout << (7 << 2) << endl;// same as (7 * 2^2)
    cout << (7 >> 2) << endl;// same as (7 / 2^2)

    //Practice Qs
    cout << ~4 << endl;
    cout << (8 >> 1) << endl;

    //Odd or Even
    int num = 7;
    bool isOdd = num & 1;
    cout << (isOdd ? "odd" : "even") << endl;

    //Get ith bit
    num = 6;
    int i = 2;
    int mask = 1 << i;
    if(num & mask) {
        cout << "bit is 1\n";
    } else {
        cout << "bit is 0\n";
    }

    //Set ith bit
    num = 6;
    i = 3;
    mask = 1 << i;
    num = num | mask;
    cout << num << endl; //14 is expected;

    //Clear ith Bit
    num = 6;
    i = 1;
    mask = ~(1 << i);
    num = num & mask;
    cout << num << endl; //4 is expected; 

    //Power of 2
    cout << isPowerOf2(8) << endl;
    cout << isPowerOf2(7) << endl;

    //Update ith Bit
    updateIthBit(7, 2, 0);
    updateIthBit(7, 3, 1);

    //Clear last i bits
    clearLastIBits(15, 2);

    //Count Set Bits;
    countSetBits(10);
    countSetBits(7);

    //Fast Exponentiation
    fastExponentiation(3, 4);
    return 0;    
}


