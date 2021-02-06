/* 
Imran Sabur
Project 1B
CSCI 235
Professor Ligorio

This program is an implementation student class.

*/

#include <iostream>
using namespace std;
#include "CourseMember.hpp"
#include "Student.hpp"
#include <string> 



Student::Student(int id, string first, string last):CourseMember(id,first,last)
{
    major_ = "";
    gpa_ = 0; 
    
}

void Student::displayMember()  
{
    cout << getFirstName() << " " << getLastName() << " " << "majors in " << getMajor() << "with gpa: " << getGpa()  << endl; 
}


void Student::setMajor(const string major)
{
    major_ = major;
}

void Student::setGpa(const double gpa)
{
    gpa_ = gpa;
}


string Student::getMajor() const
{
    return major_;
}

double Student::getGpa() const
{
    return gpa_;
}
