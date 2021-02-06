Imran Sabur
CSCI 335 Assignment 3

All parts of this assignment are complete: linear_probing, double_hashing, as well as the necessary 
calculations such as the number of items, collisions , load factor and the average number of 
collisions. 

Please note that I submitted this project one day late because of errors in the deletion
portion of the spell_check. The program was having trouble recognizing the i+1 letter. Via
advice from the tutoring center, I was able to diagnose my problem and get it running correctly.
I hope this does not effect my grade as the problem was very specific to my code style. 

To compile Parts 1 & 2 on terminal, please type (in this order)

make clean
make all
./create_and_test_hash words.txt query_words.txt <flag> 

The flag is the type of hashtable: linear, quadratic or double.

I chose 191 as the R value for R - (x mod R), as it was the largest prime number that I used in order
to get the values close to what was shown in the expected results

Please note that compilation may result in warnings, especially prime functions but please ignore.

To compile Part 3, please type (in this order)

make clean
make all
./spell_check <document file> <dictionary file>

The document file is of your choosing and the dictionary file is wordsEn.txt.

The user may experience warnings when compiling on terminal but please do ignore and compile
anyway. 

I chose a linear hash table for my implemenation of Part C. 


