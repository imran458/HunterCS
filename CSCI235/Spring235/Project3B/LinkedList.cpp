//Â  Created by Frank M. Carrano and Timothy M. Henry.
//Â  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.
//
//  Modified by Tiziana Ligorio for Hunter College CSCI 235
//  Removed Exception Handling becuse not yet covered and
//  added Project3A specific methods

//This program was further modified by Imran Sabur on April 4, 2019 


/** ADT list: Singly linked list implementation.

 Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.hpp"  // Header file
#include <cassert>

template<class T>
LinkedList<T>::LinkedList() : head_ptr_(nullptr), item_count_(0)
{
}  // end default constructor

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& a_list) : item_count_(a_list.item_count_)
{
   Node<T>* orig_chain_pointer = a_list.head_ptr_;  // Points to nodes in original chain

   if (orig_chain_pointer == nullptr)
      head_ptr_ = nullptr;  // Original list is empty
   else
   {
      // Copy first node
      head_ptr_ = new Node<T>();
      head_ptr_->setItem(orig_chain_pointer->getItem());

      // Copy remaining nodes
      Node<T>* new_chain_ptr = head_ptr_;      // Points to last node in new chain
      orig_chain_pointer = orig_chain_pointer->getNext();     // Advance original-chain pointer
      while (orig_chain_pointer != nullptr)
      {
         // Get next item from original chain
         T next_item = orig_chain_pointer->getItem();

         // Create a new node containing the next item
         Node<T>* new_node_ptr = new Node<T>(next_item);

         // Link new node to end of new chain
         new_chain_ptr->setNext(new_node_ptr);

         // Advance pointer to new last node
         new_chain_ptr = new_chain_ptr->getNext();

         // Advance original-chain pointer
         orig_chain_pointer = orig_chain_pointer->getNext();
      }  // end while

      new_chain_ptr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class T>
LinkedList<T>::~LinkedList()
{
   clear();
}  // end destructor

template<class T>
bool LinkedList<T>::isEmpty() const
{
   return item_count_ == 0;
}  // end isEmpty

template<class T>
int LinkedList<T>::getLength() const
{
   return item_count_;
}  // end getLength

template<class T>
bool LinkedList<T>::insert(int new_position, const T& new_entry)
{
   bool able_to_insert = (new_position >= 1) && (new_position <= item_count_ + 1);
   if (able_to_insert)
   {
      // Create a new node containing the new entry
      Node<T>* new_node_ptr = new Node<T>(new_entry);

      // Attach new node to chain
      if (new_position == 1)
      {
         // Insert new node at beginning of chain
         new_node_ptr->setNext(head_ptr_);
         head_ptr_ = new_node_ptr;
      }
      else
      {
         // Find node that will be before new node
         Node<T>* prev_ptr = getNodeAt(new_position - 1);

         // Insert new node after node to which prev_ptr points
         new_node_ptr->setNext(prev_ptr->getNext());
         prev_ptr->setNext(new_node_ptr);
      }  // end if

      item_count_++;  // Increase count of entries
   }  // end if

   return able_to_insert;
}  // end insert

template<class T>
bool LinkedList<T>::remove(int position)
{
   bool able_to_remove = (position >= 1) && (position <= item_count_);
   if (able_to_remove)
   {
      Node<T>* cur_ptr = nullptr;
      if (position == 1)
      {
         // Remove the first node in the chain
         cur_ptr = head_ptr_; // Save pointer to node
         head_ptr_ = head_ptr_->getNext();
      }
      else
      {
         // Find node that is before the one to delete
         Node<T>* prev_ptr = getNodeAt(position - 1);

         // Point to node to delete
         cur_ptr = prev_ptr->getNext();

         // Disconnect indicated node from chain by connecting the
         // prior node with the one after
         prev_ptr->setNext(cur_ptr->getNext());
      }  // end if

      // Return node to system
      cur_ptr->setNext(nullptr);
      delete cur_ptr;
      cur_ptr = nullptr;

      item_count_--;  // Decrease count of entries
   }  // end if

   return able_to_remove;
}  // end remove

template<class T>
void LinkedList<T>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class T>
T LinkedList<T>::getEntry(int position) const
{
    T dummy;
   // Check precondition
   bool able_to_get = (position >= 1) && (position <= item_count_);
   if (able_to_get)
   {
      Node<T>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
    else
        return dummy; //PROBLEM!!!! may return uninitialized object - will fix later with Exception Handling

}  // end getEntry



/************* PROJECT-SPECIFIC PUBLIC METHODS ************/

