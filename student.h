#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

//student.h underneath
class Student
{
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int* days;
    DegreeType degtype;

public:
    const static int daysArraySize = 3;
    Student();
    Student(string ID, string firstName, string lastName, string emailAddress, int age, int days[], DegreeType type);

    //getters for each
    string getID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDays();
    DegreeType getDegreeType();

    //setters for each
    void setID(string ID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDays(int days[]);
    void setDegreeType(DegreeType d);
    void print();

    //destructor
    ~Student();
};
//sttudent.h above here

#endif