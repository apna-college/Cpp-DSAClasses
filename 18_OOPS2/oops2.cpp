#include <iostream>
#include <string>
using namespace std;

//Function Overloading
class Print {
public:
    void show(int x) {
        cout << "int : " << x << endl;
    }

    void show(string str) {
        cout << "string : " << str << endl;
    }
};

//Operator Overloading
class Complex {
    int real;
    int img;

public:
    Complex(int r, int i) {
        real = r;
        img = i;
    }

    void showNum() {
        cout << real << " + " <<  img << "i\n";
    }

    Complex operator - (Complex &obj) {
        int resReal = this->real - obj.real;
        int resImg = this->img - obj.img;
        Complex res(resReal, resImg);
        return res;
    }

    Complex operator + (Complex &obj) {
        int resReal = this->real + obj.real;
        int resImg = this->img + obj.img;
        Complex res(resReal, resImg);
        return res;
    }
};

//Function Overriding & Virtual Function
class Parent {
public:
    void show() {
        cout << "parent show\n";
    }

    virtual void hello() {
        cout << "hello from parent\n";
    }
};

class Child : public Parent {
public:
    void show() {
        cout << "child show\n";
    }  

    void hello() {
        cout << "hello from child\n";
    }
};

//Abstract Classes & Pure Virtual Functions

class Shape {
    //This is an abstract class
public:
    virtual void draw() = 0; //Pure Virtual Function
};

class Square : public Shape {
public:
    void draw() {
        cout << "drawing a rectangle\n";
    }
};

class Circle : public Shape {
public:
    void draw() {
        cout << "drawing a circle\n";
    }
};

//Static 
void counter() {
    static int count = 0;
    count++;
    cout << "count : " << count << endl;
}

class Example {
public:
    Example() {
        cout << "constructor\n";
    }

    ~Example() {
        cout << "destructor\n";
    }
};

//Friend Class & Function
class A {
    string secret = "private secret";
    friend class B;
    friend void shareSecret(A &obj);
};

class B {
public:
    void showSecret(A &obj) {
        cout << obj.secret << endl;
    }
};

void shareSecret(A &obj) {
        cout << obj.secret << endl;
}

int main() {
    Print p1;
    p1.show(50);
    p1.show("apnacollege");
    
    Complex num1(1, 2);
    Complex num2(3, 4);
    Complex res = num1 + num2;
    res.showNum();

    Child c1;
    c1.show();
    
    Child c2;
    Parent *par1;
    par1 = &c2; //Binding at runtime
    par1->hello();
    
    Circle cir1;
    Square squ1;
    cir1.draw();
    squ1.draw();

    counter();
    counter();
    counter();

    //Static object
    int x = 0;
    if(x == 0) {
        static Example eg1;
    }
    cout << "exiting main function.\n";

    A a1;
    B b1;
    b1.showSecret(a1);
    shareSecret(a1);
    return 0;    
}


