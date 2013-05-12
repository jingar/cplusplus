#include <iostream>
#include <vector>
#include <cmath>

void n_primes(std::vector<bool>& numbers,int n)
{
  for(int i = 2; i < n;i++)
    {
      for(int j = i; j < n; j+=i)
	{
	  if(j > i  && numbers[j] == false)
	    {
	      std::cout << "i " << i<< "\n";
	      numbers[j] = true;
	    }
	}
    }
  
}
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



void print_n_primes(const std::vector<bool>& numbers,int n)
{
  for(int i = 2; i < n;i++)
    {
      if(numbers[i] == false)
	{
	  std::cout << i <<  "\n";
	}
    }
}

void print_primes(const std::vector<bool>& numbers)
{
  for(unsigned int i = 2; i < numbers.size();i++)
    {
      if(numbers[i] == false)
	{
	  std::cout << i <<  "\n";
	}
    }
}
int main()
{
  int max = 0;
  std::cout << "This program calculates primes up to Max, enter the value for max" << std::endl;
  std::cin >> max;
  if(max > 5)
    {
      max = (max * log(max)) + (max * log(log(max)));
      std::cout << "n " << max << std::endl;    
    }
  std::vector<bool> numbers(max+1,false);
  
 
  //  prime_soe(numbers);
  n_primes(numbers,max);
  print_n_primes(numbers,max);
  //print_primes(numbers);
}
