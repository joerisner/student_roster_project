#include <iostream>
#include <string>
using namespace std;

#include "roster.h"
#include "student.h"

// Parse the studentDataString by comma delimiters, then call the Add function
// to create pointers for each student object based on the parsed variables
void Roster::ParseStudentData(string studentDataString) {
  
    size_t rhs = studentDataString.find(",");
    string id = studentDataString.substr(0, rhs);
    
    size_t lhs = rhs + 1;
    rhs = studentDataString.find(",", lhs);
    string first = studentDataString.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentDataString.find(",", lhs);
    string last = studentDataString.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentDataString.find(",", lhs);
    string email = studentDataString.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentDataString.find(",", lhs);
    int age = stoi(studentDataString.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentDataString.find(",", lhs);
    int days1 = stoi(studentDataString.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentDataString.find(",", lhs);
    int days2 = stoi(studentDataString.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentDataString.find(",", lhs);
    int days3 = stoi(studentDataString.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = studentDataString.find('\0', lhs);
    string degreeString = studentDataString.substr(lhs, rhs - lhs);
    DegreeProgram prog = DegreeProgram::SOFTWARE;
    if (degreeString == "SECURITY") {
        prog = DegreeProgram::SECURITY;
    }
    if (degreeString == "NETWORK") {
        prog = DegreeProgram::NETWORK;
    }
    
    Add(id, first, last, email, age, days1, days2, days3, prog);
}

// Create a new pointer to a student object (classRosterArray is an array of pointers, not objects)
// and increment craIndex so that classRosterArray at index 0 doesn't just get created 5 times
void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int tmpArray[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
    classRosterArray[craIndex] = new Student(studentID, firstName, lastName, emailAddress, age, tmpArray, degreeProgram);
    craIndex++;
}

// Iterate over classRosterArray and call Student::Print() on each student object
void Roster::PrintAll() {
    for (int i = 0; i < ARR_SIZE; i++) {
        if (classRosterArray[i] != NULL) {
            classRosterArray[i]->Print();
        }
    }
}

// Print a student's average number of days in three courses
void Roster::PrintAverageDaysInCourse(string studentID) {
    for (int i = 0; i < ARR_SIZE; i++) {
        if (classRosterArray[i]->GetStudentID() == studentID) {
            int* daysArray = classRosterArray[i]->GetDaysInCourse();
            cout << "Average Days in Courses: " << (daysArray[0] + daysArray[1] + daysArray[2]) / 3 << endl;
        }
    }
}

void Roster::PrintInvalidEmails() {
    char invalidChar = ' ';
    char requiredChars[2] = {'@', '.'};
    
    for (int i = 0; i < ARR_SIZE; i++) {
        string tmpEmail = classRosterArray[i]->GetEmail();
        if (tmpEmail.find(invalidChar) != tmpEmail.npos) {
            cout << "Email: " << tmpEmail << " includes invalid space character" << endl;
        }
        if (tmpEmail.find(requiredChars[0]) == tmpEmail.npos) {
            cout << "Email: " << tmpEmail << " is missing the '@' character" << endl;
        }
        if (tmpEmail.find(requiredChars[1]) == tmpEmail.npos) {
            cout << "Email: " << tmpEmail << " is missing the '.' character" << endl;
        }
    }
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < ARR_SIZE; i++) {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->Print();
        }
    }
}

// Remove student from classRosterArray by studentID and print error if studentID is not found
void Roster::Remove(string studentID) {
    int idCount = 0;
    for (int i = 0; i < ARR_SIZE; i++) {
        if (classRosterArray[i] != NULL) {
            string id = classRosterArray[i]->GetStudentID();
            if ( id == studentID) {
                delete classRosterArray[i];
                classRosterArray[i] = nullptr; // The pointer at this index must be set to NULL to deallocate memory
                cout << "Student ID " << id << " removed" << endl;
                break; // Break out of the loop if the student is found and removed
            }
            else {
                idCount++;
            }
            if (idCount >= ARR_SIZE) {
                cout << "Error: Student not found by Remove function\n";
            }
        }
        else {
            cout << "Student with ID " << studentID << " was not found." << endl;
        }
    }
}

// Destructor
// Loop through the classRosterArray and delete each student pointer and set it equal to nullptr
Roster::~Roster() {
    for (int i = 0; i < ARR_SIZE; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

