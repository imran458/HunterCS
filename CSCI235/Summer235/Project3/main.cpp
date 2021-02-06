#include <iostream>
#include "Student.hpp"
#include "Instructor.hpp"
#include "TeachingAssistant.hpp"
#include "Person.hpp"
#include "Roster.hpp"

int main() 
{
    
    Student* Imran = new Student(12,"Imran","Sabur");
    Instructor* Tiziana = new Instructor(1212, "Tizana","Ligorio");
    TeachingAssistant* Owen = new TeachingAssistant(46465,"Owen","Kunhardt");

    Imran->setGpa(3.0);
    Imran->setMajor("computer science"); 

    Tiziana->setOffice("1000C");
    Tiziana->setContact("235Instructors@hunter.cuny.edu");

    Owen->setMajor("computer science"); 
    Owen->setGpa(3.5);
    Owen->setHours(9);
    Owen->setRole(LAB_ASSISTANT); 

    Imran->display();
    Tiziana->display(); 
    Owen->display(); 

    delete Imran;
    delete Tiziana;
    delete Owen; 

 
   /* 
   Roster r1("data_full.csv");
   r1.display();
   */
    


}

