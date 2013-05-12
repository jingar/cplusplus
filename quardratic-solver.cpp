#include <iostream>
#include <cmath>

void quadratic_solver(double a, double b, double c)
{
  double temp = (b*b) - (4 * a * c);
  if(temp < 0)
    {
      std::cout << "This equation has no real roots ";
      return;
    }
  else if ( temp == 0)
    {
      double one_root = (-b + sqrt(temp))/ 2 * a;
      std::cout << "There is one root, " << one_root << std::endl;
    }
  else
    {
      double one_root = (-b + sqrt(temp))/ 2 * a;
      double two_root = (-b - sqrt(temp))/ 2 * a;
      std::cout << "There are two root, " << one_root << ", " << two_root << std::endl;
    }
 
 
}


int main()
{
  double a = 0.0,b = 0.0 , c = 0.0;

  std::cout << "This is a quadartic formula solver" << std::endl;
  std::cout << "Enter the first value" << std::endl;
  std::cin >> a;
  std::cout << "Enter the second value" << std::endl;
  std::cin >> b;
  std::cout << "Enter the third value" << std::endl;
  std::cin >> c;


  quadratic_solver(a,b,c);
  return 0;
}
