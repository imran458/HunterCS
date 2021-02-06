#include "WordLadder.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <string> 

int main()
{
    
    WordLadder m; 

    m.readLexicon("4LetterWordsReduced.dat");


    std::vector<std::string> test_vec = m.findShortestLadder("code", "data");
    for(int i =0; i < test_vec.size();i++)
    {
        std::cout << test_vec[i] << std::endl; 
    }
    
    


    
}


