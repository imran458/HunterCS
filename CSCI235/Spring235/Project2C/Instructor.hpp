/*
Imran Sabur
CSCI 235
Project 1B
Professor Ligorio

This program is an definition of the Instructor class. 

*/

#ifndef Instructor_hpp 
#define Instructor_hpp
#include "CourseMember.hpp"

class Instructor: public CourseMember
{
public: 

    Instructor(int id, std::string first, std::string last);

     void displayMember() override; 

    std::string getOffice() const;

    std::string getContact() const;

    void setOffice(const std::string office);

    void setContact(const std::string contact);

private:

    std::string office_;
    std::string contact_;
};

#endif 


