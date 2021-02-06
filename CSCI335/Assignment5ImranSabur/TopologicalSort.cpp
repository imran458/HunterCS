#include <iostream>
using namespace std; 
#include <string>
#include <sstream> 
#include  <fstream> 
#include "Graph.h"

int main(int argc, char **argv){
    if (argc != 2)
	{
		cout << "Usage: " << argv[0] <<" <GRAPH_FILE>"  << endl; 
		return 0;
	}
	const string graph_file (argv[1]);//this is the string that will be inputted via the command line 
	

	ifstream inputted_graph_file(graph_file);
	string graph_line; 
	int number_of_vertices; 
	inputted_graph_file >> number_of_vertices;
	Graph new_graph (number_of_vertices);//this calls the one parameter constructor which instantiates the graph with n vertices
	
	cout << "Performing Topological Sort " << endl;
	int vertex; 
	int adjacent_vertex;
	float cost; //cost has a decimal so it is a float
	while (getline(inputted_graph_file, graph_line))//get each graph line
	{
		stringstream ss(graph_line); //a string stream object to go through and get the adjacent and cost
		ss>> vertex; //get the vertexes to output
		while (ss >> adjacent_vertex && ss>> cost) //gets the adjacent vertex and gets the cost
		{	
			new_graph.addToAdjaceny(vertex, adjacent_vertex, cost); //adds to the adjacency graph
		}

        
	}
    new_graph.TopoLogicalSort(); //call the public topological sort function which accounts for the indigree
}