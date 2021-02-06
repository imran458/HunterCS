#include <iostream>
#include "LinkedList.hpp"
#include "Node.hpp"



int main()
{
    

    LinkedList<int> reverse_list;
    
    reverse_list.insert(1,1);
    reverse_list.insert(2,2);
    reverse_list.insert(3,3);
    reverse_list.insert(4,5);
    reverse_list.insert(5,8);
    reverse_list.insert(6,9);

    std::cout << reverse_list.getEntry(1) << std::endl;  

    
}