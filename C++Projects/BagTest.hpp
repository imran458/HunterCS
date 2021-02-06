/*
Imran Sabur
CSCI 235
This is the definition of the bag test class.
*/




#ifndef BagTest_hpp
#define BagTest_hpp
#include "ArrayBag.hpp"
#include "CourseMember.hpp"


class BagTest
{
public:

    void displayCourseMemberBag(const ArrayBag<CourseMember>& a_bag); 


    ArrayBag<CourseMember> testCourseMemberBag(); 

private:

     

    ArrayBag<CourseMember> bag_; 
    ArrayBag<CourseMember> createBagFromInput(std::string input_file);
};

#include "BagTest.cpp"
#endif 

