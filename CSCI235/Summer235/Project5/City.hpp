//Imran Sabur
//CSCI 235
//Project 5
//Professor Ligorio
//July8, 2019


//This is the header file of the city class

#ifndef City_hpp
#define City_hpp
#include <string> 
#include <vector>


class City
{
 public:

    //default constructor initializes visit to false
    City();
    

    //@param constructor that takes in the name of the city
    City(std::string name); 
    

    /* @returns city_name */
    std::string getCityName() const;

    //checks if the city was added 
    bool isVisited();

    //sets visited to true 
    bool Visit();

    //returns the adjacent of the city that has been unvisited
    City* get_Unvisited_Adjacent(); 

 /*
    returns true if adjacent city was added 
    takes in a city pointer as parameter
*/    
bool addAdjacent(City* city); 

 protected:
     
    std::string city_name; //the city's name 

    std::vector<City*> adj_city; //vector of type City pointers that has  adjacent cities

    bool visited; //boolean visited value

    
}; 
#endif 
/* City_hpp */ 
