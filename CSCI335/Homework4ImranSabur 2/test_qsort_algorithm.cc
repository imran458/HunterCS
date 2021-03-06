// Homework 4
// Testing Sorting Algorithms (2nd program)
// YOUR NAME

#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;


template <typename Comparable, typename Comparator>
class Quick{

 public:

  void quickSort( vector<Comparable> & a,Comparator less_than )
  {
    quicksort( a, 0, a.size( ) - 1,less_than );
  }

  //regular quicksort
  void quicksort( vector<Comparable> & a, int left, int right, Comparator less_than )
  {
      if( left + 10 <= right )
      {
          const Comparable & pivot = median3( a, left, right, less_than );

              // Begin partitioning
          int i = left, j = right - 1;
          for( ; ; )
          {
              while( less_than(a[ ++i ],pivot ) == true) { }
              while( less_than(pivot, a[ --j ]) == true ) { }
              if( i < j )
                  std::swap( a[ i ], a[ j ] );
              else
                  break;
          }

          std::swap( a[ i ], a[ right - 1 ] );  // Restore pivot

          quicksort( a, left, i - 1,less_than );     // Sort small elements
          quicksort( a, i + 1, right,less_than );    // Sort large elements
      }
      else  // Do an insertion sort on the subarray
          insertionSort( a, left, right,less_than );

  }//end regular quick sort

 /**
  * Internal insertion sort routine for subarrays
  * that is used by quicksort.
  * a is an array of Comparable items.
  * left is the left-most index of the subarray.
  * right is the right-most index of the subarray.
  */
  //template <typename Comparable>
  void insertionSort( vector<Comparable> & a, int begin, int end, Comparator less_than )
  {
      for( int p = begin; p < end+1; ++p )
      {
          Comparable tmp = std::move( a[ p ] );
          int j;

          for( j = p; j > 0 && less_than(tmp, a[ j - 1 ]) == true; --j )
              a[ j ] = std::move( a[ j - 1 ] );
          a[ j ] = std::move( tmp );
      }
  }//end insert sort

  //First	pivot	(always	select	the	first	item	in	the	array)
  void first_pivot(vector<Comparable> &input, int left, int right, Comparator less_than){
  if( left + 10 <= right )
      {
          int start = left;//signfies the first element in the array 
          std::swap(input[start],input[right - 1]);
          const Comparable & pivot = input[right - 1];

              // Begin partitioning
          int i = left;   
          int j = right - 1;
          for( ; ; )
          {
              while( less_than(input[ ++i ],pivot ) == true) { }
              while( less_than(pivot, input[ --j ]) == true ) { }
              if( i < j )
                  std::swap( input[ i ], input[ j ] );
              else
                  break;
          }

          std::swap( input[ i ], input[right - 1 ] );  // Restore pivot

          first_pivot( input, left, i - 1,less_than );     // Sort small elements
          first_pivot( input, i + 1, right,less_than );    // Sort large elements
      }
      else  // Do an insertion sort on the subarray
          insertionSort( input, left, right,less_than );
  }
  
 

  
  void middle_pivot(vector<Comparable>& input, int left, int right, Comparator less_than){
  if( left + 10 <= right )
      {
          int middle = (left+right)/2; //this signifies the middle of the vector and allows it to become the pivot
          std::swap(input[middle],input[right - 1]);
          const Comparable & pivot = input[right - 1];

              // Begin partitioning
          int i = left;
          int j = right - 1;
          for( ; ; )
          {
              while( less_than(input[ ++i ],pivot ) == true) { }
              while( less_than(pivot, input[ --j ]) == true ) { }
              if( i < j )
                  std::swap( input[ i ], input[ j ] );
              else
                  break;
          }

          std::swap( input[ i ], input[right - 1 ] );  // Restore pivot

          middle_pivot( input, left, i - 1,less_than );     // Sort small elements
          middle_pivot( input, i + 1, right,less_than );    // Sort large elements
      }
      else  // Do an insertion sort on the subarray
          insertionSort( input, left, right,less_than );
    
  }
 


  /**
  * Return median of left, center, and right.
  * Order these and hide the pivot.
  * Median	of	three	(as	in	the	slides)
  */
  //template <typename Comparable>

