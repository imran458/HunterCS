//Imran Sabur
//Project 1 CSCI 235
//This is the implementation of the teaching assistant class


#include "Student.hpp"
#include "TeachingAssistant.hpp"
#include <iostream>




TeachingAssistant::TeachingAssistant(int id, std::string first, std::string last):Student(id,first,last) //member initialization list
{
    hours_per_week_ = 0; //initiliaze to 0 

}

void TeachingAssistant::setRole(const ta_role role)
{
    role_ = role; 
}

void TeachingAssistant::setHours(const int hours)
{
    hours_per_week_ = hours; 
}

int TeachingAssistant::getHours() const
{
    return hours_per_week_;
}

ta_role TeachingAssistant::getRole() const 
{
    return role_; 
}