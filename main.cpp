#include<iostream>
#include<iomanip>
#include <string>
#include "roster.h"
using std::string;
using std::cout;
using std::cerr;

using namespace std;

int main()
{

    cout << "\t" <<" -- COURSE TITLE --" << endl << endl;
    cout << "SCRIPTING AND PROGRAMMING APPLICATIONS - C867" << endl << endl;
    cout << "\t" << "--PROGRAMMING LANGUAGE--" << endl << endl;
    cout << "                 C++ " << endl << endl;
    cout << "\t" << "-- STUDENT ID AND NAME --" << endl << endl;
    cout << "\t" << "ID - 000897282 - Michael Curran" << endl << endl << endl;


    Roster* classRoster = new Roster(numStudents);//creates roster
    cout << "Parsing data and adding students:\t";
    for (int i = 0; i < numStudents; i++)
    {
        classRoster->parseAdd(studentData[i]);//parse each line turns them into student objects
    }
    cout << "Done.\n";
    cout << "\n";
    cout << "Displaying all students:\n";
    classRoster->print_All();//displaying all students in the roster
    cout << "\n";

    classRoster->printInvalidEmails();
    cout << "\n";

    classRoster->printbyDegreeType(SOFTWARE);
    cout << "\n";

    classRoster->printAverageDays("A3");//prints average days remaining of specified ID
    cout << "\n";

    cout << "Removing A3:\n"; // Remove the student with the supplied ID
    classRoster->remove("A3");
    cout << "\n";
    classRoster->print_All(); //prints all to show removal
    cout << "\n";

    cout << "Removing A3:\n"; //Remove the student again to check error coindition
    classRoster->remove("A3");
    cout << "\n";

    system("pause");//holds console window up in vstudio
    return 0; //finished!
}
