#include <iostream>
using namespace std;

int main() {
    int n = 4;

    //Number Square Pattern
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            cout << i;
        }
        cout << endl;
    }

   // Star Pattern
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    //Inverted Star Pattern
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n-i+1; j++) {
            cout << "*";
        }
        cout << endl;
    }

   // Half Pyramid Pattern
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout << j;
        }
        cout << endl;
    }

   // Character Pyramid Pattern
    char ch = 'A';
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout << ch++;
        }
        cout << endl;
    }

    //Hollow Rectangle Pattern
    for(int i=1; i<=n; i++) {
        cout << "*";
        for(int j=1; j<=n-1; j++) {
            if(i == 1 || i == n) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout<< "*" << endl;
    }

    //Inverted & Rotated Half Pyramid
    for(int i=1; i<=n; i++) {
        //spaces
        for(int j=1; j<=n-i; j++) {
            cout << " ";
        }
        //stars
        for(int j=1; j<=i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    //Floyd's Triange Pattern
    int num = 1;
    for(int i=1; i<=5; i++) {
        for(int j=1; j<=i; j++) {
            cout << num++ << " ";
        }
        cout << endl;
    }

    //Diamond Pattern
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n-i; j++) {
            cout << " ";
        }
        for(int j=1; j<=2*i-1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    for(int i=n; i>0; i--) {
        for(int j=1; j<=n-i; j++) {
            cout << " ";
        }

        for(int j=1; j<=2*i-1; j++) {
            cout << "*";
        }
        cout << endl;
    }

    //Butterfly Pattern
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            cout << "*";
        }
        for(int j=1; j<=2*(n-i); j++) {
            cout << " ";
        }
        for(int j=1; j<=i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    for(int i=n; i>0; i--) {
        for(int j=1; j<=i; j++) {
            cout << "*";
        }
        for(int j=1; j<=2*(n-i); j++) {
            cout << " ";
        }
        for(int j=1; j<=i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    
    return 0;
}