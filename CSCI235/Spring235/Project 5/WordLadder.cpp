#include "WordLadder.hpp"
#include <iostream>
#include <vector>
#include <fstream>


/*
void WordLadder::readLexicon(std::string input_file)
{
    std::fstream in_stream("4LetterWordsReduced.dat"); //open the file
    std::string line_;
    std::vector<std::string> word_list; //vector of words

    if(!in_stream.is_open())
    {
        std::cout << "Could not read file" << std::endl; //conditional if you can't open file

    }

    while(std::getline(in_stream, line_))
    {
        word_list.push_back(line_)
    }

}
