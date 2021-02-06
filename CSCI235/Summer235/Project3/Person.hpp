//Imran Sabur
//Project 3 CSCI 235
//June 20, 2019
//This is the implementation of the teaching assistant class

//This is the definition of the Person class.

#include <iostream>
#include <string> 

#ifndef Person_hpp
#define Person_hpp

class Person
{
public:

    //default constructor
    Person();

    //parameterized constructor @param id of person, first and last name 
    Person(int id, std::string first, std::string last);

    //function that returns id
    int getID() const;
    
    //function that returns first name
    std::string getFirstName() const;

    //function that returns last name
    std::string getLastName() const;

    friend bool operator==(const Person& person1,const Person& person2); //overloading operator 
    
    virtual void display() = 0; //pure virtual function
    

protected:

    int id_;
    std::string first_name_;
    std::string last_name_; 


};//Person class ends

#endif 