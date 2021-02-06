//Imran Sabur
//CSCI 235
//Project 4
//Professor Ligorio


//This is the header file of the city class

#ifndef City_hpp
#define City_hpp
#include <string> 

class City
{
    public:

    

    

    City();
    //default constructor

    City(std::string name); 
    //constructor

    /** @returns city_name */
    std::string getCityName() const;

     


    private:

    std::string city_name; //the city's name 

    
};

#endif /* City_hpp */ 
