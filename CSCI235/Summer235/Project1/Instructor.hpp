//Imran Sabur
//Project 1 CSCI 235
//This is the header file of the Instructor class which inherits from Person. 

#ifndef Instructor_hpp
#define Instructor_hpp 

#include "Person.hpp"
#include <iostream>

class Instructor: public Person
{
public: 

    //default constructor
    Instructor(); 

    //@param constructor with id, first and last name of instructor
    Instructor(int id, std::string first, std::string last);

    //@return the office
    std::string getOffice() const;

    //@return contact
    std::string getContact() const;

    //mutator function @param office: a string variable
    void setOffice(const std::string office);

    //mutator fucntion @param contact, another string variable 
    void setContact(const std::string contact);

private:

    std::string office_;
    std::string contact_;

};//end Instructor 

#endif
