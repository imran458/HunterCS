//Imran Sabur
//This is the header file of wordladder
//CSCI 235
//July 2, 2019

#ifndef WordLadder_hpp
#define WordLadder_hpp
#include <iostream>
#include <vector>
#include <string>

class WordLadder
{
    public:

    /**
    @post reads lexicon words from the input file and stores them for
    later use
    **/
    void readLexicon(std::string input_file);

    /**
    @param start_word is the first word in the ladder
    @param end_word is the last word in the ladder
    @return a vector containing words s.t. the first word is start_word,
    the last word is end_word, and all words in between differ by
    only one character from the preceding and following words, in
    the shortest such transformation found in the current lexicon.
    If no transformation is found between start_word and end_word,
    returns an empty vector.
    **/

    //used words vector for the helper function


    //this is a helper function to test if we've used word
    bool NotUsed(std::string input_word);
    

    std::vector<std::string> findShortestLadder(std::string start_word, std::string end_word);
    
    std::vector<std::string> lexicon;    //vector of all words
    std::vector<std::string> empty_ladder;  // empty ladder that i return
    std::vector<std::string> used_word;
   // std::vector<std::string> lexicon;
    //private functions


}; //end WordLadder

#endif 



