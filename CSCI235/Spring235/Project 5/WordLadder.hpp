//Imran Sabur
//Project 5
//Headerfile of wordladder

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

    std::vector<string> findShortestLadder(std::string start_word, std::string end_word);    


    private: 


    //private functions


}; //end WordLadder

#endif 