  const Comparable & median3( vector<Comparable> & a, int left, int right,Comparator less_than )
  {
     int center = ( left + right ) / 2;
    
     if( less_than(a[ center ], a[ left ] ) == true)
          std::swap( a[ left ], a[ center ] );
      if( less_than(a[ right ] , a[ left ] ) == true)
         std::swap( a[ left ], a[ right ] );
      if( less_than(a[ right ],a[ center ] ) == true)
          std::swap( a[ center ], a[ right ] );

          // Place pivot at position right - 1
      std::swap( a[ center ], a[ right - 1 ] );
      return a[ right - 1 ];
  }
 


}; //end quicksort


namespace {


// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) {
  vector<int> a;
  for (size_t i = 0; i < size_of_vector; ++i)
    a.push_back(rand());
  return a;
}

// Here you can put your code.
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) {

  bool in_order = true; //a flag to verify that list is in order

    for(int i = 0; i < input.size() - 1;i++){ 
      if(input[i] == input[i+1] || less_than(input[i],input[i+1]) == true){} 
      else in_order = false; //means that it is not in order
    }//end for 

  return in_order;  
  
}

// Signature for quicksorts (3 implementations)
//Median of three quicksort
template <typename Comparable, typename Comparator>
void QuickSort1(vector<Comparable> &a, Comparator less_than) {
  
  Quick<int,Comparator> test_median; 
  const auto begin = chrono::high_resolution_clock::now();
  test_median.quickSort(a,less_than); 
  const auto end = chrono::high_resolution_clock::now();  

  cout << "Median of three: " << endl;
  cout << endl;   
  cout << "Median of three: Runtime:  " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << " ns " << endl;
  
  cout << endl; 
  cout << "Verified: " << VerifyOrder(a,less_than) << endl;
}

//test middle pivot
template <typename Comparable, typename Comparator>
void QuickSort2(vector<Comparable> &a, Comparator less_than) {

  Quick<int,Comparator> test_middle_pivot;

  int length = a.size() - 1; 
  
  const auto begin = chrono::high_resolution_clock::now();
  test_middle_pivot.middle_pivot(a,0,length,less_than); 
  const auto end = chrono::high_resolution_clock::now();  

  cout << "Middle: " << endl;
  cout << endl;   
  cout << "Middle Pivot: Runtime:  " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << " ns " << endl;
 
  cout << endl; 
  int verified_status = VerifyOrder(a,less_than); 
  cout << "Verified: " << verified_status << endl;
}


template <typename Comparable, typename Comparator>
void QuickSort3(vector<Comparable> &a, Comparator less_than) {
  Quick<int, Comparator> test_first_pivot;
  int length = a.size() - 1;

  const auto begin = chrono::high_resolution_clock::now();
  test_first_pivot.first_pivot(a,0,length,less_than);
  const auto end = chrono::high_resolution_clock::now(); 

  cout << "First: " << endl;
  cout << endl;   
  cout << "First: Runtime:  " << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << " ns " << endl;
  //cout << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms " << endl;
  cout << endl; 
  cout << "Verified: " << VerifyOrder(a,less_than) << endl;


}
 


// Test function that shows how you can time a piece of code.
// Just times a simple loop.
template <typename Comparable, typename Comparator>
void TestTiming(vector<Comparable> &a, Comparator less_than) {

  QuickSort1(a,less_than); 
  cout << endl; 
  cout << "-----" << endl;
  QuickSort2(a,less_than);
  cout << endl; 
  cout << "-----" << endl;
  QuickSort3(a,less_than);
  cout << endl; 
  //cout << "-----" << endl;

}

}  // namespace
int main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
    return 0;
  }
  const string input_type = string(argv[1]);
  const int input_size = stoi(string(argv[2]));
  const string comparison_type = string(argv[3]);

  cout << "Testing quicksort: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
  vector<int> input_vector;
  if (input_type == "random") {
    input_vector = GenerateRandomVector(input_size);
    
  }else if(input_type == "sorted") {
    input_vector = GenerateRandomVector(input_size);
  }else{
    cout << "Unknown input type " << endl; 
    return 0; 
  }

  if(comparison_type == "greater"){
    TestTiming(input_vector,greater<int>());
  }
  else if(comparison_type == "less"){
    TestTiming(input_vector,less<int>());
  }else
  {
    cout << "Unknown comparsion type" << endl; 
  }
  
  
  return 0;
}
