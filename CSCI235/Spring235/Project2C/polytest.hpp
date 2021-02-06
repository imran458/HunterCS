//Imran Sabur
//Projct 2C 235


#ifndef polytest_hpp
#define polytest_hpp
#include "CourseMember.hpp"
#include "List.hpp"
#include "Instructor.hpp"
#include "TeachingAssistant.hpp"



class polytest
{
public:

    /**
    @param cm_list the list to be populated with pointers to CourseMember
    @param input_file the file containing data used to generate CourseMemberderived objects to add to cm_list
    @post reads parameters from input_file to call addMemberToList()
    */
    void populateCmList(List<CourseMember*>& cm_list, std::string input_file);


    /**
    @post instantiates a new object - Student, TeachingAssistant or Instructor -
    as indicated by the title parameter, randomly generate relevant data not
    provided by parameters (e.g. major_, gpa_ etc.) and append a pointer to
    cm_list that points to the newly instantiated object
    */
    void addMemberToList(List<CourseMember*>& cm_list, int id, const std::string& first_name, const std::string& last_name, const std::string& title);



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

#include "polytest.cpp"
#endif