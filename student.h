#ifndef student_h
#define student_h

#include <string>
using namespace std;

#include "degree.h"

class Student {
public:
    Student(string studentID,
            string firstName,
            string lastName,
            string email,
            int age,
            int* days,
            DegreeProgram program);
    void SetStudentID(string id);
    void SetFirstName(string name);
    void SetLastName(string name);
    void SetStudentEmail(string email);
    void SetStudentAge(int age);
    void SetDaysInCourse(int* days);
    void SetDegreeProgram(DegreeProgram program);
    string GetStudentID();
    string GetFirstName();
    string GetLastName();
    string GetEmail();
    int GetStudentAge();
    int* GetDaysInCourse();
    DegreeProgram GetDegreeProgram();
    void Print();
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;
};

#endif /* student_h */
