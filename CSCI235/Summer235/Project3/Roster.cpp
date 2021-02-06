//Imran Sabur
//This is the header file of the Roster class
//Professor Ligorio
//June 20, 2019

//It inherits from List, adds pointers of Students, TA or Instructor to Roster


#include "Roster.hpp"
#include <iostream>
#include "Student.hpp"
#include "Person.hpp"
#include "TeachingAssistant.hpp"
#include "Node.hpp"
#include "Instructor.hpp" 
#include "List.hpp"
#include <sstream>
#include <fstream>
#include <string>
#include <ctime> 

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
Roster::Roster(std::string input_file_name)
{

    

    std::ifstream csv_file(input_file_name);
    if(!csv_file.is_open())
    {
        std:: cout << "File failed to open" << std::endl; 
    }else
    {
        std::string csv_line; //string to read csv file
        std::string id; //stores id 
        std::string first_name_; //stores  first_name
        std::string last_name_; //stores last name
        std:: string title;  //stores title 

        while(getline(csv_file,csv_line)) //for each line in file
        {
            std::stringstream ss(csv_line); //new stringstream objects
            getline(ss,id,','); //gets the id then stops at delimiter
            getline(ss,first_name_,','); //gets the next line after comma, stores it in name
            getline(ss,last_name_,',');//gets the next phrase after the comma, stores it in the last name
            getline(ss,title); //stop at title

             

            if(title == "student")
            {
                Student* s_ptr = new Student(stoi(id),first_name_,last_name_); //new student object of type student
                s_ptr->setGpa(randGpa());//sets student's gpa randomly 
                s_ptr->setMajor(randMajor()); //sets student's major randomly
                insert(item_count_,s_ptr); //insert it at item_count_
                

            }else if(title == "instructor"){
                Instructor* i_ptr = new Instructor(stoi(id),first_name_,last_name_); //new dynamically allocated object of Instructor
                i_ptr->setOffice("1000C"); //office is not random
                i_ptr->setContact("235Instructors@hunter.cuny.edu"); //contact will always be email
                insert(item_count_,i_ptr); //insert it in the list
                 
            
            }else if(title == "teaching_assistant")
            {
                TeachingAssistant* t_ptr = new TeachingAssistant(stoi(id),first_name_,last_name_); //dynamically allocate new TA
                t_ptr->setRole(randRole()); //set role randomly
                t_ptr->setHours(rand() % 2); //set gpa randomly
                t_ptr->setGpa(randGpa());  //set TA's gpa 
                insert(item_count_,t_ptr); //insert it in the list
                 


            }
            
            

        }

        
    
    }

}


/**
@return a string randomly sampled from
 {"Computer Science", "Literature", "Music", "Philosophy", "Physics",
"Theatre", "Computational Biology", "Mathematics", "Geography",
"Linguistics"}
 */
std::string Roster::randMajor()
{
    std::string major[10] = {"Computer Science", "Literature", "Music", "Philosophy", "Physics",
    "Theatre", "Computational Biology", "Mathematics", "Geography",
    "Linguistics"}; //array of majors

    int index = rand() % 9; //random number out of 10
    return major[index];  //return a random index in the array
}

double Roster::randGpa()
{
    return rand() % 4; 
}

/**
@return a ta_role randomly sampled from
{LAB_ASSISTANT, LECTURE_ASSISTANT,FULL_ASSISTANT}
*/
ta_role Roster::randRole()
{
    ta_role role[3] = {LAB_ASSISTANT, LECTURE_ASSISTANT,FULL_ASSISTANT};
    int index = rand() % 2;
    return role[index]; 
}

/**@post displays all data in roster, one per line
 as per each object’s specific display method\n”
 **/

void Roster::display()
{
    Node<Person*>* person_ptr = first_; //points to the first item in the list

    while(person_ptr != nullptr) //iterate 
    {
        person_ptr->getItem()->display(); //display the item per the object's method

        person_ptr = person_ptr->getNext(); //update person_ptr
    }
}

//default constructor 
Roster::Roster()
{}




