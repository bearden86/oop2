#include <iostream>
#include <string>
using namespace std;

//class is a template for creating objects, describes the structure
//object is an instance of a class
//object is a specific instance of a class (example)
//object is an instance of a class that has specific values for the attributes of the class
//instantiating - creating an object from a class
//data members - variables
//methods - functions

//abstraction - concept that makes something easy by hiding the complicated stuff
//encapsulation - granting access to private data through controlled public interfaces
//inheritance - create derived (children) classes that inherit properties from parent classes
//polymorphism - ability to use a single interface with different implementations


class Person { //class describes structure
private:
    string first;
    string last;

    public:
    void setFirstName(string first) { 
        this->first = first; 
    }
    void setLastName(string last) { 
        this->last = last; 
    }
    string getName() {
        return first + " " + last;
    }
    //getter (accessor) - returns value of a variable
    //setter (mutator) - sets value of a variable
    //constructor - special method that is called when an object is created
    //destructor - special method that is called when an object is destroyed
    void printFullName() {
        cout << first << " " << last << endl;
    }
};


int main() {
    Person p; //object that is a specific instance of the Person class; this is "instantiating"
    p.setFirstName("Matt");
    p.setLastName("Bearden");

    Person p2;
    p2.setFirstName("John");
    p2.setLastName("Smith");

    p.printFullName();
    p2.printFullName();
    cout << p.getName() << endl;
    return 0;
}