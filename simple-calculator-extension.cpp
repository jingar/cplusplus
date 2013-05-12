#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> stringnums;
void initalize_stringnums()
{
  stringnums.push_back("zero");
  stringnums.push_back("one");
  stringnums.push_back("two");
  stringnums.push_back("three");
  stringnums.push_back("four");
  stringnums.push_back("five");
  stringnums.push_back("six");
  stringnums.push_back("seven");
  stringnums.push_back("eight");
  stringnums.push_back("nine");
  
}


int read_number()
{
  const int not_symbol_value = stringnums.size(); // this will make it always make it a value not stored in the stringnums, atm it goes from 0 -9 stringnums.size() will give us 11;
  int value = not_symbol_value;

  if(std::cin >> value)
    {
      return value;
    }
 
  std::string s = "";
  std::cin.clear();	// clear string after failed attempt to read an integer
  if(std::cin >> s)
    {
      for(unsigned int i = 0; i < stringnums.size();i++)
	{
	  if(stringnums[i] == s)
	    {
	      value = i;
	    }
	}
    }

  return value;

}

int main()
{
  
  initalize_stringnums();
  std::cout << "This is a simple calculator which supports addition ,subtraction ,division , multiplication and modulus operations" 
	    << std::endl;
  while(true)
    {
      int first_number = read_number();
      char symbol = 0;
      std::cin >> symbol;
      int second_number = read_number();
      switch(symbol)
	{
	case'+':
	  std::cout << first_number << " " << symbol << " " << second_number << " = " << first_number + second_number << std::endl;
	  break;
	case'-':
	  std::cout << first_number << " " << symbol << " " << second_number << " = " << first_number - second_number << std::endl;
	  break;
	case'/':
	  if(second_number == 0)
	    {
	      std::cout << "error division by 0" << std::endl;
	      break;
	    }
	  std::cout << first_number << " " << symbol << " " << second_number << " = " << first_number / second_number << std::endl;
	  break;
	case'*':
	  std::cout << first_number << " " << symbol << " " << second_number << " = " << first_number * second_number << std::endl;
	  break;
	case'%':
	  if(second_number == 0)
	    {
	      std::cout << "error modulus by 0" << std::endl;
	      break;
	    }
	  std::cout << first_number << " " << symbol << " " << second_number << " = " << first_number % second_number << std::endl;
	  break;
	}
    }
  return 0;
}
