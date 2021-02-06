/*
 - Vertex class made by Imran Sabur
  - CSCI 335
  - Assignment 5 Professor  Stamos
*/


#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
using namespace std;
#include <vector>
#include "AdjacentVertex.h"

class Vertex{

public: 
    Vertex(const int& vertex_count_,const bool& f, const float& distance_, const int indegree_, const int init_num,Vertex* route_){
        vertex_count = vertex_count_;
        flag = f;
        distance = distance_;
        initial_num = init_num;
        indegree = indegree_; 
        route = route_; 
    }

    int vertex_count;
    Vertex* route;
    float distance; 
    int indegree;
    int initial_num; 
    bool flag; 
    vector<AdjacentPoint> adjacency_list; //vector of adjacent vertices

  

    
};

#endif