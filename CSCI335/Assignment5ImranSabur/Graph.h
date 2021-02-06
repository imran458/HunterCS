/*
	- Imran Sabur
	- December 11,2019
	- This Graph class was made in part for Assignment 5 of Professor Stamos's CSCI 335 class.
	- Graph class which allows Dijkstra and Topological sort to be computed via the given files.
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;
#include "AdjacentVertex.h"
#include "Vertex.h"
#include <limits>
#include <vector> 
#include <queue> 



class Graph
{
private:
    void getroute (Vertex * a_vertex)
	{
		if (a_vertex -> route !=  nullptr)
		{
			getroute( a_vertex -> route); //recursively get the shorestest path 
		}
		cout << a_vertex -> vertex_count << " "; //print out that vertex
	}
    vector<Vertex*> vertices; //will store the vertex read from graph
    /*
    void RemoveVertices(){
        for(vector<Vertex*>::iterator it = vertices.begin(); it != vertices.end(); it++) {
            delete it; //lol 
        }
    }
    */  

   /*
		void Graph::TopologicalSort() {
				Queue<Vertex>	q;
				int	counter	= 0;
				for	each Vertex	v	
					if	(v.indegree_	== 0) q.enqueue(v);
			
				while	(!q.isEmpty()) {
				Vertex	v	= q.dequeue();
				v.top_num_	= ++counter;
	 	
		for	each Vertex	w adjacent to	v	
	 		if	(--w.indegree_	== 0) 
			 	q.enqueue(w);

	if	(counter	!=	num_vertices_)
		throw CycleFoundException()

		 I made topological sort via this psuedocode provided by Professor Stamos
		 in the lecture.
	*/
   void TopoLogicalSortHelper(){
		queue<Vertex*> my_queue; //a queue
		int counter = 0; 

		//cout << "This is the size: " << vertices.size() << endl;


		for(int i = 1; i < vertices.size();i++){
			if(vertices[i]->indegree == 0){
				my_queue.push(vertices[i]);
			}
		}

		while(!my_queue.empty()){
			Vertex* a_vertex = my_queue.front();
			cout << a_vertex ->vertex_count << ","; 
			my_queue.pop();
			a_vertex->initial_num = ++counter;

			//cout << vertices.size() << " " << endl;
			for(int j = 0; j < a_vertex->adjacency_list.size();j++){
				Vertex * some = vertices[a_vertex->adjacency_list[j].vertex]; //for each vertex adjacent to the vertex 
				some -> indegree--; //decrease indegree
				

				if(some ->indegree == 0){
					my_queue.push(some); //enqueue it
				} //end if

			
			}//end for 
		}//end while

		if(my_queue.empty()){
			cout << "."; 
		}
		int num_vertices = vertices.size() - 1; 

		//cout << num_vertices << endl; 
		//cout << counter << endl; 
		if(counter != num_vertices){
			cout << "Cycle Found" << endl; //error message there is	no vertex with indegree zero in the graph.
			//return; 
		}else{
			cout << endl; 
		}


	}//end topological sort  

	//updates the indegree
	void Indigree(){
		for(int i  = 1; i < vertices.size(); i++){
			for(int k = 0; k < vertices[i] ->adjacency_list.size(); k++){
				
				int adj = vertices[i]->adjacency_list[k].vertex;//get the adjacent vertex
				vertices[adj] -> indegree++; //update indegree
			}
		}
	}

public:
    Graph(){}


    /* 
        Helper function that comes in handy to add the adjacent vertex to the adjacency list vector
        also factors in the cost
    */
    void addToAdjaceny(const int& a_vertex, const int& an_adjacent_vertex, const float& cost){
        AdjacentPoint adj_object(an_adjacent_vertex,cost);
        vertices[a_vertex] -> adjacency_list.push_back(adj_object); //a vertex now points to an adjacent vertex
    }

	/*
		- This is a constructor that takes the number of vertices of the graph after being
		read from a file as a parameter.
		- This allows us to create a graph with n vertices
		- We pass the integer by reference here because it changes depending on 
		the input. 

	*/
    Graph(const int & num_of_vertices) : vertices (num_of_vertices + 1)
	{
		size_t inf = std::numeric_limits<int>::max(); //help from tutoring 
		for (int i = 1; i < num_of_vertices + 1; i++)
		{
			vertices[i] = new Vertex (i, false, inf, 0, 0, nullptr); //instantiate the vertex constructor 
		}
	} 

