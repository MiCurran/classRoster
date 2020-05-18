#include <iostream>
#include <iomanip>
#include "student.h"
using namespace std;

//sttudentt.cpp below
Student::Student()
{
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->days = new int[daysArraySize];
    for (int i = 0; i < daysArraySize; i++) this->days[i] = 0;
    this->degtype = SECURITY;
}

Student::Student(string ID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeType type)
{
    this->studentID = ID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->days = new int[daysArraySize];
    for (int i = 0; i < 3; i++) this->days[i] = days[i];
    this->degtype = type;
}

//getters
string Student::getID()
{
    return studentID;
}

string Student::getFirstName()
{
    return firstName;
}
string Student::getLastName()
{
    return lastName;
}
string Student::getEmailAddress()
{
    return emailAddress;
}
int Student::getAge()
{
    return age;
}
int* Student::getDays()
{
    return days;
}
DegreeType Student::getDegreeType()
{
    return degtype;
}

void Student::setID(string ID)
{
    studentID = ID;
}

void Student::setFirstName(string firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
    this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
    this->age = age;
}

void Student::setDays(int days[])
{
    this->days = new int[daysArraySize];
    for (int i = 0; i < 3; i++)
        this->days[i] = days[i];
}

void Student::setDegreeType(DegreeType d) {
    this->degtype = d;
}

void Student::print()
{    
    cout << left << getID() << "\t";
    cout << left << "First Name: " << getFirstName() << "\t";
    cout << left << "Last Name: " << getLastName() << "\t";
    cout << left << "Age: " << getAge() << "\t" << "\t";
    cout << left << "Days in course: {" << getDays()[0] << ",";
    cout << left << getDays()[1] << ",";
    cout << left << getDays()[2] << "}\t";
    cout << left << degreeTypeStrings[getDegreeType()] << "\n";   
}

Student::~Student()
{
    if (days != nullptr) {
        delete[] days;
        days = nullptr;
    }
}//student.cpp above here