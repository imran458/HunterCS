//Imran Sabur
//CSCI 235

//This is the implementation of the city class

#include <string>
#include "City.hpp"

City::City()
{}


City::City(std::string name)
{
    city_name = name; 
}



std::string City::getCityName() const
{
    return city_name; 
}