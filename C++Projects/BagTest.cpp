/*
Imran Sabur
CSCI 235
This is the implementation of the bagtest file. 

*/

#include <iostream>
#include <fstream>
#include "BagTest.hpp"
#include "ArrayBag.hpp"
#include "CourseMember.hpp"
using namespace std; 

void BagTest::displayCourseMemberBag(const ArrayBag<CourseMember>& a_bag)
{
    //STUB  
}

ArrayBag<CourseMember> BagTest::testCourseMemberBag()
{
   /*
    string filename; 
    cout << "Input a filename" << endl;
    cin >> filename;
    ifstream myInputFile(filename);

    if(!myInputFile.is_open())
    {
        exit(EXIT_FAILURE)
        
    }
    else
    {
        while(!myInputFile.eof())
        {
            getline(myInputFile, id, ',');
            getline(myInputFile, first, ',');
            getline(myInputFile, last, ',');
        

            CourseMember cobj(id,first,last);
            cobj.add(bag_);

        }
        myInputFile.close()
        return bag_; 
    }
    

     


    //ask user for input filename and store it in a var called filename
    //open the file stream = in_stream
    //check instream was successfull 
    // for each line in the inputfile until eof
    //          read info 
    //           getline (in_stream, id, ',');   '\n'
    //           instantiate coursemember
    //             add coursemember to bag 
    //close file
    // return bag_
    */
    return bag_;   
}