//Imran Sabur
//CSCI 235
//This is an implementation of the instructor class which inherits from person class.

#include "Person.hpp"
#include "Instructor.hpp"


Instructor::Instructor(int id, std::string first, std::string last):Person(id,first,last) //member initialization list, inherits from Person
{
    office_ = ""; //empty string
    contact_ = ""; //empty string 
}

void Instructor::setOffice(const std::string office)
{
    office_ = office;
}

void Instructor::setContact(const std::string contact)
{
    contact_ = contact;
}

std::string Instructor::getOffice() const
{
    return office_; 
}

std::string Instructor::getContact() const
{
    return contact_; 
}