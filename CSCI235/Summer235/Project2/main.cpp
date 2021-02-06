#include <iostream>
#include "ArrayBag.hpp"
#include "Roster.hpp"
#include "Person.hpp"
#include "Student.hpp"
//#include <sstream>
//#include <fstream>
#include <string>

int main()
{
/*
std::cout<<"Starting"<<std::endl;
    bag1;
    Roster bag2; 
    Student John(123,"John", "Doe");
    Student John2(123,"John", "Doe");
    Student Jane(456,"Jane","Doe");
std::cout<<"Made some people"<<std::endl;

    std::cout 
    << (John == John2)
    << std::endl; 
std::cout<<"Compared some people"<<std::endl;
*/ 
//roster 1
 // bag1.add(John);
 // bag1.add(Jane);
//std::cout<<"Added some people to roster one"<<std::endl;

//roster 2
  //bag2.add(John2);
//std::cout<<"Added some people to roster two"<<std::endl;

/*
   bag1 += bag2;
std::cout<<"Set union: roster one and roster two"<<std::endl;



std::cout<<"Print bag one:"<<std::endl;
   bag1.display(); 

   
std::cout<<"Print bag two:"<<std::endl;
   bag2.display(); 
*/

/*
 bag1 -= bag2;

 std::cout<<"Print bag one:"<<std::endl;
   bag1.display(); 

   
std::cout<<"Print bag two:"<<std::endl;
   bag2.display(); 

*/ 

/*
  Roster r1("data.csv");
  r1.display(); 
*/
    //   Roster r1("data.csv");



   ArrayBag<int> bag1;
   ArrayBag<int> bag2; 

   bag1.add(1);
   bag1.add(2);
   bag1.add(3);

   bag1.display();  
return 0;

}

