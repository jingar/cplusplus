#include <iostream>
#include <string>
#include <cmath>


int main()
{
  char symbol = ' ';
  double first_number = 0.0 , second_number = 0.0;
  std::cout << "This is a simple calculator which supports addition ,subtraction ,division , multiplication and modulus operations" 
	    << std::endl;
  if(!(std::cin >> first_number >> symbol >> second_number))
    {
      std::cout << "Syntax error in expression" << std::endl;
      return -1;
    }
 
  switch(symbol)
    {
    case'+':
      std::cout << first_number << " " << symbol << " " << second_number << " = " << first_number + second_number << std::endl;
      break;
    case'-':
      std::cout << first_number << " " << symbol << " " << second_number << " = " << first_number - second_number << std::endl;
      break;
    case'/':
      std::cout << first_number << " " << symbol << " " << second_number << " = " << first_number / second_number << std::endl;
      break;
    case'*':
      std::cout << first_number << " " << symbol << " " << second_number << " = " << first_number * second_number << std::endl;
      break;
    case'%':
      std::cout << first_number << " " << symbol << " " << second_number << " = " << fmod(first_number,second_number) << std::endl;
      break;



    }
  // std::cout << first_number << " first_number" << std::endl;
  // std::cout << symbol << " symbol" << std::endl;
  // std::cout << second_number << "second_number" << std::endl;
  return 0;
}
