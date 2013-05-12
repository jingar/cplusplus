#include <iostream>

int main()
{
  double input = 0,squares = 1, counter = 0;
  // if(std::cin >> input)
  //   {
  //     while(squares < input)
  // 	{
  // 	  squares*=2;
  // 	  counter++;
  // 	  std::cout << "squares " << squares << "counter " << counter << std::endl;
	  
  // 	}
  //   }
  // std::cout << "Number of squares required for " << input << " is " << counter << std::endl;

  if(std::cin >> input)
    {
      while(counter < input)
	{
	  squares*=2;
	  counter++;
	  std::cout << "squares " << squares << " counter " << counter << std::endl;
	}
    }
}
