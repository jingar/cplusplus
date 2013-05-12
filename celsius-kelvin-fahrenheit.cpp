#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <cstdlib>
#include <vector>

const double lowest_temperature = -273.15; // in celsius

//pre-condition - c must be equal to or greater than -273.15
//post-condition - return converted temperature or throw exception
double ctof(double celsius)
{
  if(celsius < lowest_temperature)
    {
      throw std::runtime_error("Temperature given is below the lowest possible");
    }
  double fahrenheit = celsius * 9/5 + 32;
  return fahrenheit;
}


//pre-conditions - kelvin cannot be less than 0
//post-conditions - return celsius value or throw exception
double ktoc(double kelvin)
{
  if(kelvin < 0)
    {
      throw std::runtime_error("Lowest possible value for kelving is 0");
	}

  double celsius = kelvin - 273.15;
  return celsius;
}



//pre-condition - c must be equal to or greater than -273.15
//post-condition - return converted temperature or throw exception
double ctok(double c)
// converts Celsius to Kelvin
{

  if(c < lowest_temperature)
    {
      throw std::runtime_error("Temperature given is below the lowest possible");
    }
  double k = c + 273.15;
  return k;
}
int main()
{
  try
    {
      double c = 0; // decplare input variable
      if(std::cin >> c)// retrieve temperature into input variable
	{
	  //double k = ctok(c); // celsius to kelvin
	  //double k = ktoc(c); // kelvin to celsius
	  double k = ctof(c);
	  std::cout << k << std::endl ; // print out temperature
	}
      else
	{
	  std::cerr << "invalid input " << std::endl;
	}
    }
  catch(std::runtime_error& e)
    {
      std::cerr << "runtime error: " << e.what() << '\n';
      return -1;
    }
  catch(...)
    {
      std::cerr << "something unexpected occured" << '\n';
    }
}
