#include <iostream>
#include "Node.hpp"
#include "LinkedBag.hpp"
#include <cstddef>


int main()
{
    LinkedBag<int> bag1;
    LinkedBag<int> bag2; 
    std::vector<int> outBag; 
    
    bag1.add(1);
    bag1.add(2);
    bag1.add(5);
    bag1.add(6);
    

    

    bag2.add(1);
    bag2.add(2);
    bag2.add(7);
    bag2.add(8);

    

    LinkedBag<int> ubag = bag2.bagDifference(bag1);

    outBag = ubag.toVector();

    for(int i = 0; i < outBag.size(); i++)
    {
        std::cout << outBag[i] << std::endl; 
    }

    std::cout << "\n "; 

    return 0; 
}

// should return 5,6,7,8