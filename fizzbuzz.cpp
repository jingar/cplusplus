#include <iostream>



int main()
{
  for(unsigned int i = 1; i <= 100; ++i)
    {
      if(i % 5 == 0 && i % 3 == 0)
        {
          std::cout << i << ": fizzbuzz \n";
        }
      else if(i % 3 == 0)
        {
          std::cout << i << ": fizz \n";
        }
    }
  return 0;
}
