//Imran Sabur
//Project 4
//This is an implementation of the RouteMap class

#include "City.hpp" 
#include <iostream>
#include "RouteMap.hpp" 
#include <string>
#include <stack>
#include <fstream>
#include <vector> 


bool RouteMap::isAdj(City * c, City* p)
{
    bool adjacent = false;
    cities_ =  c; 
    for(int i = 0; i < cities_.size();i++)
    {
        isAdj[]
    }
}

bool RouteMap::readMap(std::string input_file_name)
{
    std::fstream in_stream(input_file_name); 
    std::string city_; 
    std::string adjCity_; 

    std::vector<City> cities; 
    std::vector<City> adjacent; 

    if(!in_stream.is_open())
    {
        std::cout << "Could not read the file: " << std::endl;

        return false; 
    }
   while(!in_stream.eof() && std::getline(in_stream ,city_, ','))
    {
        
        
        
        for(int i city_.length() - 1; i >= 0; i--)

        {
            if (city_.find('-') >= 0 && city_.find('-') <= city_.length()) 
            {
                adjacent.push_back(city_)
            }
             
        } 
        
        else 
        {
            cities.push_back(city_)
        }
    }
    
    

    //in_stream.close(); 
    //return true; 

}


bool RouteMap::isRoute(City* origin, City* destination)
{
    if(origin == destination)
    {
        //cout cities 
    }
}

City* RouteMap::getCity(size_t position) 
{

}




 