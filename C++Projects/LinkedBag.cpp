//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//  Modified by Tiziana Ligorio 2019 for CSCI 235 Hunter College

//Imran Sabur 
//Professor Ligorio
// The implementation for bagUnion, bagDifference, bagIntersectNoDuplicates, made by Imran Sabur for class CSCI 235, Project 2A. 

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

#include "LinkedBag.hpp"
#include "Node.hpp"
#include <cstddef>

template<class T>
LinkedBag<T>::LinkedBag() : head_ptr_(nullptr), item_count_(0)
{
}  // end default constructor

template<class T>
LinkedBag<T>::LinkedBag(const LinkedBag<T>& a_bag)
{
	item_count_ = a_bag.item_count_;
   Node<T>* orig_chain_ptr = a_bag.head_ptr_;  // Points to nodes in original chain

   if (orig_chain_ptr == nullptr)
      head_ptr_ = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      head_ptr_ = new Node<T>();
      head_ptr_->setItem(orig_chain_ptr->getItem());

      // Copy remaining nodes
      Node<T>* new_chain_ptr = head_ptr_;      // Points to last node in new chain
      orig_chain_ptr = orig_chain_ptr->getNext();     // Advance original-chain pointer

      while (orig_chain_ptr != nullptr)
      {
         // Get next item from original chain
         T next_item = orig_chain_ptr->getItem();

         // Create a new node containing the next item
         Node<T>* new_node_ptr = new Node<T>(next_item);

         // Link new node to end of new chain
         new_chain_ptr->setNext(new_node_ptr);

         // Advance pointer to new last node
         new_chain_ptr = new_chain_ptr->getNext();

         // Advance original-chain pointer
         orig_chain_ptr = orig_chain_ptr->getNext();
      }  // end while

      new_chain_ptr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class T>
LinkedBag<T>::~LinkedBag()
{
   clear();
}  // end destructor

template<class T>
bool LinkedBag<T>::isEmpty() const
{
	return item_count_ == 0;
}  // end isEmpty

template<class T>
int LinkedBag<T>::getCurrentSize() const
{
    return item_count_;
}  // end getCurrentSize

template<class T>
bool LinkedBag<T>::add(const T& new_entry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (head_ptr_ is null if chain is empty)
   Node<T>* next_node_ptr = new Node<T>();
   next_node_ptr->setItem(new_entry);
   next_node_ptr->setNext(head_ptr_);  // New node points to chain
//   Node<T>* next_node_ptr = new Node<T>(new_entry, head_ptr_); // alternate code

   head_ptr_ = next_node_ptr;          // New node is now first node
   item_count_++;

   return true;
}  // end add


template<class T>
std::vector<T> LinkedBag<T>::toVector() const
{
   std::vector<T> bag_contents;
   Node<T>* cur_ptr = head_ptr_;
	while ((cur_ptr != nullptr))
   {
		bag_contents.push_back(cur_ptr->getItem());
        cur_ptr = cur_ptr->getNext();
   }  // end while

   return bag_contents;
}  // end toVector

template<class T>
bool LinkedBag<T>::remove(const T& an_entry)
{
   Node<T>* entry_node_ptr = getPointerTo(an_entry);
   bool can_remove = !isEmpty() && (entry_node_ptr != nullptr);
   if (can_remove)
   {
      // Copy data from first node to located node
      entry_node_ptr->setItem(head_ptr_->getItem());

      // Delete first node
      Node<T>* node_to_delete = head_ptr_;
      head_ptr_ = head_ptr_->getNext();

      // Return node to the system
      node_to_delete->setNext(nullptr);
      delete node_to_delete;
      node_to_delete = nullptr;

      item_count_--;
   } // end if

	return can_remove;
}  // end remove


template<class T>
void LinkedBag<T>::clear()
{
   Node<T>* node_to_delete = head_ptr_;
   while (head_ptr_ != nullptr)
   {
      head_ptr_ = head_ptr_->getNext();

      // Return node to the system
      node_to_delete->setNext(nullptr);
      delete node_to_delete;

      node_to_delete = head_ptr_;
   }  // end while
   // head_ptr_ is nullptr; node_to_delete is nullptr

	item_count_ = 0;
}  // end clear


template<class T>
int LinkedBag<T>::getFrequencyOf(const T& an_entry) const
{
	int frequency = 0;
   int counter = 0;
   Node<T>* cur_ptr = head_ptr_;
   while ((cur_ptr != nullptr) && (counter < item_count_))
   {
      if (an_entry == cur_ptr->getItem())
      {
         frequency++;
      } // end if

      counter++;
      cur_ptr = cur_ptr->getNext();
   } // end while

	return frequency;
}  // end getFrequencyOf

template<class T>
bool LinkedBag<T>::contains(const T& an_entry) const
{
	return (getPointerTo(an_entry) != nullptr);
}  // end contains




// private


/**
 @return Returns either a pointer to the node containing a given entry
 or the null pointer if the entry is not in the bag.
 */
template<class T>
Node<T>* LinkedBag<T>::getPointerTo(const T& an_entry) const
{
    bool found = false;
    Node<T>* cur_ptr = head_ptr_;

    while (!found && (cur_ptr != nullptr))
    {
        if (an_entry == cur_ptr->getItem())
            found = true;
        else
            cur_ptr = cur_ptr->getNext();
    } // end while

    return cur_ptr;
} // end getPointerTo

template<class T>
LinkedBag<T> LinkedBag<T>::bagUnion(const LinkedBag<T>& a_bag) const 
{
   LinkedBag<T> union_bag; // new bag of linkedbag 
   Node<T>* uptr = head_ptr_; // start with the head pointer
   
   while(uptr != nullptr ) //traverse the node until you reach the end 
   {
      union_bag.add(uptr->getItem()); // add the contents of this bag into the union bag
      uptr = uptr->getNext();  // go the next node 
       
   }   

   Node<T>* temp_ = a_bag.head_ptr_; // the temp variable points to the head of abag
   while(temp_ != nullptr)
   {
      union_bag.add(temp_->getItem()); 
      temp_ = temp_->getNext();
   }
   
   return union_bag; 
}
//end bagUnion


/* @param a_bag to be subtracted from this bag
 @return a new LinkedBag that contains only those items that occur in
 this bag or in a_bag but not in both, and it does not contain duplicates
 */
template<class T>
LinkedBag<T> LinkedBag<T>::bagDifference(const LinkedBag<T>& a_bag) const
{
   LinkedBag<T> differenceBag; //new bag of type linkedbag

   Node<T>* cur_ptr = head_ptr_; // points to head of this bag

   while(cur_ptr != nullptr) 
   {
      if(!differenceBag.contains(cur_ptr->getItem()) && !a_bag.contains(cur_ptr->getItem()))//if the difference bag does not contain items of this bag and a_bag doesn't as well 
      {
         differenceBag.add(cur_ptr->getItem()); //add it to the difference bag
      }
      
      cur_ptr = cur_ptr->getNext(); // go to next node 

   }

   cur_ptr = a_bag.head_ptr_; //set the current pointer to head of abag

   while(cur_ptr->getNext() != nullptr) //while the next node is not null
   {
      if(!differenceBag.contains(cur_ptr->getItem()) && !contains(cur_ptr->getItem())) //diff bag doesn't contain items of abag and duplicated ones
      {
         differenceBag.add(cur_ptr->getItem()); //add those to the current bag
      }
      
      cur_ptr = cur_ptr->getNext(); //go to next pointer

   }

   return differenceBag; 

}
//end bagDifference

/* @param a_bag to be intersected with the contents of this (the calling)
 bag
 @return a new LinkedBag that contains the intersection of the contents
 of this bag and those of the argument a_bag. This intersection does not
 contain duplicates (e.g. every element occurring in BOTH bags will be
 found only once in the intersection, no matter how many occurrences in
 the original bags) as in set intersection A ∩ B
 */
template<class T>
LinkedBag<T> LinkedBag<T>::bagIntersectionNoDuplicates(const LinkedBag<T>& a_bag) const 
{
   LinkedBag<T> inter_bag;
   Node<T>* inter_ptr = a_bag.head_ptr_;
   
   while(inter_ptr != nullptr)//traverse the list until the pointer equals null then it will stop
   {
      //if the new bag doesn't contain the next item but the abag contains it, add it
      if(!inter_bag.contains(inter_ptr->getItem()) && contains(inter_ptr->getItem())) 
      {
         inter_bag.add(inter_ptr->getItem());
      }
      inter_ptr = inter_ptr->getNext(); //move on to the next node after checking the condition
       
   }

   inter_ptr = head_ptr_; //repeat the same for the head pointer of this bag
   while(inter_ptr != nullptr)
   {
      if(!inter_bag.contains(inter_ptr->getItem()) && a_bag.contains(inter_ptr->getItem())) //not in this but in abag then add
      {
         inter_bag.add(inter_ptr->getItem());
      }
      inter_ptr = inter_ptr->getNext(); //advance pointer
   }  


   
   return inter_bag; 

}
//end bagIntersectnoDuplicates

/**
 @param a_bag whose contents are to be copied to this (the calling) bag
 @post this (the calling) bag has same contents as a_bag
 */

template<class T>
void LinkedBag<T>::operator= (const LinkedBag<T>& a_bag)
{
   item_count_ = a_bag.item_count_;
   Node<T>* orig_chain_ptr = a_bag.head_ptr_;  // Points to nodes in original chain

   if (orig_chain_ptr == nullptr)
      head_ptr_ = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      head_ptr_ = new Node<T>();
      head_ptr_->setItem(orig_chain_ptr->getItem());

      // Copy remaining nodes
      Node<T>* new_chain_ptr = head_ptr_;      // Points to last node in new chain
      orig_chain_ptr = orig_chain_ptr->getNext();     // Advance original-chain pointer

      while (orig_chain_ptr != nullptr)
      {
         // Get next item from original chain
         T next_item = orig_chain_ptr->getItem();

         // Create a new node containing the next item
         Node<T>* new_node_ptr = new Node<T>(next_item);

         // Link new node to end of new chain
         new_chain_ptr->setNext(new_node_ptr);

         // Advance pointer to new last node
         new_chain_ptr = new_chain_ptr->getNext();

         // Advance original-chain pointer
         orig_chain_ptr = orig_chain_ptr->getNext();
      }  // end while

      new_chain_ptr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor


//end operator 



/**
 @param new_entry to be added to the bag
 @post new_entry is added at the end of the chain preserving the order of
 items in the bag
 @return true if added successfully, false otherwise
 */
template<class T>
bool LinkedBag<T>::addToEnd(const T& new_entry)
{
   Node<T>* add_ptr; // new pointer of head
   Node<T>* next_ptr = new Node<T>(); // new node pointer
   next_ptr->setItem(new_entry); //points to the entry's pointer 
   next_ptr->setNext(nullptr);

   if(!add_ptr)
   {
      add_ptr = next_ptr; //if not go to next
      return false;
   }
   else
   {
      Node<T>* end = add_ptr;
      while(end->getNext() != nullptr)
      {
         end = end->getNext(); 
         return true; 
      }

   }


}
//end addToEnd

