#include <iostream>
#include <cctype>
struct X 
{
  void f(int x) 
  {
    struct Y {
      int f()
      {
        return 1 ; 
      } 
      int m; 
    };
    int m;
    m=x; 
    Y m2;
    return f(m2.f()); 
  }
  int m;
  void g(int m) 
  {
    if (m)
      {
        f(m+2);
      }
    else 
      {
        g(m+2); 
      }
  }
  X()
  { 
  }
  void m3() 
  {
  }
  void main() 
  {
    X a; a.f(2); 
  }
};

int main()
{
  X test;
  test.f(10);
  return 0;
}
