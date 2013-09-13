#include<iostream>
#include<cstdio>
using namespace std;
 
class Test
{
public:
  Test() {  cout<<"Default constructor called "<<endl;}
   Test(const Test &t)
   {
      cout<<"Copy constructor called "<<endl;
   }
   Test& operator = (const Test &t)
   {
      cout<<"Assignment operator called "<<endl;
   }
};


int main()
{
  Test t1; // default constructor
  // t2 = t1; assinment
  // Test t3 = t1; // copy constructor
  Test t2(t1); // copy constructor
  getchar();
  return 0;
}











