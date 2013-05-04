#include <iostream>

int square(int x)
{
  int number = 0;
  for(int i = 0; i < x; i ++ )
    {
      number+=x;
    }
  return number;
}
int main()
{
  int number = 0;
  std::cout << "Enter a number to be sqaured (must be a integer)" << std::endl;
  std::cin >> number;
  std::cout << square(number) << std::endl;

  return 0;
}
