Author: Imran Sabur
Date: November 22, 2019
Class: CSCI 335
Professor Ioannis Stamos

This project was done in order to test the runtimes of different algorithms, namely HeapSort, MergeSort and, QuickSort.

Furthermore, this project also tested the runtimes of the three variations of quicksort:
    a) Median of three 
    b) Middle pivot (always	select	the	middle	item in	the	array)
    c) First pivot	(always	select	the	first item	in the array)  

All runtimes are reported in ns (nanoseconds)

There are no known bugs in the program currently, however note that for inputs greater than 50,000,
one may encounter a segmentation fault. 

A bulk of the code was provided by sort.h, however I copy and pasted the necessary code
for each particular sorting algorithm and put in a class. Via this approach, I instantiated
a new object for each type of sort and this inevitably allowed for a much cleaner style and reduced redudancies. 


To compile type (in this order):

 make clean
 make all

To test runtimes for different sorting algorithms, please type:

./test_sorting_algorithms	<input_type>	<input_size>	<comparison_type>

such as:

./test_sorting_algorithms random 20000 less
./test_sorting_algorithms sorted 10000 greater

To test runtimes of different quicksorts, please type:

./test_sorting_algorithms	<input_type>	<input_size>	<comparison_type>

./test_qsort_algorithm random 20000 less

and or any variations of input size or of the two comparison_types: less or greater