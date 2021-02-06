/*
Imran Sabur
Project 1B
CSCI 235
Professor Ligorio

This file contains the function prototypes of the Student class which is derived from 
CourseMember.

*/

#ifndef Student_hpp
#define Student_hpp
#include "CourseMember.hpp"


class Student: public CourseMember //the student class derives from coursemember
{
public:


    //Parameteritized constructor with the given variables
    Student(int id, std::string first, std::string last);
 
    //ACCESSOR FUNCTIONS:

    //This function returns the major of the student
     std::string getMajor() const;

    //This function return the gpa of the student
     double getGpa() const;

    //MUTATOR FUNCTIONS:

    //sets major
     void setMajor(const std::string major);

    //this function sets gpa 
     void setGpa(const double gpa);

    virtual void displayMember() override; 

protected:
    std::string major_; 
    double gpa_;

}; //Student class ends

#endif