// Imran Sabur
//Nov 5, 2019
/*
  Imran added the following functions:
  insert_to_hash(); //adds words to hashtable
  query_helper(); // looks for words and reports how many probes it found them in

*/

#include "quadratic_probing.h"
#include "linear_probing.h"
#include "double_hash.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


//helper function of query_helper
//I decided to add this function in order to keep things nice and clear
//it simply iterates through the file and puts words in the hashtable
template <typename HashTableType>
void insert_to_hash(HashTableType &a_table, const string& file_name){

  ifstream word_file(file_name);
  string word = " "; 
 
 //for each line in the file, store it in a var called word and then insert it
  while(getline(word_file,word)){
    a_table.Insert(word); 
  }

 // cout << word << endl; 

}

//helper function of testfunctionforhash
//looks for words and reports how many probes it found them in
template <typename HashTableType>
void query_helper(HashTableType& some_table, const string& query_file){

  ifstream query(query_file);
  string w = " "; 
  cout << '\n'; 

  while(getline(query,w)){
    if(some_table.locate(w)){ //looks for word in table, reports in how many probes in found it
      cout << w << ": Found in " << some_table.get_probes() << " probes" << endl; 

    }else{
      cout << w << ": Not found in " << some_table.get_probes() << " probes" << endl; 
    }
  }//end while
}//end query helper


template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  cout << "------>" << endl; 


  cout << "TestFunctionForHashTables..." << endl;
  cout << "Words filename: " << words_filename << endl;
  cout << "Query filename: " << query_filename << endl;
  hash_table.MakeEmpty();  

  //insert to hash in order to report calculations
 insert_to_hash(hash_table,words_filename);
 

  //..Insert your own code

  cout << "Collisions: " << hash_table.get_collisions() << endl; //report collisions
  cout << "Number of items: " << hash_table.get_num_items() << endl; //gets the items
  cout << "Size of hash table: " << hash_table.get_size() << endl; //gets the size
  cout << "Load factor: " << hash_table.get_num_items()/(double)hash_table.get_size()<< endl; //reports load factor
  cout << "Avg. number of collisions: " << hash_table.get_collisions()/(double)hash_table.get_num_items()<< endl; // reports collisions

  //call helper
  query_helper(hash_table,query_filename);


}

// Sample main for program create_and_test_hash
int main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << " <wordsfilename> <queryfilename> <flag>" << endl;
    return 0;
  }
  
  
  const string words_filename(argv[1]);
  const string query_filename(argv[2]);
  const string param_flag(argv[3]);

  if (param_flag == "linear") {
    LinearProb<string> linear_probing_table;
    TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);    
  } else if (param_flag == "quadratic") {
    HashTable<string> quadratic_probing_table;
    TestFunctionForHashTable(quadratic_probing_table, words_filename, query_filename);    
  } else if (param_flag == "double") {
    string hello = "helo86iam";
    
    DoubleProb<string> double_probing_table;
    TestFunctionForHashTable(double_probing_table, words_filename, query_filename);    
  } else {
    cout << "Uknown tree type " << param_flag << " (User should provide linear, quadratic, or double)" << endl;
  }
  return 0;

  
}
