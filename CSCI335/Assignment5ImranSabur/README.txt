Author: Imran Sabur
CSCI 335
Assignment 5 Graph 
December 12, 2019 

All parts of this assignment are completed. 
Graph DONE
Dijkstra DONE
Topological DONE

There are no known bugs except for 1. When running dijkstra algorithm on Graph2.txt, 
my program prints 

1: 1 (Cost: 0)
2: 1 2 (Cost: 2)
3: 1 4 3 (Cost: 3)
4: 1 4 (Cost: 1)
5: 1 4 5 (Cost: 3)
6: 1 4 7 6 (Cost: 6)
7: 1 4 7 (Cost: 5)

However, the expected result should be:

1: 1 (Cost: 0)
2: 1 2 (Cost: 2.0)  //my program does not print the additional .0
3: 1 4 3 (Cost: 3.0 ) //not the additional .0 
4: 1 4 (Cost: 1)
5: 1 4 5 (Cost: 3)
6: 1 4 7 6 (Cost: 6)
7: 1 4 7 (Cost: 5)

Dijkstra's algorithm works perfectly but the cost of the second and third vertex is missing a .0.
I think that this is due to a precision error which occurs due to stringstream's disregard
for the last digit, as it is only a .0 so ss disregards it. 

To run the program please download the folder and type:

Part 1:

make clean
make all 
./CreateGraphAndTest Graph1.txt	AdjacencyQueries1.txt

Dijkstra algorithm:

make clean 
make all 
./FindPaths Graph2.txt	1

Topological Sort:

(not vertex	with indegree zero in the graph)
make clean
make all 
./TopologicalSort Graph2.txt

make clean
make all 
./TopologicalSort Graph3.txt


Your Output will be:

Imrans-MacBook-Pro:Assignment5ImranSabur imran$ ./CreateGraphAndTest Graph1.txt AdjacencyQueries1.txt
Verify Adjacency: 
4 1: Not Connected 
3 4: Connected, weight of edge is 50.2
1 5: Connected, weight of edge is 0.5
5 1: Not Connected 
1 3: Not Connected 
Imrans-MacBook-Pro:Assignment5ImranSabur imran$ ./FindPaths Graph2.txt 1
Performing Dijkstra:  
1: 1 (Cost: 0)
2: 1 2 (Cost: 2)
3: 1 4 3 (Cost: 3)
4: 1 4 (Cost: 1)
5: 1 4 5 (Cost: 3)
6: 1 4 7 6 (Cost: 6)
7: 1 4 7 (Cost: 5)
Imrans-MacBook-Pro:Assignment5ImranSabur imran$ ./TopologicalSort Graph2.txt
Performing Topological Sort 
.Cycle Found
Imrans-MacBook-Pro:Assignment5ImranSabur imran$ ./TopologicalSort Graph3.txt
Performing Topological Sort 
1,2,5,4,3,7,6,.
