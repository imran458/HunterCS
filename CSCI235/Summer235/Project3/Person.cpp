//Imran Sabur
//Project 3 CSCI 235
//June 20,2019
//This is the implementation of the person class.

#include "Person.hpp"
#include <iostream>
#include <string> 


Person::Person():id_(-1), first_name_(""), last_name_(""){};

Person::Person(int id, std::string first, std::string last)
{
    id_ = id; //set id to param
    first_name_ = first; //set first name to param
    last_name_ = last;
}

std::string Person::getFirstName() const
{
    return first_name_; //
}

std::string Person::getLastName() const
{
    return last_name_;

}

int Person::getID() const
{
    return id_; 
}

bool operator==(const Person& person1,const Person& person2)
{
    return(person1.first_name_ == person2.first_name_ && person1.last_name_ == person2.last_name_ && person1.id_ == person2.id_);
    
}
