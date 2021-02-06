//Imran Sabur
//Project 3 CSCI 235
//This is the header file of the teaching assistant class. It inherits from student. 
//June 20,2019


#include <iostream>
#include <string>

#ifndef TeachingAssistant_hpp
#define TeachingAssistant_hpp
#include "Student.hpp"

enum ta_role {LAB_ASSISTANT, LECTURE_ASSISTANT, FULL_ASSISTANT}; 

class TeachingAssistant: public Student
{
public:

    //default constructor
    TeachingAssistant();

    //@param constructor that has id, first and last name of the teaching assistant
    TeachingAssistant(int id, std::string first, std::string last);
    
    //accessor function which returns the hours
    int getHours() const;

    //accessor function which returns the role of the enum
    ta_role getRole(); 

    //mutator function @param hours
    void setHours(const int hours);

    
    //mutator function @param role
    void setRole(const ta_role role); 

    void display() override; //overriden function

private:

    int hours_per_week_;
    ta_role role_; //role of type ta_role 


}; //end Teaching Assistant
#endif 