/*
	-Imran Sabur
	- December 11, 2019
	- 
*/

#include <iostream>
using namespace std; 
#include <string>
#include <sstream> 
#include  <fstream> 
#include "Graph.h"

int main(int argc, char **argv){
    if (argc != 3)
	{
		cout << "Usage: " << argv[0] <<" <GRAPH_FILE> <STARTING_VERTEX>" << endl;
		return 0;
	}
	const string create_graph_file (argv[1]);
	int vertex_from_cmdline = atoi(argv[2]); //command line input

	ifstream input_file (create_graph_file);
	string line; 
	int n; //amount of vertices 
	input_file >> n; //store the first thing read by the file as that is the graph size
	Graph new_graph (n);//object of graph class with total number of vertices as a parameter
	
	cout << "Performing Dijkstra:  " << endl;
	int vertex;
	int adjacent_vertex;
	float cost;
	while (getline(input_file, line)) //reading each line from the input file
	{
		stringstream ss(line); //a string stream object used to parse vertex, cost and adjacent vertex
		ss >> vertex;//get the first item, or the vertex
		while (ss >> adjacent_vertex && ss >> cost)
		{	
			new_graph.addToAdjaceny(vertex, adjacent_vertex, cost); //add the vertex, the adjacent vertex and the cost to  the adjacency list
		}
	}

	new_graph.Dijkstra(vertex_from_cmdline); //call the dijkstra function with that number as a function paramater
}