//Imran Sabur
//CSCI 235
//June 19, 2019
//This is an implementation of the instructor class which inherits from person class
//A display() method which is overridden in the abstract class, Person.

#include "Person.hpp"
#include "Instructor.hpp"

//default constructor inherits from person
Instructor::Instructor():Person(){

}

Instructor::Instructor(int id, std::string first, std::string last):Person(id,first,last) //member initialization list, inherits from Person
{
    office_ = ""; //empty string
    contact_ = ""; //empty string 
}

//mutator function
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

//displays Tizana Ligorio - office: 1000C, email: 235Instructors@hunter.cuny.edu
void Instructor::display() 
{
    std::cout << getFirstName() << " " << getLastName() << " - office: " << getOffice() << "," <<
    " email: " << getContact() << std::endl;
}