#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>


void print_almost_equal(double val_1,double val_2)
{
  const double almost_equal = 1.0/10000000;

  if(fabs(val_1 - val_2) < almost_equal)
    {
      std::cout << "the numbers are almost equal" << std::endl;
    }
}

void print_vector(std::vector<double> & v)
{
  sort(v.begin(),v.end());
  for(unsigned int i = 0; i < v.size();i++)
    {
      std::cout << v[i] << std::endl;
    }
}
int main()
{
  double value = 0.0;
  const double m_to_cm =100 , inch_to_cm = 2.54, feet_to_inches = 12;
  double smallest = 0.0, largest = 0.0,sum = 0.0;
  bool is_set = false;
  int counter = 0;
  std::vector<double> store;
  std::string unit = "";

  while(std::cin >> value >> unit)//takes in a number followed by a unit, example 10 cm, value = 10 , unit = cm
    {
      if(unit.compare("m") == 0)
	{
	  sum+=value;
	}
      else if (unit.compare("cm") == 0)
	{
	  sum = sum + (value/100);
	}
      else if(unit.compare("in") == 0)
	{
	  sum = sum + ((value * inch_to_cm)/100);
	}
      else if(unit.compare("ft") == 0)
	{
	  sum = sum + ((value * feet_to_inches * inch_to_cm)/100);
	}
      else
	{
	  std::cout << "Unrecognized unit: " << unit << std::endl;
	  return 0;
	}
      if(smallest == 0.0 && largest == 0.0 && is_set == false)
	{
	  smallest = value;
	  largest = value;
	  is_set = true;
	}
      else if(value > largest)
	{
	  largest = value;
	  std::cout << largest << " largest so far " << std::endl
		    << "but the smallest is still " << smallest << std::endl;
	}
      else if (value < smallest)
	{
	  smallest = value;
	  std::cout << smallest << " smallest so far " <<  std::endl
		    << "but the largest is still " << largest << std::endl;
	}
      counter++;
      store.push_back(value);
    }
  print_vector(store);
  
  std::cout << "sum is: " << sum << "m" << " number of values entered is: " << counter << std::endl;
  return 0;
}