// A  wrapper to a recursive method that inverts the contents of the list
// @post the contents of the list are inverted such that
//      the item previously at position 1 is at position item_count_,
//      the item previously at position 2 is at position item_count_-1 ...
//      the item previously at position âŒŠitem_count/2âŒ‹ is at position âŒˆitem_count_/2âŒ‰
//implemented by Imran Sabur  

template<class T>
void LinkedList<T>::invert()
{
  if(head_ptr_ == nullptr)
  {
    return; 
  }else{
  invertRest(head_ptr_); //the linked list can only be accessed by the head thus that is the parameter. 
  }
}

template<class T>
void LinkedList<T>::selectionSort()
{
   if(head_ptr_ == nullptr)
   {
      return; 
   }
   head_ptr_ = recursiveSelectionSort(head_ptr_); 
   
}

 



/************* PRIVATE ************/



template<class T>
Node<T>* LinkedList<T>::getNodeAt(int position) const
{
   // Debugging check of precondition
   assert( (position >= 1) && (position <= item_count_) );

   // Count from the beginning of the chain
   Node<T>* cur_ptr = head_ptr_;
   for (int skip = 1; skip < position; skip++)
      cur_ptr = cur_ptr->getNext();

   return cur_ptr;
}  // end getNodeAt



/***************** PROJECT-SPECIFIC PRIVATE METHODS ****************/
//This is the implementation of the invertRest function



//recursively inverts the contents of he list, used for safe programming to avoid
//exposing pointers to list in public methods
// @post the contents of the list are inverted such that
//      the item previously at position 1 is at position item_count_,
//      the item previously at position 2 is at position item_count_-1 ...
//      the item previously at position âŒŠitem_count/2âŒ‹ is at position âŒˆitem_count_/2âŒ‰
// Added by Imran Sabur


template<class T>
void LinkedList<T>::invertRest(Node<T>* current_first_ptr)
{
  
  if(current_first_ptr->getNext() == nullptr) //specifies the last node, as last node's next will always be null
  {
    head_ptr_ = current_first_ptr; //  because we're going backward, now the last will be the head  
    return;

  }
  invertRest(current_first_ptr->getNext()); //traverse the node recursively 
  current_first_ptr->getNext()->setNext(current_first_ptr); //set current pointer which was was previous to the next pointer
  current_first_ptr->setNext(nullptr); //set the next to null because that is first 


}







template<class T>
Node<T>* LinkedList<T>::recursiveSelectionSort(Node<T>* current_first_ptr)
{
   
   
   Node<T>* curr_ptr = current_first_ptr; //iterating pointer will also point to first node
   Node<T>* prev_min = nullptr; 
   Node<T>* min_ptr = current_first_ptr;


   if(current_first_ptr == nullptr ||current_first_ptr->getNext() == nullptr) //conditional for a single node
   {
      return current_first_ptr;
   }

   while(curr_ptr->getNext() != nullptr)
   {
      if(curr_ptr->getNext()->getItem() < min_ptr->getItem())  //if value of iterating ptr is less than first node - our minimum
      {
         min_ptr = curr_ptr->getNext(); //that becomes a new minimum
         prev_min = curr_ptr; // 

      }

      curr_ptr = curr_ptr->getNext(); 
   }


   if(prev_min == current_first_ptr)
   {
      current_first_ptr->setNext(min_ptr->getNext());
      min_ptr->setNext(current_first_ptr);         
      
   }
   else if(min_ptr != current_first_ptr)
   {
      Node<T>* temp = min_ptr->getNext(); //temp variable which holds mins get next
      min_ptr->setNext(current_first_ptr->getNext());
      prev_min->setNext(current_first_ptr);
      current_first_ptr->setNext(temp); 

   }

   


   Node<T>* r_ptr = recursiveSelectionSort(min_ptr->getNext()); 
   min_ptr->setNext(r_ptr);

   return min_ptr; 
   
   
}




