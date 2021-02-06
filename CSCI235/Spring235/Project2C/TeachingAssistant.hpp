/*
Imran Sabur
CSCI 235
Project 1B
Professor Ligorio

This is the definition of the teaching assistant class.

*/

#ifndef TeachingAssistant_hpp
#define TeachingAssistant_hpp
#include "Student.hpp"
#include "CourseMember.hpp"

enum ta_role {LAB_ASSISTANT, LECTURE_ASSISTANT, FULL_ASSISTANT}; 

class TeachingAssistant: public Student
{
public:
    TeachingAssistant(int id, std::string first, std::string last);

    int getHours() const;

    ta_role getRole() const;

    void setHours(const int hours);

    void setRole(const ta_role role); 

    void displayMember() override; 

private:

    int hours_per_week_;
    ta_role role_; 
};

#endif
