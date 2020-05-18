#include <iostream>
#include<string>
#include "roster.h"

using namespace std;

Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}

void Roster::parseAdd(string row)
{
    if (lastIndex < capacity) {
        lastIndex++;
        int darray[Student::daysArraySize];//temporary array to hold days
        this->classRosterArray[lastIndex] = new Student();

        //setting ID
        int rhs = studentData[lastIndex].find(",");
        classRosterArray[lastIndex]->setID(studentData[lastIndex].substr(0, rhs));

        //read first name
        int lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

        //read last name
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

        //read email
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setEmailAddress(studentData[lastIndex].substr(lhs, rhs - lhs));

        //read age
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        classRosterArray[lastIndex]->setAge(stoi(studentData[lastIndex].substr(lhs, rhs - lhs)));

        //read each day
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        darray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        darray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        darray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

        //set the days
        classRosterArray[lastIndex]->setDays(darray);

        //set the degree type
        lhs = rhs + 1;
        rhs = studentData[lastIndex].find(",", lhs);
        if (studentData[lastIndex].substr(lhs, rhs - lhs) == "SECURITY")
        {
            classRosterArray[lastIndex]->setDegreeType(SECURITY);
        }
        else if (studentData[lastIndex].substr(lhs, rhs - lhs) == "NETWORK")
        {
            classRosterArray[lastIndex]->setDegreeType(NETWORK);
        }
        else {
            classRosterArray[lastIndex]->setDegreeType(SOFTWARE);
        }

    }
    else
    {
        cerr << "ERROR! LIST HAS EXCEEDED MAXIMUM CAPACITY\n EXITING NOW";
        exit(-1);
    }

}

void Roster::print_All()//go tthrough array of students and printfor each
{
    for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

void Roster::remove(string ID)
{
    bool found = false;
    for (int i = 0; i <= lastIndex; ++i) {
        if (this->classRosterArray[i]->getID() == ID)
        {
            found = true;
            //delete it
            delete this->classRosterArray[i];
            this->classRosterArray[i] = this->classRosterArray[lastIndex];
            lastIndex--;//roster is one element smaller
        }
    }
    if (found == false) {
        cout << "Student with ID " << ID << " was not found." << endl;
    }
    else {
        cout << ID << " Removed Successfully" << endl;
    }
}

void Roster::printAverageDays(string studentID)
{
    int average = 0;
    bool found = false;
    for (int i = 0; i <= lastIndex; i++)
    {
        if (this->classRosterArray[i]->getID() == studentID)
        {
            found = true;
            int* d = classRosterArray[i]->getDays();
            average = (d[0] + d[1] + d[2]) / 3;
            cout << "Average days remaining for (" << studentID << ")" <<"\n";
            cout << "(" << studentID << "): " << average << "\n";

        }
    }
    if (!found) cout << "Student not found!\n";
}

void Roster::printInvalidEmails()
{
    cout << "Displaying invalid email entries:\n";
    for (int i = 0; i <= lastIndex; i++)
    {
        string email = classRosterArray[i]->getEmailAddress();
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
        {
            cout << "The email for student: " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << " is not valid: " << email << endl;

        }
    }
}

void Roster::printbyDegreeType(DegreeType d)
{
    cout << "Printing students by degree type " << degreeTypeStrings[d] << "\n";
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->getDegreeType() == d) this->classRosterArray[i]->print();
    }
}

Roster::~Roster()//destroys all student objects
{
    for (int i = 0; i < numStudents; i++)
    {
        delete this->classRosterArray[i];
    }
    delete this;
}

//roster.cpp above here