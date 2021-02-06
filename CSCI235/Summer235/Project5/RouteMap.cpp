`//Imran Sabur
//Project 5
//This is an implementation of the RouteMap class
//July 8,2019

#include <iostream>
#include "RouteMap.hpp" 
#include "City.hpp"
#include <string>
#include <stack>
#include <fstream>
#include <sstream>
#include <vector> 


RouteMap::RouteMap(){}

bool RouteMap::readMap(std::string input_file_name)
{
    std::ifstream csv_file(input_file_name); //ifstream object to open the input file
     


    if(!csv_file.is_open())
    {
        std::cout << "Could not read the file: " << std::endl; //conditinal 
        return false;
    }else
    {   
        std::string csv_line; 
        std::string city_; 
        std::string adjCity_;

        getline(csv_file,csv_line);
        std::stringstream ss(csv_line);

        while(getline(ss,csv_line,','))
        {
            City* c = new City(csv_line); //new dynamically allocated city
            cities_.push_back(c); //push those cities in a vector

        }

        getline(csv_file,csv_line); //getline again to read 2nd line
        std::stringstream s1(csv_line); //string stream object

        City *c; //new dynamically allocated object of city
        City* d; 
        while(getline(s1,csv_line,'-')) //stops at the hyphen 
        {
            getline(s1,adjCity_,','); //stops at the comma

            for(int j = 0; j < cities_.size(); j++) //for each element in the city
            {
                if(cities_[j]->getCityName() == csv_line) //if the city in the vector is the city in the csv file
                {

                    c = cities_[j]; //dynamically object equals that city
                    for(int k = 0; k < cities_.size(); k++) 
                    {
                        if(cities_[k]->getCityName() == adjCity_) //if that element which appears after hyphen is the adjacent city
                        {
                            
                            d = cities_[k]; //set the dynamically pointed object of city to that element
                            c->addAdjacent(d); //add it to the adjacent cities vector
                            
                        }
                        
                    
                    }
                
                    
                    
                }
            }



        }

        
    

    }


   /*

    for(int i = 0; i < cities_.size();i++)
    {
        std::cout << cities_[i]->getCityName() << std::endl; 
        
    }
    
    */
    

    

    //in_stream.close(); 
    return true; 

}

 
bool RouteMap::isRoute(City* origin, City* destination)
{
    std::stack<City*> my_stack; //stack of city pointers
    my_stack.push(origin); //push the origin
    origin->Visit(); //mark origin as visited

    City* temp_city; //temporary city used for comparison
    std::stack<City*> stack2; //new stack to copy elements of the first stack and print cities
    
    
    while(origin != destination && !my_stack.empty())//while the stack is not empty and the cities are not equal
    {
        temp_city = my_stack.top()->get_Unvisited_Adjacent(); //temp_city will be the top of the stack

        if(temp_city == nullptr){
            my_stack.pop(); //if there are no unvisited adjacents then u pop the stack
        }
        else{
            origin = temp_city; //origin will be the temp_city
            my_stack.push(origin); //push the city into the the stack
            origin->Visit(); //mark the city as visited

            
        }
    }

        //if the the origin and destination are the same
        if(origin->getCityName() == destination->getCityName()){
        while(!my_stack.empty()){
        stack2.push(my_stack.top()); //push the contents of the first stack onto the the second stack
        my_stack.pop();//pop that stack
        }

        while(!stack2.empty()){
        if(stack2.size() == 1){
            std::cout << stack2.top()->getCityName() << std::endl; //if I have reached the last city, print it
            stack2.pop(); //pop the stack
        }else{
            std::cout << stack2.top()->getCityName() << " -> "; //print city name and "->" next city
            stack2.pop(); //pop the stack
        }
         
        }  
            
        
        return true; //return true within while loop
    }
        
        

        
        
    return false; 
}    

    


City* RouteMap::getCity(size_t position) 
{
    if(position >= 0 && position < cities_.size()){ //if the position is greater than or equal to 0 or less than the size of the vector
        return cities_[position]; //return the vector at that position

    }else{
        return nullptr; //else return nullptr
    }


}






 
