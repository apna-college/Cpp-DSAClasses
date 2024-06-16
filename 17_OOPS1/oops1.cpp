#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    float cgpa;

public:
    string name;

    //Setter
    void setCgpa(float newCgpa) {
        if(newCgpa < 0) {
            cout << "Invalid Data\n";
            return;
        }
        cgpa = newCgpa;
    }

    //Getter
    float getCgpa() {
        return cgpa;
    }

    void getPercentage() {
        cout << (cgpa * 10) << "% \n";
    }
};

class Car {
    string name;
    int price;

public:
    int *mileage;
    //Contructor
    Car() {
        cout << "Creating & Initializing a new car..\n";
    }

    //Parameterized Contructor
    Car(string name, int price) {
        cout << "Creating & Initializing a new car..\n";
        this->name = name;
        this->price = price;
        mileage = new int;
        *mileage = 12;
    }

    //Custom Copy Constructor
    Car(Car &original) {
        cout << "copying..\n";
        name = original.name;
        price = original.price;
        mileage = new int;
        *mileage = *original.mileage;
    }

    //Getter
    string getName() {
        return name;
    }

    int getPrice() {
        return price;
    }

    int getMileage() {
        return *mileage;
    }

    //Setter
    // void setMileage(int mileage) {
    //     mileage = &mileage;
    // }

    ~Car() {
        cout << "object deletion..\n";
        if(mileage != NULL) {
            delete mileage;
            mileage = NULL;
        }
    }
};

//Inheritance
class Animal {
    string color;

public: 
    void eat() {
        cout << "eats\n";
    }

    void breathe() {
        cout << "breathes\n";
    }
};

class Fish : public Animal {
    int fins;

public:
    void swim() {
        cout << "swims\n";
    }
};

int main() {
    // Student s1;
    // cout << sizeof(s1) << endl;
    // s1.name = "shradha";
    // cout << s1.name << endl;

    // //Setter
    // s1.setCgpa(9.0);

    // //Getter
    // cout << s1.getCgpa() << endl;
    // s1.getPercentage();

    //Contructors
    // Car c1("maruti 800", 4);
    // cout << c1.getName() << endl;
    // cout << c1.getMileage() << endl;


    //Default Copy Constructor
    // Car c2(c1);
    // cout << "**************\n";
    // cout << c1.getName() << endl;
    // cout << c1.getPrice() << endl;
    // cout << c2.getMileage() << endl;

    // *c2.mileage = 15;
    // cout << c2.getMileage() << endl;
    // cout << c1.getMileage() << endl;

    //Inheritance
    Fish f1;
    f1.eat();
    f1.swim();
    return 0;    
}


