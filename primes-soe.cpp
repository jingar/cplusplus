#include <iostream>
#include <vector>
#include <cmath>

void prime_soe(std::vector<bool>& numbers)
{
  //find all the multiples of every number 2 and size of vector
  for(unsigned int i = 2; i < numbers.size();i++)
    {
      //always make j equal a multiple of i but making it equal to i and simply adding i to it every iteration
      for(unsigned int j = i; j < numbers.size(); j+=i)
	{
	  //we dont care about i but every multiple after i that has not been marked
	  if(j > i  && numbers[j] == false)
	    {
	      numbers[j] = true;
	    }
	}
    }
}



void print_primes(const std::vector<bool>& numbers,int max)
{
  int counter = 0;
  for(unsigned int i = 2; i < numbers.size(); ++i)
    {
      if(numbers[i] == false)
	{
	  std::cout << i <<  "\n";
	  ++counter;
	}
      if(counter == max)
	{
	  break;
	}
    }
}

void print_primes(const std::vector<bool>& numbers)
{
  for(unsigned int i = 2; i < numbers.size(); ++i)
    {
      if(numbers[i] == false)
	{
	  std::cout << i <<  "\n";
	}
    }
}
int main()
{
  int user_input = 0,max = 0;
  std::cout << "This program calculates primes up to Max, enter the value for max" << std::endl;
  std::cin >> max;
  user_input = max;
  if(max <= 0)
    {
      std::cout << "Dont give me stupid input \n";
      return -1;
    }
  else if(max > 5)
    {
      max = (max * log(max)) + (max * log(log(max)));
      std::cout << "max >5:  " << max << std::endl;    
    }
  else
    {
      std::cout << "less than 5\n";
      max = 11;
    }

  std::vector<bool> numbers(max+1,false);
  prime_soe(numbers);
  print_primes(numbers,user_input);
  //print_primes(numbers);
}
