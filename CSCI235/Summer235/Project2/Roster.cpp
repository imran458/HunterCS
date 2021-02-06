//Imran Sabur
//CSCI 235
//June 11, 2019

//This is the implementation of the Roster class. It contains 2 methods and a default constructor
//


#include "Roster.hpp"
#include <iostream>
#include "ArrayBag.hpp"
#include "Student.hpp"
#include <sstream>
#include <fstream>
#include <string>


/**parameterized constructor
@pre the input file is expected to be in CSV
comma separated value) where each line has format:
“id,first_name_,last_name\n"
@param input_file_name the name of the input csv file
@post Student objects are added to roster as per the data
n the input file
**/
Roster::Roster(std::string input_file_name)
{
    std::ifstream csv_file(input_file_name);
    if(!csv_file.is_open())
    {
        std:: cout << "File failed to open" << std::endl; //error message 
    }else
    {
        std::string csv_line; //string to read csv file
        std::string id; //stores id 
        std::string first_name_; //stores  first_name
        std::string last_name_; //stores last name


        while(getline(csv_file,csv_line)) //for each line in csv file
        {
            std::stringstream ss(csv_line); //new stringstream object 
            getline(ss,id,','); //first item in file is id, reads id and stores it in string variable until it hits a comma
            getline(ss,first_name_,',');    //reads next item and stores it in first name until it hits a comma
            getline(ss,last_name_); // reads last name, does not need delimiter as param

            Student s1(std::stoi(id),first_name_,last_name_);   //add csv elements to student objects
            add(s1); //add to this bag

        }

    
    }

}
    

/**@post displays all students in roster, one per line
 in the form "first_name_ last_name_\n"
 **/

void Roster::display()
{
    //for each item in roster, display first name "space" last name
 for(int i = 0; i < item_count_ ; i++)
  {
    std:: cout << items_[i].getFirstName() << " " << items_[i].getLastName();  
  }   

  std::cout << std::endl;
}

//default constructor 
Roster::Roster()
{}




