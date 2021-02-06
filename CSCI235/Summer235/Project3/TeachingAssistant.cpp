//Imran Sabur
//Project 3 CSCI 235
//June 19, 2019
//This is the implementation of the teaching assistant class


#include "Student.hpp"
#include "TeachingAssistant.hpp"
#include <iostream>

TeachingAssistant::TeachingAssistant():Student(){

}


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

ta_role TeachingAssistant::getRole()  
{
    return role_; 
}


//displays “first_name_ last_name_ majors in major_ with gpa: gpa_
// working [part-time/full-time] as a ta_role_\n”
void TeachingAssistant::display() 
{

    std::string time; //new variable to hold tie
    std::string role = ""; 
    
    //condition for full-time or part time
    if(getHours() > 8){
        time = "full-time";
    }else{
        time = "part-time"; 
    }

    //role = 0,1,2
    //role 0 = Lab_ASSISTANT
    //role 1 = lecture assistant
    //role 2 = full_assistnt



    if(getRole() == 0){ //if the enum is at value 0 then lab
        role = "LAB_ASSISTANT";
    }else if(getRole() == 1){ 
        role = "LECTURE_ASSISTANT";
    }else if(getRole() == 2){
        role = "FULL_ASSISTANT"; 
    }


    std::cout << getFirstName() << " " << getLastName() << " majors in " << getMajor() << " with gpa: " <<
    getGpa() << " working " << time << " as a " << role << std::endl;

}

