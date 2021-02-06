// Imran Sabur
// This is the Chain class that implements the big five as well as some functions in order to enhance understanding to dynamic array.
// Functions were provided by the instructor. Operator to add chain and string was added by Imran Sabur
// Note that line 109 may cause a warning, do ignore! 
// 9/10/19

#ifndef CSCI335_HOMEWORK1_CHAIN_
#define CSCI335_HOMEWORK1_CHAIN_

#include <iostream>
#include <cstddef>
#include <array>
#include <string>
#include <sstream>


namespace teaching_project {
// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Chain {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor.
  Chain(){
    size_ = 0; //initialize values
    array_ = nullptr; 
  }

  // Copy-constructor.
  Chain(const Chain &rhs){

    size_ = rhs.size_;
    array_ = new Object[size_]; //new dynamically created array to copy contents of this array to rhs
    for(int i = 0;i < rhs.size_;i++){
      array_[i] = rhs.array_[i]; 
    }

  }

  // Copy-assignment. 
  Chain& operator=(const Chain &rhs){
    //code was provided in comments
    Chain copy = rhs; 
    std::swap(*this, copy);
    return *this;
  }

  // Move-constructor. 
  Chain(Chain &&rhs){
    size_ = rhs.size_; //make the private variables equal to the the input in contructor
    array_ = rhs.array_;
    rhs.size_ = 0; //reset variables afterwards 
    rhs.array_ = nullptr; 
  }
  
  // Move-assignment.
  // Just use std::swap() for all variables.
  Chain& operator=(Chain &&rhs){

   if(this != &rhs){
     delete[] array_; // delete the old array
     size_ = 0; //reset it's size back to 0 

     size_ = rhs.size_; //update size and array
     array_ = rhs.array_;


     rhs.size_ = 0; //reset
     rhs.array_ = nullptr; 
    }

    return *this;
  }

  ~Chain() {

    delete []array_; //delete the array
    size_ = 0; //reset size

  }

  // End of big-five.

  // One parameter constructor.
  Chain(const Object& item) {
    size_ = 1; //update size 
    array_ = new Object[1]; //dynamically allocate array of size 1
    array_[0] = item; //array in the first index will be the item itself
  }

  // Read a chain from standard input.
  void ReadChain() {

    std::string line; 
    getline(std::cin,line);
    line.erase(0,1); //removes the first bracket
    line.pop_back();// removes last bracket 
   
  
    std::stringstream ss(line);
    ss >> size_; //gets the size and stores it in string variable
    Object convert_;
    array_ = new Object[size_]; //dynamically allocated array
    //The line below produces a warning during compilation as "ch" is not being used. Please ignore the warning and continue to run as this line is necessary for the removal of colon.
    char ch = ss.get(); //removes colon 
    for(int i =0; i < size_; i++){
          ss >> convert_; 
         array_[i] = convert_; //puts elements in string line  into the array 
        
    }

  }

  size_t size() const {
    return size_;
  } 

  // @location: an index to a location in the chain.
  // @returns the Object at @location.
  // const version.
  // abort() if out-of-range.
  const Object& operator[](size_t location) const { 

    //conditional for the location index, if it's less than 0 error out of range
    if(location < 0){
     abort(); 
   }else{
     return array_[location];
   }
    // Write something
  }

 // @location: an index to a location in the range.
 // @returns the Object at @location.
 // non-const version.
 // abort() if out-of-range.
 Object& operator[](size_t location) 
 { 
   
   //conditional for the location index, if it's less than 0 error out of range
   if(location < 0){
     abort(); 
   }else{
     return array_[location];
   }
    
 }

 //  @c1: A chain.
 //  @c2: A second chain.
 //  @return the concatenation of the two chains.
 friend Chain operator+(const Chain &c1, const Chain &c2) {
   
   
   Chain t;
   t.size_ = c1.size_ + c2.size_;
   t.array_ = new Object[t.size_]; //new dynamically allocated array with t's size

   for(int i = 0; i < c1.size_;i++){
     t.array_[i] = c1.array_[i];
   }

  int l = c1.size_;  //counter to keep track of c1's size
   for(int j =0; j < c2.size_;j++){
     t.array_[l] = c2.array_[j];
     l++; 
   }
   
   return t; 


 }

 // @p1: A chain
 // @w: an object of any type
 // @return the concatentation of the chain and Object 
 friend Chain operator+(const Chain& p1,const Object& w){

   Chain r;
   r.size_ = p1.size_;
   r.array_ = new Object[r.size_+1]; //new array of r's size + 1 as one more object is being added

  for(int i =0; i  < p1.size_;i++){

     r.array_[i] = p1.array_[i];
  }

  r.array_[r.size_ - 1] = w; //set the object w to the last item in the array 

  return r; 

 } 
  

 // Overloading the << operator.
 friend std::ostream &operator<<(std::ostream &out, const Chain &a_chain) {
   //prints items in array in the order described in the output
   out << "[";
    for(int i =0; i < a_chain.size_;i++){
      if(i < a_chain.size_-1)
      {
        out << a_chain.array_[i] << " ";
      }
      else
      {
        out << a_chain.array_[i] << "]" << std::endl;
      }
    }

    //edge case if arr is empty
    if(a_chain.array_ == nullptr){
      out << "]" << std::endl;
    }
   // Prints the chain.
   return out;
 }
 
 private:
  size_t size_;
  Object *array_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_CHAIN_
