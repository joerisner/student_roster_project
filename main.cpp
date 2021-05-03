#include <iostream>
#include <string>
using namespace std;

#include "student.h"
#include "roster.h"

int main() {
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,John,Doe,johndoe@example.com,35,30,60,45,SOFTWARE"
    };
    
    Roster classRoster;

    // Parse studentData array, create student objects from each element, and add them to classRoster.
    for (int i = 0; i < 5; i++) {
        classRoster.ParseStudentData(studentData[i]);
    }

    cout << "####  Print All  ####\n";
    classRoster.PrintAll();
    cout << endl;
    
    cout << "####  Print Invalid Emails  ####\n";
    classRoster.PrintInvalidEmails();
    cout << endl;
    
    cout << "####  Print Average Days In Course  ####\n";
    for (int n = 0; n < 5; n++) {
        string id = classRoster.classRosterArray[n]->GetStudentID();
        cout << "Student ID " << id << " ";
        classRoster.PrintAverageDaysInCourse(id);
    }
    cout << endl;
    
    cout << "####  Print By Degree Program  ####\n";
    classRoster.PrintByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;
    
    cout << "####  Remove student w/ ID: A3  ####\n";
    classRoster.Remove("A3");
    cout << endl;
    
    cout << "####  Print All  ####\n";
    classRoster.PrintAll();
    cout << endl;
    
    cout << "####  Try to remove student A3 again  ####\n";
    classRoster.Remove("A3");
    cout << endl;
    
    // Call Destructor to release memory allocated by classRoster (set classRosterArray pointers to NULL).
    classRoster.~Roster();
    
    return 0;
}
