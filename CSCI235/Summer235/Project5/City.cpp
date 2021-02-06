//Imran Sabur
//CSCI 235
//Project 5
//7/8/2019

//This is the implementation of the city class

#include <string>
#include "City.hpp"
#include "RouteMap.hpp"

City::City()
{
    visited = false; //initialize value to false
}

bool City::Visit()
{
    return visited = true; //sets city to true if it has been visited
}

bool City::isVisited()
{
    return visited;  
}

City::City(std::string name)
{
    city_name = name; 
}



std::string City::getCityName() const
{
    return city_name; //returns the name of  the city
}

//adds a pointer of the adjacent city to the adjacent city vector
bool City::addAdjacent(City* city)
{
    adj_city.push_back(city); //push the city the adjacent cities vector
    return true;//
}

City* City::get_Unvisited_Adjacent()
{
    City* c; 
    for(int i =0;i < adj_city.size();i++) //for each element in the adjacent cities
    {
         c = adj_city[i]; //set the dynamically allocated object to each value in the vector
        if(!c->isVisited()) //if it has not been visited return it
        {
            return c;
        }
    }

    //c->getCityName();
    return nullptr; //return nullptr otherwise
}