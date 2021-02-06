// Imran Sabur
//November 5, 2019
/*
  This program makes a spell checker via hash table. Using the hash functions provided,
  I chose the linear table to construct the hashtable, store dictionary words in it, and 
  then compare in order to find corrections. I have implemented all three case: one to add a character
  in the designated positions,swap the characters, and remove if needed.
*/


#include "linear_probing.h"
#include "double_hash.h"
#include "quadratic_probing.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


template <typename HashTableType>
void Hash_Spell_Check(const string &doc_filename, const string &dictionary_filename,HashTableType &linear_table) {


  ifstream doc_file;
  doc_file.open(doc_filename);//opens the document file
  
  //open the dictionary 
  ifstream dictionary_file;
  dictionary_file.open(dictionary_filename);
  
  string dictionary_word; 
  while(getline(dictionary_file, dictionary_word)) {
    linear_table.Insert(dictionary_word); //insert into table
  }

  //string of alphabets used to append into the first conditions 
  vector<string> alphabets = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

  bool flag = false; // a flag to tell to stop looping when it sees non-alphabetical characters

  
  while(doc_file >> dictionary_word) {

    string doc_word = ""; //variable used to store word in the document we are parsing through
    for(char letter: dictionary_word){ //check each element of the word

      if(letter == '\''){ //skip it if you see an apostraphe
        flag = true;
      }
      else if(isalpha(letter)){ //check if it's alphanumeric and then convert to lowercase
        doc_word += tolower(letter);
      }
    }

   
   string final_word = doc_word; //variable in which the final word to be corrected will be stored and displayed
   if (!flag && !linear_table.Contains(final_word)) {

        
        //for each letter in the alphabet
          for(string l:alphabets){
            for(int j =0; j < doc_word.length(); ++j){ //loop through words
              final_word.insert(j,l); //insert where needed
              //if this word is in my hash table, print it
              if(linear_table.Contains(final_word)) {
                    cout << doc_word << " -> " << final_word <<  " (Error A)" <<  endl;
                }
               final_word = doc_word; 
            }
          }//end Case A
        
       final_word = doc_word;
       for(int i = 0; i < doc_word.length(); ++i){

         //removes every letter one by one in word
         //prints the word if it's in our hashtable
         
          final_word = doc_word.substr(0,i) + doc_word.substr(i+1);
            if(linear_table.Contains(final_word)) {
                    cout << doc_word << " -> " << final_word << " (Error B)" << endl;
            }
            final_word = doc_word; 

        }//end case B
       //swaps the adjacent letter, searches for it in the hash table
       for(int i = 0; i < doc_word.length() != 0 && i < doc_word.length() - 1; i++) { //check for i == 0
            swap(final_word[i], final_word[i+1]); //swap the letters

            if(linear_table.Contains(final_word)) { //check 
                    cout << doc_word<< " -> " << final_word <<  " (Error C)" << endl;
            }
            final_word = doc_word; 

       }//end end Case C
    } // end if
    flag = false;

  } 
  
}

// Sample main for program spell_check
int main(int argc, char **argv) {
  if (argc != 3) {
    cout << "Usage: " << argv[0] << " <document-file> <dictionary-file>" << endl;
    return 0;
  }
  
  const string document_filename(argv[1]);
  const string dictionary_filename(argv[2]);
  
  cout << "Input document filename is " << document_filename << endl;
  cout << "Input dictionary filename is " << dictionary_filename << endl;

  // Call functions implementing the assignment requirements.

 LinearProb<string> linear_probing_table;
  Hash_Spell_Check( document_filename, dictionary_filename,linear_probing_table);
 

  return 0;
}
