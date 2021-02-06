/*
Imran Sabur
CSCI 235
Project 1B
Professor Ligorio


This is the implementation of the teaching assistant class.

*/

#include "TeachingAssistant.hpp"
#include "Student.hpp"
#include <iostream>
using namespace std; 

TeachingAssistant::TeachingAssistant(int id, string first, string last):Student(id,first,last)
{
    hours_per_week_ = 0;

}

void TeachingAssistant::setRole(const ta_role role)
{
    role_ = role; 
}


TeachingAssistant::displayMember()  
{

    std::string time;

    if((getHours() >8) time = "full-time" );
    else time = "part time"
    if(getRole() == 0)role= "LAB_ASSISTANT";
    if(getRole() == 1)role ="LECTURE_ASSISTANT";
    if(getRole() == 2)role = "FULL_ASSISTANT"; 
    
    std::cout << getFirstName() << getLastName() << "majors in " << getMajor() << "with gpa: " << getGpa() << "working " << time << "as a " << role << std::endl;  
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