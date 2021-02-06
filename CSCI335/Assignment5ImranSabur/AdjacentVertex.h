//Imran Sabur
//CSCI 335
//Project 5
//Professor Stamos

#ifndef ADJACENT_POINT_H
#define ADJACENT_POINT_H

#include <iostream>
using namespace std;


/*
    This Class is made by Imran Sabur. 
    It contains a vertex to be read by the file and a cost
    Furthermore it contains a constructor to initialize these variables
*/ 

class AdjacentPoint{

public: 
    int vertex;
    float cost; 

    //Two parameterized constructor which takes in the vertex and the cost of it via the formatted file
    AdjacentPoint(const int &vertex_, const float &cost_):vertex{vertex_},cost{cost_}{}
};

#endif

//end AdjacentPoint
