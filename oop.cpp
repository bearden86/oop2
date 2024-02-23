#include <iostream>
#include <string>
#include <vector> 
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


class Person { //class describes structure //parent class 
private: //if you change access modifier to "protected" you can access private data from derived classes 
    string first;
    string last;

    public:
    Person(string first, string last): first(first), last(last) {} //constructor allows pass in data
    Person() = default; //allows creation of empty object

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
    virtual void printInfo() { //virtual and override are associated, virtual allows derived class to override base class
        cout << "first name: " << first << endl;
        cout << "last name: " << last << endl;
    }
    static void printPeople(vector<Person*> people) {
        for(auto person: people) {
            person->printInfo();
        }
    }
};

class Employee: public Person {  //derived class
    string department;
    public:
    Employee(string firstName, string lastName, string department): Person(firstName, lastName), department(department) {}
    Employee() = default;
    string getDepartment() { return department; }
    void setDepartment(string department) {
        this->department = department;
    }
    void printInfo() override {
        cout << "name: " << getName() << endl; //if modifier = protected, cout << "first name: " << first << endl;
        cout << "department: " << department << endl; //if modifier = protected, cout << "last name: " << last << endl;
    }
};


int main() {
    vector<Person*> people;

    // Person p("Matt", "Bearden"); // to use constructor
    Person p; //object that is a specific instance of the Person class; this is "instantiating"
    p.setFirstName("Matt");
    p.setLastName("Bearden");

    // Person p2("John", "Smith"); // to use a constructor 
    Person p2;
    p2.setFirstName("John");
    p2.setLastName("Smith");

    p.printFullName();
    p2.printFullName();
    cout << p.getName() << endl;

    Person p3; //to use a default constructor, not pass in any data  
    p3.printFullName();

    Employee e;
    e.setFirstName("Jared"); //access 
    e.setLastName("Bearden");
    e.printFullName();

    Employee e2("Derek", "Bearden", "Software");
    e2.printFullName();
    cout << e2.getDepartment() << endl;
    e2.printInfo();

    people.push_back(&p);
    people.push_back(&e);

    Person::printPeople(people);

    for(auto person: people) {
        person->printInfo();
    }

    return 0;
}
    