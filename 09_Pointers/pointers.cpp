#include <iostream>
using namespace std;

void passValue(int param) {
    param = 1000;
}

//using Pointers
void passReference(int *param) {
    *param = 1000;
}

//using Reference Variable
void passReference2(int &param) {
    param = 5000;
}

int main() {
    int a = 10;
    int *ptr = &a;
    int **ptr2 = &ptr;

    cout << &a << " = " << ptr << endl;
    cout << &ptr << " = " << ptr2 << endl;

    //Dereference Operator
    cout << a << " = " << *ptr << " = " << *(&a) << endl;

    *ptr = 20;
    cout << a << endl; //should be 20 now

    //Null Pointer
    float* nptr = NULL;
    cout << nptr << endl;

    //cout << *nptr; // Gives Segmentation Fault

    //Pass by value
    int x = 0;
    passValue(x);
    cout << x << endl;

    //Pass by reference
    passReference(&x);
    cout << x << endl;

    //Reference Variable
    int i = 5;
    int &j = i;
    j++;
    cout << i << endl;

    passReference2(x);
    cout << x << endl;
}


