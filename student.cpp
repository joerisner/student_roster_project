#include <iostream>
#include <string>
using namespace std;

#include "student.h"
#include "degree.h"

// Constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, int* days, DegreeProgram program) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    emailAddress = email;
    this->age = age;
    daysInCourse[0] = days[0];
    daysInCourse[1] = days[1];
    daysInCourse[2] = days[2];
    this->degreeProgram = program;
}

// Mutator (setter) Functions
void Student::SetStudentID(string id) { studentID = id; }
void Student::SetFirstName(string name) { firstName = name; }
void Student::SetLastName(string name) { lastName = name; }
void Student::SetStudentEmail(string email) { emailAddress = email; }
void Student::SetStudentAge(int age) { this->age = age; }
void Student::SetDaysInCourse(int days[]) {
    daysInCourse[0] = days[0];
    daysInCourse[1] = days[1];
    daysInCourse[2] = days[2];
}
void Student::SetDegreeProgram(DegreeProgram program) { degreeProgram = program; }

// Accessor (getter) Functions
string Student::GetStudentID() { return studentID; }
string Student::GetFirstName() { return firstName; }
string Student::GetLastName() { return lastName; }
string Student::GetEmail() { return emailAddress; }
int Student::GetStudentAge() { return age; }
int* Student::GetDaysInCourse() { return daysInCourse; } // Get pointer to the daysInCourse array
DegreeProgram Student::GetDegreeProgram() { return degreeProgram; }

// Format for printing:
// A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security
void Student::Print() {
    cout << studentID;
    cout << "\tFirst Name: " << firstName;
    cout << "\tLast Name: " << lastName;
    cout << "\tAge: " << age;
    cout << "\tdaysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "} ";
    if (degreeProgram == DegreeProgram::SECURITY) {
        cout << "Degree Program: Security";
    }
    if (degreeProgram == DegreeProgram::NETWORK) {
        cout << "Degree Program: Network";
    }
    if (degreeProgram == DegreeProgram::SOFTWARE) {
        cout << "Degree Program: Software";
    }
    cout << endl;
}



