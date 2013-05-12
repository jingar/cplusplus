#include <iostream>
#include <vector>

void find_primes(std::vector<int>& p,int max)
{
  p.push_back(2);
  for(int i = 3 ; i <= max;i++)
    {
      for(unsigned int j = 0; j <p.size(); j++)
	{	 

	  if((i%p[j]) ==0)
	    {
	      p.push_back(i);
	    }
	}
    }
}

void print_primes(std::vector<int> p)
{
 
  for(unsigned int i = 0; i < p.size();i++)
    {
      std::cout << "primes[" << i << "] = " << p[i] << "\n";
    }
}
int main()
{
  std::vector<int> primes;
  
  std::cout << "This program calculates primes from 1 to max, please enter the value for max" << std::endl; 

  int max = 0;
  if(std::cin >> max)
  {
      find_primes(primes,max);
      print_primes(primes);
    }
  else
    {
      std::cout << "Error" << std::endl; 
      return -1;
    }
  return 0;
}
