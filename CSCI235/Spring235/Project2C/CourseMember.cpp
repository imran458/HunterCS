/*
 Imran Sabur
 CSCI 235
 Professor Ligorio
 Lab 1A

 This is an implementation of the interface provided as coursemember.hpp. Accesor functions
 are defined in this program.

 */


#include "CourseMember.hpp"
#include <iostream>
#include <string>


using namespace std;

/*This sets the parameters in the constructor equal to those listed 
the private access specficer */
CourseMember::CourseMember(int id, string first, string last)    
{
    id_ = id;
    first_name_ = first;
    last_name_ = last;
}

//Returns the first name
string CourseMember::getFirstName() const
{
    return first_name_;
}

//Returns last 
string CourseMember::getLastName() const 
{
    return last_name_;
}

//Returns id
int CourseMember::getID() const 
{
    return id_; 
}

