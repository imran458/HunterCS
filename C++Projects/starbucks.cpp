#include <iostream>
using namespace std;

bool isPrime(int x)
{

}


int main()
{
    string response;

    int a;
    int b;
    int difference;
    int sum; 

    cout << "Enter a number: \n";
    cin >> a;

    cout << "Enter another number: \n";
    cin >> b; 

    cout << "What operation would you like to perform? (Add or Subtract) \n";
    cin >> response; 

    sum = a+b;
    difference = a-b;

    if(response == "Add")
    {
        cout << "The sum is " << sum;
    }else{
        cout << "The difference is " << difference << endl; 
    }

    return 0; 
}

cout << "Hello Wrold"; 