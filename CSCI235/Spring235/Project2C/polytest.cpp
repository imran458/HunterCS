//Imran Sabur
//Project 2C

//implementation of polytest


#include <iostream>
#include <string> 
#include "polytest.hpp"


#include <fstream>

ta_role randRole()
{
    ta_role role[3] = {LAB_ASSISTANT,LECTURE_ASSISTANT,FULL_ASSISTANT};
    int index = rand() % 2;
    return role[index];


    
}
double randGpa()
{
    return rand() % 4; 
}

std::string randMajor()
{
    std::string major[10] = {"Computer Science","Literature","Music","Philosophy","Physics","Theatre","Computational Biology","Mathematics","Geography","Linguistics"};
    int index = rand() % 9;
    return major[index];

    

}



void addMemberToList(List<CourseMember*>& cm_list, int id, const std::string& first_name, const std::string& last_name, const std::string& title)
{

    CourseMember* c_ptr;
    if(title == "Student")
    {
        Student* s_ptr = new Student(id, first_name, last_name);
    //select random gpa and major
        s_ptr->setGpa(randGpa());
        s_ptr->setMajor(randMajor());
        c_ptr = s_ptr; 
    }
    if(title == "Instructor")
    {
        Instructor* s_ptr = new Instructor(id,first_name,last_name);
        s_ptr->setOffice("1001C");
        s_ptr->setContact("235Instructors@hunter.cuny.edu");
        c_ptr = s_ptr;  

    }
    if(title == "Teaching Assistant")
    {
        TeachingAssistant* s_ptr = new TeachingAssistant(id,first_name,last_name);
        s_ptr->setRole(randRole()); 
        s_ptr->setHours(rand() % 2);
        s_ptr->setGpa(randGpa());
        s_ptr->setRole(randRole());

        c_ptr = s_ptr;  
         
    }
    cm_list.insert(cm_list.getLength(),c_ptr); 
}

void populateCmList(List<CourseMember*>& cm_list, std::string input_file)
{

    int id; 
    std::string id_; 
    std::string first_name; 
    std::string last_name; 
    std::string title; 
    std::fstream in_stream(input_file);

    if(!in_stream.is_open())
    {
        std::cerr << "cannot read from input file: " <<  input_file << std::endl;
        return; 
    }
    while(std::getline(in_stream, id_, ',') && std::getline(in_stream, first_name,',') && std::getline(in_stream,last_name, ',') &&  std::getline(in_stream,title,'\n'))
    {
        if(!in_stream.eof())
        {
            title.pop_back();
        }
        id = stoi(id_);

        addMemberToList(cm_list,id,first_name,last_name,title);

    }
    

    in_stream.close(); 

        


    
}






