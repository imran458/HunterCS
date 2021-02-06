/*

Imran Sabur
CSCI 235
Project 1B
Professor Ligorio

This is an implementation of the instructor class

*/

#include "Instructor.hpp"
#include "CourseMember.hpp"
#include <iostream>
using namespace std;



Instructor::Instructor(int id, string first, string last):CourseMember(id,first,last)
{
    office_ = "";
    contact_ = "";
}


void Instructor::displayMember() 
{

    cout << getFirstName() << getLastName() << "-office: " << getOffice() << " email " << getContact() << "\n" 


    //should print out tiziana ligrio 1001C email:
}




void Instructor::setOffice(const string office)
{
    office_ = office;
}

void Instructor::setContact(const string contact)
{
    contact_ = contact;
}

string Instructor::getOffice() const
{
    return office_; 
}

string Instructor::getContact() const
{
    return contact_; 
}