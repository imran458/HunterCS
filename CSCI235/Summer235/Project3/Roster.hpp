//Imran Sabur
//This is the header file of the Roster class
//Professor Ligorio
//June 19, 2019

//It inherits from List, adds Person pointers to Roster

#include "Node.hpp"
#include "List.hpp"
#ifndef Roster_hpp
#define Roster_hpp 
#include "Student.hpp"
#include "Person.hpp"
#include "TeachingAssistant.hpp"
 

class Roster: public List<Person*> //Template List of person pointers 
{
public:
  
  //default constructor 
  Roster();

   

 /**parameterized constructor
 @pre the input file is expected to be in csv
 (comma separated value) where each line has format:
 “id,first_name_last_name,title\n"
 @param input_file_name the name of the input csv file
 @post Pointers to Person are stored in the Roster, each pointer
 pointing to either a Student, Instructor or TeachingAssistant
 object as per the data in the input file and specified by the
 title field
 **/
 Roster(std::string input_file_name);


 /**@post displays all data in roster, one per line
 as per each object’s specific display method\n”
 **/ 
 void display(); 

  /**
  @return a number randomly sampled from
 {4.0, 3.75, 3.5, 3.25, 3.0, 2.75, 2.5, 2.25, 2.0}
  */
  double randGpa(); 

  /**
  @return a string randomly sampled from
 {"Computer Science", "Literature", "Music", "Philosophy", "Physics",
  "Theatre", "Computational Biology", "Mathematics", "Geography",
  "Linguistics"}
 */
  std::string randMajor();  

  /**
  @return a ta_role randomly sampled from
 {LAB_ASSISTANT, LECTURE_ASSISTANT,FULL_ASSISTANT}
 */
  ta_role randRole();





};

#endif 
