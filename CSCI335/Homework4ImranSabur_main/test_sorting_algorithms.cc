// Homework 4
// Testing Sorting Algorithms
// Imran Sabur
//November 22,2019

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

template <typename Comparable, typename Comparator>
class Heap{
  public:
		void heapsort(vector<Comparable> & a, Comparator less_than)
		{
			for (int i = a.size()/2 - 1; i >= 0; --i)
			{
				percDown(a,i,a.size(),less_than); //added to support comparator 
			}
			for (int j = a.size() - 1; j > 0; --j) 
			{
				swap(a[0],a[j]);
				percDown(a,0,j,less_than);
			}
		}

		inline int leftChild(int i)
		{
			return 2 * i + 1;
		}

		void percDown(vector<Comparable> & a, int i, int n, Comparator less_than)
		{
			int child;
			Comparable tmp;
			
			for (tmp = std::move(a[i]); leftChild(i) < n; i=child) 
			{
				child = leftChild(i);
				if (child != n-1 && less_than(a[child],a[child+1]) == true)
				{
					child++;
				}
				if (less_than(tmp,a[child]) == true)
				{
					a[i] = move(a[child]); 
				}
				else
				{
					break; 
				}
			}
			a[i] = move(tmp);
		}
};//end class HeapSort

template<typename Comparable, typename Comparator> 
class Merge{
  public:
	
		void mergeSort(vector<Comparable> & a, Comparator less_than)
		{
			vector<Comparable> tmpArray(a.size());
			mergeSort(a,tmpArray,0,a.size()-1,less_than);
		}


		void mergeSort(vector<Comparable> & a, vector<Comparable> & tmpArray, int left, int right, Comparator less_than)
		{
			if (left < right)
			{
				int center = (left+right)/2;
				mergeSort(a,tmpArray,left,center,less_than); 
				mergeSort(a,tmpArray,center+1,right,less_than); 
				merge(a,tmpArray,left,center+1,right,less_than);
			}
		}

		void merge(vector<Comparable> & a, vector<Comparable> & tmpArray, int leftPos, int rightPos, int rightEnd, Comparator less_than)
		{
			int leftEnd = rightPos - 1;
			int tmpPos = leftPos;
			int numElements = rightEnd - leftPos + 1;


			while (leftPos <= leftEnd && rightPos <= rightEnd)
			{
				if (less_than(a[leftPos],a[rightPos]) == true)
				{
					tmpArray[tmpPos++] = move(a[leftPos++]);
				}
				else
				{
					tmpArray[tmpPos++] = move(a[rightPos++]);
				}
			}

			// Left
			while (leftPos <= leftEnd)
			{
				tmpArray[tmpPos++] = move(a[leftPos++]);
			}

			// Right
			while (rightPos <= rightEnd)
			{
				tmpArray[tmpPos++] = move(a[rightPos++]);
			}

			// Copy Array
			for (int i = 0; i < numElements; ++i, --rightEnd)
			{
				a[rightEnd] = move(tmpArray[rightEnd]);
			}
		}
}; 

template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) {

  bool in_order = true; //a flag to verify that list is in order

    for(int i = 0; i < input.size() - 1;i++){ 
      if(input[i] == input[i+1] || less_than(input[i],input[i+1]) == true){} 
      else in_order = false; //means that it is not in order
    }//end for 

  return in_order; 
    
}
namespace {

//function to test timing of mergesort and report verify status
template <typename Comparable, typename Comparator>
void MergeSort(vector<Comparable> &a, Comparator less_than){
  Merge<int,Comparator> test_merge; //object of type mergesort

  const auto begin = chrono::high_resolution_clock::now();

	test_merge.mergeSort(a, less_than); //call the merge sort driver function

	const auto end = chrono::high_resolution_clock::now();

	cout << "MergeSort: Runtime: " << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << "ns" <<endl;
	cout << "Verified: " << VerifyOrder(a, less_than) <<endl; //report verify order status

}

//function to test timing of heapsort and report verified status
template <typename Comparable, typename Comparator>
void HeapSort(vector<Comparable> &a, Comparator less_than) {
  Heap<int, Comparator> test_heap; //object of type heapsort

  const auto begin = chrono::high_resolution_clock::now();

	test_heap.heapsort(a, less_than); //call heapsort function

	const auto end = chrono::high_resolution_clock::now();

	cout << "HeapSort: Runtime: " << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << "ns" <<endl;
	cout << "Verified: " << VerifyOrder(a, less_than) <<endl; //report verify order status
}

//function to test timing of heapsort and report verified status
template <typename Comparable, typename Comparator>
void Time_Quick_Sort(vector<Comparable> &a, Comparator less_than){

  Quick<int, Comparator> test_quick; //object of type quicksort

  const auto begin = chrono::high_resolution_clock::now();

	test_quick.quickSort(a, less_than); //call quick sort function

	const auto end = chrono::high_resolution_clock::now();

	cout << "QuickSort: Runtime: " << chrono::duration_cast<chrono::nanoseconds>(end-begin).count() << "ns" <<endl;
	cout << "Verified: " << VerifyOrder(a, less_than) <<endl; //report verified status

}

// Driver Function that calls heapsort,mergesort and quick sort and prints the timing, verified status
template <typename Comparable, typename Comparator>
void TestTiming(vector<Comparable> &a, Comparator less_than) {
  HeapSort(a,less_than); 
  cout << endl; 

  MergeSort(a,less_than); 
  cout << endl; 

  Time_Quick_Sort(a,less_than);
  cout << endl; 

}

// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) {
  vector<int> a;
  for (size_t i = 0; i < size_of_vector; ++i)
    a.push_back(rand());
  return a;
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
  
  
  

  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " 
       << comparison_type << endl;
  vector<int> input_vector;
  if (input_type == "random") {
    input_vector = GenerateRandomVector(input_size);
    
  } else if(input_type == "sorted") {
    input_vector = GenerateRandomVector(input_size);
  }else{
    cout << "Unknown comparison type" << endl; 
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
