#include <iostream>
using namespace std;

void checkDivisors(int x)
{
    for(int i=1;i <= x;i++)
    {
        if(x%i == 0)
        {
            return i;
        }
    }
}

int main()
{
    cout << checkDivisors(100) << endl; 
}