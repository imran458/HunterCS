#include <iostream>
#include <string>
#include "Person.hpp" 
#include "Student.hpp"

int main()
{
    Student Samuel(232323, "Samuel","Chang");
    Samuel.setGpa(3.0);


    std::cout << Samuel.getFirstName() << std::endl;
    std:: cout << Samuel.getGpa() << std::endl;  

    
}