/*
	- I overloaded a comparison operator to see if the input vertex's distance was 
		greater than it's adjacent vertex
*/
struct CompareVertices
{
	bool operator() (const Vertex * a_vertex, const Vertex * adjacent_vertex) const
	{
		return a_vertex -> distance > adjacent_vertex -> distance;
	}
};// end comparator


	//public function which will be called by the graph	
	void TopoLogicalSort(){
		
		Indigree(); 
		TopoLogicalSortHelper();

	}//end topological sort

    void Is_Adjacent(const int & a_vertex, const int & adjacent_vertex)
	{
		bool isAdjacent = false;
		for (int i = 0; i < vertices[a_vertex] -> adjacency_list.size(); i++)
		{
			if (vertices[a_vertex] -> adjacency_list[i].vertex == adjacent_vertex)
			{
				isAdjacent = true;
				cout << a_vertex <<" "<< adjacent_vertex <<": Connected, weight of edge is " << vertices[a_vertex] -> adjacency_list[i].cost << endl;
			    	break;
			}
		}
		if (!isAdjacent) //if the vertex is not adjacent to the adjacent vertex then print the following message 
			cout << a_vertex <<" "<< adjacent_vertex <<": Not Connected " << endl;
	}

	/*
		1) Initialize distances of all vertices as infinite.

		2) Create an empty priority_queue pq.  Every item
   		of pq is a pair (weight, vertex). Weight (or 
   		distance) is used used as first item  of pair
   		as first item is by default used to compare
   		two pairs

		3) Insert source vertex into pq and make its
   			distance as 0.

	4) While either pq doesn't become empty
    	a) Extract minimum distance vertex from pq. 
       Let the extracted vertex be u.
    	b) Loop through all adjacent of u and do 
       	following for every vertex v.

           // If there is a shorter path to v
           // through u. 
           	If dist[v] > dist[u] + weight(u, v)

               	(i) Update distance of v, i.e., do
                     dist[v] = dist[u] + weight(u, v)
               (ii) Insert v into the pq (Even if v is
                    already there)
               
		5) Print distance array dist[] to print all shortest
   		paths.
		
		Please note that this psuedocode ^^^ was copy and pasted from this following link https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/

		While my actual approach is different, I was able to recieve alot of guidance via this psuedocode. 

		
	*/

    void Dijkstra(const int & v)
	{
		vertices[v] -> distance = 0;
		priority_queue <Vertex*, vector<Vertex*>, CompareVertices> my_queue; //declare the queue
		my_queue.push(vertices[v]);//push the vertices in the queue 

		while (!(my_queue.empty()))
		{
			Vertex * a_vertex = my_queue.top();
			my_queue.pop();
			a_vertex -> flag = true;

			//for each element in my adjacency list
			for (int i = 0; i < a_vertex -> adjacency_list.size(); i++)
			{
				//setlook at each vertex
				int vertice = a_vertex -> adjacency_list[i].vertex;
				Vertex * unknown_v = vertices[vertice];
				if (!unknown_v -> flag) //if i haven't seen it or if there is a shorter path
				{
					float cost_ = a_vertex -> adjacency_list[i].cost; //find the weight of vertex
					//if the distance between the current vertex and th
					if (a_vertex -> distance + cost_ < unknown_v -> distance)
					{ 
						unknown_v -> distance = a_vertex -> distance + cost_; //update distance, which will be equal to the vertix's distance + cost
						unknown_v -> route = a_vertex;
					}
					my_queue.push (unknown_v);//enqueue that vertex 
				}
			}
		}

		float max_path = std::numeric_limits<int>::max(); //maximum path allowed 
		for (int i = 1; i < vertices.size(); i++)
		{
			cout << vertices[i] -> vertex_count <<": ";
			double shortest_path_cost = vertices[i] -> distance;
			getroute(vertices[i]);//call the private function here
			if (shortest_path_cost != max_path)
				cout << "(Cost: " << shortest_path_cost << ")" << endl; //get the cost
			else
				cout << "(No path)" << endl;   //there is no such path between the input
		}
		
	}


    ~Graph(){}
};

#endif