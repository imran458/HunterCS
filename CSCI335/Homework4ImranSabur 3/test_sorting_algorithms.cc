// Homework 4
// Testing Sorting Algorithms
// YOUR NAME

#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
using namespace std;

namespace {
// Test function that shows how you can time a piece of code.
// Just times a simple loop.

void TestTiming() {
  cout << "Test Timing" << endl;
  const auto begin = chrono::high_resolution_clock::now();
  // Time this piece of code.
  int sum = 0;
  for (int i = 1; i < 10000; ++i) sum ++;
  // End of piece of code to time.
  const auto end = chrono::high_resolution_clock::now();    
  cout << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "ns" << endl;
  cout << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms" << endl;

}

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

    if (sort(input.begin(), input.end(), greater<int>())) return true; //code for greater comparator 
    
    //compares i , i+1
    less_than(a[i],a[i+1]); 

  // Add code.
  return true;
}

// Signature for quicksort (heapsort / mergesort similar signatures)
template <typename Comparable, typename Comparator>
void QuickSort(vector<Comparable> &a, Comparator less_than) {
  // quicksort implementation
  // to be filled
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
  if (input_type != "random" && input_type != "sorted_small_to_large") {
    cout << "Invalid input type" << endl;
    return 0;
  }
  if (input_size <= 0) {
    cout << "Invalid size" << endl;
    return 0;
  }
  if (comparison_type != "less" && comparison_type != "greater") {
    cout << "Invalid comparison type" << endl;
    return 0;
  }
  
  // This block of code to be removed for your final submission.
  TestTiming();

  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " 
       << comparison_type << endl;
  vector<int> input_vector;
  if (input_type == "random") {
    input_vector = GenerateRandomVector(input_size);
    
  } else {
    // Generate sorted vector.
  }

  // Call quicksort / heapsort / mergesort using appropriate input.
  // ...
  // if comparison type is "less" then call 
  // QuickSort(input_vector, less<int>{})
  // otherwise call
  // QuickSort(input_vector, greater<int>{})
  // ...
  return 0;
}
