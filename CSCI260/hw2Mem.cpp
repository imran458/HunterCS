#include <iostream>
using namespace std;


int main() {
  struct foo_t {
    int x[100];
    int var1;
    int y[10];
    } foo;

  int var2;
  long i;
  int *p, *q;
  int *ptr; //MOD
  short int *s;
  long int *l;
  struct foo_t bar[50];

  for (i=0; i<100; i++) foo.x[i]=100+i;
  for (i=0; i<10; i++)  foo.y[i]=200+i;
  foo.var1 = 250;

  cout << sizeof(*s) << "\n"; //s is 2 bytes or 16 bits for shorts
  cout << sizeof(*p) << "\n"; //p is 4 bytes or 32 bits for regular ints
  cout << sizeof(*l) << "\n"; //l is 8 bytes or 64 bits for longs
  cout << sizeof(*ptr) << "\n"; 
  q = (int *) &foo;    cout << q << "\n"; // this prints 0x7ffedfea12b0, address of??
  p=&(foo.x[5]);       cout << *p << "\n"; //prints 105
 // POINT 1
  q = (int *) &var2;   cout << q << "\n"; //prints 0x7ffeed5982ac
  q = p+16;            cout << *q << "\n"; //prints 121
  i = ((long) p) + 16;
  q = (int *) i;       cout << *q << "\n"; //prints 109
  s = (short *) i;     cout << *s << "\n"; //prints 109
  l = (long *) i;      cout << *l << "\n"; //prints 472446402669
  q = p+95;            cout << *q << "\n";  // EXPLAIN
  
  q = p+98;            cout << *q << "\n"; //prints 202
  i = ((long) p) + 17;
  q = (int *) i;       cout << *q << "\n";
  q = p + 101;     cout << *q << "\n"; //MOD to print 205
  q = (int *) (((long) p) + 404);  cout << *q << "\n"; //MOD to print 205
  p = (int *) bar;
  *(p + 988) = 500; cout << bar[8].var1 << "\n";

   
}