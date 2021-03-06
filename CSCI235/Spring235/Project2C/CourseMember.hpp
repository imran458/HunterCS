/**
// @file  CourseMember.hpp
//  Project1A
//
//  Created by Tiziana Ligorio on 1/14/19.
//  Copyright © 2019 Tiziana Ligorio. All rights reserved.

This program was modified by Imran Sabur to support polymorphism. Virtual functions were added along with one 
pure virtual function named by displaycoursemember
*/

#ifndef CourseMember_hpp
#define CourseMember_hpp

#include <string>

class CourseMember
{
public:

    CourseMember();
    /** Parameterized constructor
     @param id the student's unique identifier
     @param first the student's first name
     @param last the student's last name
     */
    CourseMember(int id, std::string first, std::string last);
    
    
    //********** Accessor Methods ****************


    virtual void displayMember() = 0;  

    
    /** @return returns id_; */
     int getID() const;
    
    /** @return returns first_name_ */
     std::string getFirstName() const;
    
    /** @return returns last_name_ */
     std::string getLastName() const;
    
private:
    int id_; /** the CourseMember's ID */
    std::string first_name_; /** the CourseMember's first name */
    std::string last_name_; /** the CourseMember's last name */
    
    
}; //end CourseMember

#endif /* CourseMember_hpp */
