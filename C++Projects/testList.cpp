
#include <iostream>
#include "List.hpp"

int main () 
{
    List<int> test_list;

    test_list.insert(0,3);
    test_list.insert(1,4);
    test_list.insert(2,5);
    test_list.insert(3,6);
    test_list.insert(4,3);
    test_list.insert(5,4);
    test_list.insert(6,5);
    test_list.insert(7,9);
    test_list.insert(8,5);
    test_list.insert(9,4);
    test_list.insert(10,3);
    test_list.insert(11,2);
    test_list.insert(12,5);
    test_list.insert(13,7);
    test_list.insert(14,4);


    List<int> sub_list = test_list.scanSublist(5);

    sub_list.traverse();






}