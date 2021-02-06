#include <iostream>
#include "LinkedList.hpp"
using namespace std; 


int main()

    LinkedList<int> testlist;


    testlist.insert(1,5);
    testlist.insert(2,2);
    testlist.insert(3,9);
    testlist.insert(4,1);
    testlist.insert(5,3);
    testlist.insert(6,8);

    
    testlist.selectionSort();

    std::cout << "a: " << testlist.getEntry(1) << std::endl;
    std::cout << "b: " << testlist.getEntry(2) << std::endl;
    std::cout << "c: " << testlist.getEntry(3) << std::endl; 
    std::cout << "d: " << testlist.getEntry(4) << std::endl;
    std::cout << "e: " << testlist.getEntry(5) << std::endl;
    std::cout << "f: " << testlist.getEntry(6) << std::endl;

    //should print, 1,2,3,5,8,9 if done correctly.

    
 

    /*

    template<class T>
Node<T>* LinkedList<T>::min_prev(Node<T>* current_first_ptr)
{
   Node* min_ptr = current_first_ptr; 

   Node* prev_min = nullptr; 

   Node* temp = current_first_ptr; 
   while(temp->getNext() != nullptr) //traverse node
   {
      if(temp->getNext()->getItem() < min_ptr->getItem()
      {
          min_ptr = temp->getNext(); 
          prev_min = temp; 
      }

      temp = temp->getNext();
   }
 
   return prev_min; 
   */




}