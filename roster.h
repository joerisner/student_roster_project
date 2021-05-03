#ifndef roster_h
#define roster_h

#include <string>
using namespace std;
#include "student.h"

class Roster {
public:
    void ParseStudentData(string studentDataString);
    void Add(string studentID,
             string firstName,
             string lastName,
             string emailAddress,
             int age,
             int daysInCourse1,
             int daysInCourse2,
             int daysInCourse3,
             DegreeProgram degreeProgram);
    void Remove(string studentID);
    void PrintAll();
    void PrintAverageDaysInCourse(string studentID);
    void PrintInvalidEmails();
    void PrintByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
    Student* classRosterArray[5]; // Array of pointers, not objects
private:
    const int ARR_SIZE = 5;
    int craIndex = 0;
};

#endif /* roster_h */
