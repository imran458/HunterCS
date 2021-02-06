#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include "City.hpp"
#include "RouteMap.hpp"

int main()
{
    
    RouteMap r; 
    r.readMap("sample_map.csv");
    r.isRoute(r.getCity(1),r.getCity(5));
   
    


    /* 
    std::string city_;
    std::fstream in_stream("sample_map.csv");
    std::vector<City> cities;
    std::vector<City> adjacent; 

    while(!in_stream.eof() && std::getline(in_stream ,city_, ','))
    {
        adjacent.push_back(city_.substr(city_.find("-") + 1));
        cities.push_back(city_); 
        
    }
    
    for(int i = 0; i < cities.size();i++)
    {
        std::cout << cities[i].getCityName() << std::endl; 
    }

    for(int j = 0; adjacent.size();j++)
    {
        std::cout << adjacent[j].getCityName() << std::endl;
        
    }
    */
}


