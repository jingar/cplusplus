#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::string user_input = "";

  std::cout << "Enter the input you want to reverse" << std::endl;


  

  while(std::cin >> user_input)
    {
      int start_string = 0;
      int end_string = user_input.length()-1;
      while(end_string > start_string)
	{
	  char temp = user_input[end_string];
	  user_input[end_string] = user_input[start_string];
	  user_input[start_string] = temp;
	  start_string++;
	  end_string--;
	}
      std::cout << user_input << std::endl;
    }
  
  
}
