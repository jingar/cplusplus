#include <iostream>
#include <string>

int main()
{
  const double upper_bound = 100;
  std::string user_input = "";
  int mid = 0, higher = upper_bound, lower = 0;

  std::cout << "This is a guessing game , enter a number between 0 and 100 and i will try to guess it" << std::endl;


  while(lower <= higher)
    {
      mid = lower + (higher - lower)/2;
      std::cout << "Is your number more or less equal to  " << mid << std::endl;
      std::cin >> user_input;
      if(user_input == "equal")
	{
	  std::cout << "This is your number " << mid << std::endl;
	}
      else if(user_input == "more")
	{
	  lower = mid + 1;
	}
      else if(user_input == "less")
	{
	  higher = mid -1;
	}
      else
	{
	  std::cout << "Unrecognized symbol" << user_input << std::endl;
	  return -1;
	}

    }
  std::cout << "The number is " << mid << std::endl;
  return 0;
  
}
