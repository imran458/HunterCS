//Imran Sabur
//Imran Sabur added locate(); and edited FindPos() in order to make it work for linear probing

#include "quadratic_probing.h"
#ifndef LINEAR_PROBING_H
#define LINEAR_PROBING_H

#include <vector>
#include <algorithm>
#include <functional>


  // namespace


// Linear Probing probing implementation.
template <typename HashedObj>
class LinearProb {
 public:
  enum EntryType {ACTIVE, EMPTY, DELETED};

  explicit LinearProb(size_t size = 101) : array_(NextPrime(size)),collision_counter(0)
    { MakeEmpty(); }
  
  bool Contains(const HashedObj & x) const {
    return IsActive(FindPos(x));
  }
  
  void MakeEmpty() {
    current_size_ = 0;
    for (auto &entry : array_)
      entry.info_ = EMPTY;
  }

  bool Insert(const HashedObj & x) {
    // Insert x as active
    size_t current_pos = FindPos(x);
    if (IsActive(current_pos))
      return false;
    
    array_[current_pos].element_ = x;
    array_[current_pos].info_ = ACTIVE;
    
    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash();    
    return true;
  }

/*
   *Bulk of this function was copy and pasted from the FINDPOS function
   *This locates a word and returns true if that element was found
   
  */
bool locate(const HashedObj& y){
    probe_counter = 1;
    size_t offset = 1;
    size_t current_pos = InternalHash(y);
      
    while (array_[current_pos].info_ != EMPTY &&array_[current_pos].element_ != y){
      current_pos += offset;  // Compute ith probe.
      offset += 2;
      probe_counter++;
      if (current_pos >= array_.size()){
        current_pos -= array_.size();
      } //end if
	
    } //end while

    //Part Imran added
    if(array_[current_pos].info_ == EMPTY) return false; 
    else if(array_[current_pos].element_ == y)return true;
    

    return false;
  } 


bool Insert(HashedObj && x) {
    // Insert x as active
    size_t current_pos = FindPos(x);
    if (IsActive(current_pos))
      return false;
    
    array_[current_pos] = std::move(x);
    array_[current_pos].info_ = ACTIVE;

    // Rehash; see Section 5.5
    if (++current_size_ > array_.size() / 2)
      Rehash();

    return true;
  }


//return the number of items in the table
  size_t get_num_items(){
    return current_size_; 
  }


int get_probes(){
     return probe_counter; 
   }

//function returns the size of the hash table
int get_size(){
    return array_.size(); 
}

 int get_collisions(){
    return collision_counter; 
  }



  bool Remove(const HashedObj & x) {
    size_t current_pos = FindPos(x);
    if (!IsActive(current_pos))
      return false;

    array_[current_pos].info_ = DELETED;
    return true;
  }

 private:        
  struct HashEntry {
    HashedObj element_;
    EntryType info_;
    
    HashEntry(const HashedObj& e = HashedObj{}, EntryType i = EMPTY)
    :element_{e}, info_{i} { }
    
    HashEntry(HashedObj && e, EntryType i = EMPTY)
    :element_{std::move(e)}, info_{ i } {}
  };
    
  mutable int collision_counter; //Imran added
  mutable int probe_counter = 1;  //Imran added
  std::vector<HashEntry> array_;
  size_t current_size_;

  bool IsActive(size_t current_pos) const
  { return array_[current_pos].info_ == ACTIVE; }

  size_t FindPos(const HashedObj & x) const {
    size_t offset = 1;
    size_t current_pos = InternalHash(x);
      
    while (array_[current_pos].info_ != EMPTY &&
	   array_[current_pos].element_ != x) {
     collision_counter++;
      current_pos += offset;  // Compute ith probe.
      
       
      if (current_pos >= array_.size()){
          current_pos -= array_.size();
      }//end if
	
    }
    return current_pos;
  }

  void Rehash() {
    std::vector<HashEntry> old_array = array_;

    // Create new double-sized, empty table.
    array_.resize(NextPrime(2 * old_array.size()));
    for (auto & entry : array_)
      entry.info_ = EMPTY;
    
    // Copy table over.
    current_size_ = 0;
    for (auto & entry :old_array)
      if (entry.info_ == ACTIVE)
	Insert(std::move(entry.element_));
  }
  
  size_t InternalHash(const HashedObj & x) const {
    static std::hash<HashedObj> hf;
    return hf(x) % array_.size( );
  }
};

#endif  // QUADRATIC_PROBING_H
