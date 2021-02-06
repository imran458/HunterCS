//Imran Sabur
//This is the header file of the Roster class
//Professor Ligorio
//June 11, 2019

//It inherits from arraybag, adds student objects to Roster

#ifndef Roster_hpp
#define Roster_hpp 
#include "Student.hpp"
#include "ArrayBag.hpp"
 

class Roster: public ArrayBag<Student> //Template ArrayBag of type Student, because student objects 
{
public:
  
  //default constructor 
    Roster();



 /**parameterized constructor
 @pre the input file is expected to be in CSV
 (comma separated value) where each line has format:
 “id,first_name_,last_name\n"
 @param input_file_name the name of the input csv file
 @post Student objects are added to roster as per the data
 in the input file
 **/
 Roster(std::string input_file_name);


 /**@post displays all students in roster, one per line
 in the form "first_name_ last_name_\n"
 **/
 void display(); 






};

#endif 
