//


#include "Person.hpp"
#include "Student.hpp"
#include <iostream>
#include <string>

Student::Student():Person()
{

}

Student::Student(int id, std::string first, std::string last):Person(id,first,last) //member initiliazation list. 
{
  //  id_ = 0;

}

void Student::setMajor(const std::string major)
{
    major_ = major;
}

void Student::setGpa(const double gpa)
{
    gpa_ = gpa;
}


std::string Student::getMajor() const
{
    return major_;
}

double Student::getGpa() const
{
    return gpa_;
}
