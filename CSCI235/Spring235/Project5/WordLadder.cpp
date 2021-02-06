//Imran Sabur
//This is the implementation file of wordladder. It takes 2 words and finds the shortest path between them.
//CSCI 235
//July 2, 2019




#include "WordLadder.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <string> 
#include <algorithm> 



void WordLadder::readLexicon(std::string input_file)
{
    std::fstream in_stream(input_file);
    std::string line_; 

    if(!in_stream.is_open())
    {
        std::cout << "Could not read file" << std::endl;

    }

    while(std::getline(in_stream, line_))
    {
        lexicon.push_back(line_);
    }

    /*for(int i = 0; i < lexicon.size();i++)
    {
        std::cout << lexicon[i] << std::endl; 
    }
    */ 
}

//Helper function 
bool WordLadder::NotUsed(std::string input_name)
{
    
    if(used_word.size() == 0)
    {
        return true;

    }else
    {
        for(int i = 0; i < used_word.size();i++)
        {
            
            if(used_word[i] == input_name)
            {
                return false; 
            }
            
        }
            
        return true;

    }
    
}

std::vector<std::string> WordLadder::findShortestLadder(std::string start_word, std::string end_word)
{
     

    std::vector<std::string> partial_ladder; //new vector to store partial ladders

    partial_ladder.push_back(start_word); //push the start

    std::queue<std::vector<std::string> > myQ; //a queue of vector strings
    myQ.push(partial_ladder); // push that ladder onto the queue 

    std::vector<std::string> temp_vec2;

    if(start_word.length() != 4 || end_word.length() != 4) //if the end word or start word is not 4 letters 
    {
        return empty_ladder;
    }
    while(!myQ.empty())
    {
        std::vector<std::string> temp_vec;
        temp_vec = myQ.front();
        myQ.pop(); //dequeueing 
        std::string word = temp_vec.back();

        if(word == end_word) //if the word which was popped is the end word 
        {
            return temp_vec; //return that vector 
        }
        for(int j = 0; j < word.size(); j++) //for each for letter in the word
        {
        
            
            for(char c = 'a'; c <= 'z'; c++)
            {
                word[j] = c;
                //std::cout << word << std::endl;
                if(binary_search(lexicon.begin(),lexicon.end(),word) && NotUsed(word))
                {
                    temp_vec2 = temp_vec; //copy vector
                    temp_vec2.push_back(word);//push that copy vector 
                    myQ.push(temp_vec2); // push that into the queue 
                    used_word.push_back(word); //push it back to the used words vector
                    //append to a copy of temp vec
                    //enque that vector
                    //std::cout << word << std::endl;

                }
                word = temp_vec.back();
            }

            
            
        }
    }//end while

    //std::cout << "left while" << std::endl;
    return empty_ladder; //empty ladder


}


