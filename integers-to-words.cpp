 #include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
std::vector<std::string> units;
std::vector<std::string> teens;
std::vector<std::string> tens;
std::vector<std::string> large_units;
std::vector<long> numbers;
long unsigned position = 0;
long unit = 0;
long large_unit_position = 0;
std::string large_unit = "";
bool is_next()
{
   if(position < numbers.size())
    {
      return true;
    }
   return false;
}

long get_next()
{

  if(!is_next())
    {
      return -1;
    }
  long n = numbers[position];
  ++position;
  return n;
}

void initalize_words()
{
  units.push_back(" zero ");
  units.push_back(" one" );
  units.push_back(" two ");
  units.push_back(" three ");
  units.push_back(" four ");
  units.push_back(" five ");
  units.push_back(" six ");
  units.push_back(" seven ");
  units.push_back(" eight ");
  units.push_back(" nine ");
  
  teens.push_back(" ten ");
  teens.push_back(" eleven ");
  teens.push_back(" twelve ");
  teens.push_back(" thirteen ");
  teens.push_back(" fourteen ");
  teens.push_back(" fifteen ");
  teens.push_back(" sixteen ");
  teens.push_back(" seventeen ");
  teens.push_back(" eighteen ");
  teens.push_back(" nineteen ");
  
  tens.push_back("");
  tens.push_back("");
  tens.push_back(" twenty ");
  tens.push_back("thirty ");
  tens.push_back(" fourty ");
  tens.push_back(" fifity ");
  tens.push_back(" sixity ");
  tens.push_back(" seventy ");
  tens.push_back(" eighty ");
  tens.push_back(" ninety");
  
  large_units.push_back("");
  large_units.push_back(" thousand ");
  large_units.push_back(" million ");
  large_units.push_back(" billion ");
  large_units.push_back(" trillion ");
  large_units.push_back(" quadrillion ");
  large_units.push_back(" quintillion ");
}

void take_input()
{
  long i;
  std::cin >> i;
  while(i != 0)
    {
      numbers.push_back(i %10);
      i = i/10;
    }
}
std::string handle_units()
{
  long n = get_next();
  if(large_unit_position != 0)
    {
      large_unit = large_units[large_unit_position];
    }
  if (n != -1)
    {
      unit = n;
      return units[n] + large_unit;
    }
  return "" + large_unit;
}


std::string handle_tens()
{
  std::string s = handle_units();
  long n = get_next();
  if(n == 1)
    {  
      return teens[unit] + large_unit;
    }
  else if( n == -1)
    {
      return s;
    }
  else
    {
      return tens[n] + s;
    }
  return s;
}

std::string handle_hundreds()
{
  std::string s = handle_tens();
  long  n = get_next();
  ++large_unit_position;
  if( n == -1 || n == 0)
    {
      return s;
    }
  return units[n] + " hundred " + s;
}

int main()
{
  try
    {

      initalize_words();
      take_input();
      std::string temp;
      while(is_next())
	{

	  temp =  handle_hundreds() + temp;
	}
	std::cout << temp << '\n';
    }
  catch(std::runtime_error& e)
    {
      std::cerr << "runtime error: " << e.what() << '\n';
      return -1;
    }
}
