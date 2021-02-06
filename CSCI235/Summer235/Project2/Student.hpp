//Imran Sabur
//Project 1 CSCI 235
//This is the header file of the Student class. It inherits from person. 



#include <iostream>
#include <string>

#ifndef Student_hpp
#define Student_hpp
#include "Person.hpp" 

class Student: public Person 
{
public:

    //default constructor
    Student();

    //@param constructor, student's first name, last name and id
    Student(int id, std::string first, std::string last);

    //accessor method to return the major
    std::string getMajor() const;

    //accessor method to return the gpa
    double getGpa() const;
    
    //mutator function to set major @param major
    void setMajor(const std::string major);

    //mutator function to set gpa @param gpa
    void setGpa(const double gpa); 

protected:

    std::string major_;
    double gpa_; 

};//end student
#endif

