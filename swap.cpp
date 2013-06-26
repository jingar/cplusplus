#include <iostream>


void swap_v(int a ,int b)
{
  // std::cout << "swap_v a: " << a << '\n';
  // std::cout << "swap_v b: " << b << '\n';
  int temp; 
  temp = a;
  a=b; 
  b=temp;  

  // std::cout << "after swap_v a: " << a << '\n';
  // std::cout << "after swap_v b: " << b << '\n';
}

void swap_r(int& a ,int& b)
{
  int temp; 
  temp = a;
  a=b; 
  b=temp;  
}

void swap_cr(const int& a ,const int& b)
{
  int temp; 
  temp = a;
  a=b; 
  b=temp;  
}

int main()
{
  int x = 7;
  int y = 9;
  swap_cr(x,y);
  swap_cr(7,9);
  std::cout << "swap int x: " << x << '\n';
  std::cout << "swap int y: " << y << '\n';
  

  // const int cx = 7;
  // const int cy = 9;
  // swap_cr(cx,cy);
  // swap_cr(7.7,9.9);

  // std::cout << "swap const int cx: " << cx << '\n';
  // std::cout << "swap const int cy: " << cy << '\n';

  // double dx = 7.7;
  // double dy = 9.9;
  // swap_cr(dx,dy);
  // swap_cr(7.7,9.9);

  // std::cout << "swap double dx: " << dx << '\n';
  // std::cout << "swap double dy: " << dy << '\n';

  return 0;
}
