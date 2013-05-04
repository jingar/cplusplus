#include <iostream>

int main()
{
  int negative_num,value = 0;
  std::cout << "Please enter a series of numbers and i will count how many of them are negative" << std::endl;
  while(std::cin >> value )
    {
      if(value < 0)
	{
	  negative_num++;
	}
    }
  std::cout << "Ther are " << negative_num << " negative numbers" << std::endl;
  return 0;

}
