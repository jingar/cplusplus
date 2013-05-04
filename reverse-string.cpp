#include <iostream>
#include <vector>
#include <string>

int main()
{
  std::string user_input = "";
  int start_string = 0;

  std::cout << "Enter the input you want to reverse" << std::endl;
  getline(std::cin, user_input);

  std::cout << user_input << std::endl;
  int end_string = user_input.length()-1;
  
  while(end_string > start_string)
    {
      std::cout << user_input << std::endl;
      char temp = user_input[end_string];
      user_input[end_string] = user_input[start_string];
      user_input[start_string] = temp;
      start_string++;
      end_string--;
    }
  

}
