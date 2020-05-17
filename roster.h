#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <list>
#include <string>
#include "student.h"
using namespace std;

//roster.h below here
const int numStudents = 5;

const string studentData[numStudents] =
{
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Michael,Curran,mcurra8@wgu.edu,28,32,18,21,SOFTWARE"
    //string goes here
};

//Roster stores a collection of students
class Roster {
public:
    int lastIndex;
    int capacity;
    Student** classRosterArray;
    Roster();
    Roster(int capacity);
    void parseAdd(string datarow);
    void print_All();
    bool remove(string studentID);
    void printAverageDays(string studentID);
    void printInvalidEmails();
    void printbyDegreeType(DegreeType d);

    ~Roster();
};
//roster.h above  heree

#endif
