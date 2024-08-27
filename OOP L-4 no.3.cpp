#include <iostream>
#include <string>
using namespace std;


class Student {
protected:
    string name;
    int roll_no;

public:
    
    void readStudentData() {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> roll_no;
    }

    
    void displayStudentData() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll_no << endl;
    }
};


class Exam : public Student {
protected:
    int marks[5];

public:
    
    void readMarks() {
        cout << "Enter marks for 5 subjects:" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "Subject " << i + 1 << ": ";
            cin >> marks[i];
        }
    }

    
    void displayMarks() const {
        cout << "Marks in 5 subjects:" << endl;
        for (int i = 0; i < 5; ++i) {
            cout << "Subject " << i + 1 << ": " << marks[i] << endl;
        }
    }

    
    int totalMarks() const {
        int total = 0;
        for (int i = 0; i < 5; ++i) {
            total += marks[i];
        }
        return total;
    }
};

class Result : public Exam {
public:
  
    void displayResult() {
        displayStudentData();  
        displayMarks();       
        int total = totalMarks();
        float percentage = (float)total / 5.0;

        cout << "Total Marks: " << total << "/500" << endl;
        cout << "Percentage: " << percentage << "%" << endl;
    }
};


int main() {
    Result studentResult;

    

    studentResult.readStudentData();
    studentResult.readMarks();

   
    studentResult.displayResult();

    return 0;
}

