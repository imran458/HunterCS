/*
	- Imran Sabur
	- CSCI 335; 
	- Assignment 5 
	- This is testing method to read the vertices from the file, make a graph of that length and display 
	  if it is connected, report  the  weight. 
*/ 

#include <iostream>
using namespace std; 
#include <string>
#include <sstream> 
#include  <fstream> 
#include "Graph.h"
#include "AdjacentVertex.h"
#include "Vertex.h"

int main(int argc, char **argv){


    

    if (argc != 3)
	{
		cout << "Usage: " << argv[0] <<" <GRAPH_FILE> <ADJACENCY_QUERY_FILE>" << endl;
		return 0;
	}
	const string graph_file (argv[1]);
	const string adjacency_query_file (argv[2]);

	ifstream input_file (graph_file);
	string line; 
	int n; 
	input_file >> n; //gets the number of vertices which the first thing in the file
	Graph new_graph (n); //this calls the one parameter constructor which instantiates the graph with n vertices

	int vertex;
	int adjacent_vertex;
	double cost;
	while (getline(input_file, line)) //read each file of the graph.txt 
	{
		stringstream ss(line); //a string stream object to go through and get the adjacent and cost
		ss >> vertex;//get the vertexes to output
		while (ss >> adjacent_vertex && ss >> cost)
		{	
			new_graph.addToAdjaceny(vertex, adjacent_vertex, cost); //add to the vectors
		}
	}
   
    
    string query_line;
    string vertex_of_file;
    string adjacent_of; 
	ifstream query(adjacency_query_file); //open the query file
	cout << "Verify Adjacency: " << endl;
    
    while(getline(query, query_line)) //loop through each line of query file
	{
             
		stringstream ss1(query_line);
		getline(ss1, vertex_of_file, ' '); //stop till you reach the first space as that will be vertex
        getline(ss1, adjacent_of,' '); //stop until you reach the second space, that will signify the adjacent vertex

		int var1 = stoi(vertex_of_file); //convert the first string variable to and int as that is vertex
        int var2 = stoi(adjacent_of); 	//convert second string variable to an int because that is the adjacent vertex
            
		new_graph.Is_Adjacent(var1, var2);//check adjaceny and output as follows
        
		
	}

	return 0;
}