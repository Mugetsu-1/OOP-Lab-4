#include <iostream>
#include <string>

using namespace std;

// Base class
class Lecturer {
protected:
    string name;
    int id;

public:
    Lecturer(string n, int i) : name(n), id(i) {}

    // Virtual function to be overridden in derived classes
    virtual void displayDetails() {
        cout << "Lecturer Name: " << name << ", ID: " << id << endl;
    }
};

// Derived class PartTimeFaculty
class PartTimeFaculty : public Lecturer {
private:
    double payPerHour;

public:
    PartTimeFaculty(string n, int i, double pph) : Lecturer(n, i), payPerHour(pph) {}

    // Overriding displayDetails function
    void displayDetails() override {
        cout << "Part-Time Faculty Name: " << name << ", ID: " << id << ", Pay Per Hour: $" << payPerHour << endl;
    }
};

// Derived class FullTimeFaculty
class FullTimeFaculty : public Lecturer {
private:
    double salary;

public:
    FullTimeFaculty(string n, int i, double s) : Lecturer(n, i), salary(s) {}

    // Overriding displayDetails function
    void displayDetails() override {
        cout << "Full-Time Faculty Name: " << name << ", ID: " << id << ", Salary: $" << salary << endl;
    }
};

int main() {
    // Creating objects of derived classes
    PartTimeFaculty ptf("Ello", 101, 200.0);
    FullTimeFaculty ftf("Bambi", 102, 80000.0);

    // Demonstrating function overriding
    Lecturer* lecturer1 = &ptf;
    Lecturer* lecturer2 = &ftf;

    lecturer1->displayDetails(); 
    lecturer2->displayDetails(); 

    return 0;
}

