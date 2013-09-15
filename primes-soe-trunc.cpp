#include <iostream>
#include <vector>
#include <cmath>

void prime_soe(std::vector<bool>& numbers)
{
  const unsigned int limit = static_cast<int>(sqrt(numbers.size()));
  //find all the multiples of every number, starting from 2 but less than sqrt of size of the vector
  for(unsigned int i = 2; i < limit;i++)
    {
      //always make j equal a multiple of i but making it equal to i and simply adding i to it every iteration
      for(unsigned int j = i*i; j < numbers.size(); j+=i)
	{
	  //we dont care about i but every multiple after i that has not been marked
	  if(numbers[j] == true)
	    {
	      // std::cout << j << ": is a multiple \n";
	      numbers[j] = false;
	    }
	}
      // std::cout << "-----end----\n";
    }
}

bool is_prime(int n)
{
  if(n < 2) return false;
  if(n == 2 || n == 3) return true;
  if(n%2 == 0 || n%3 == 0) return false;
  const int limit = static_cast<int>(sqrt(n));
  for(int i = 5; i <= limit;i+=2)
    {
      if(n%i == 0)
  	return false;
    }
  return true;
}

bool is_right_trunc_prime(int n)
{
  int result = n;
  while(n != 0)
    {
      if(!is_prime(n))
	{
	  // std::cout << n << ": is not right trunc prime \n";
	  return false;
	}
      n/=10;
      // std::cout << n << " removedright digit \n";
    }
  // std::cout << result  << ": is a right trunc prime \n";
  return true;
}

bool is_left_trunc_prime(int n)
{
  //std::cout << "in is_left_trunc_prime \n";
  //std::cout << "n: " << n << " \n";
  
  int counter = 1;
  while(counter < n)
    {
      counter*=10;
    }
  //std::cout << "new counter: " << counter << '\n';
  while(n != 0)
    {
      //std::cout << "in while(n != 0) \n";
      if(!is_prime(n))
	{
	  //std::cout << n << ": is not left trunc prime \n";
	  return false;
	}
      counter/=10;
      //std::cout << "counter/10: " << counter << "\n";
      if(n < counter) // means that there was a zero in the number , which got taken away
	{
	  //std::cout << "n < counter \n";
	  return false;
	}
      //std::cout << "counter " << counter<< '\n';
      n%=counter;
      //std::cout << n << " removed left digit \n";
    }
  // std::cout << result  << ": is a left trunc prime \n";
  return true;
}


void print_primes(const std::vector<bool>& numbers)
{
  for(unsigned int i = 2; i < numbers.size(); ++i)
    {
      if(numbers[i] == true)
	{
	  std::cout << i <<  "\n";
	}
    }
}
int main()
{
  std::vector<bool> prime_numbers(1000000,true);
  prime_soe(prime_numbers);

  for(unsigned int i = 2; i < 100; ++i)
    {
      if(prime_numbers[i] == true)
	{
	  if(is_prime(i))
	    {
	      std::cout << i << " is a prime \n";
	    }
	  else
	    {
	      std::cout << i << " is not a prime \n";
	    }
	}
    }
  // prime_soe(prime_numbers);
  // // print_primes(prime_numbers);
  // int largest_left_trunc_prime = 0;
  // int largest_right_trunc_prime = 0;
  // for(unsigned int i = 2; i < prime_numbers.size();++i)
  //   {
  //     if(prime_numbers[i] == true)
  // 	{
  // 	  if(is_left_trunc_prime(i))
  // 	    {
  // 	      largest_left_trunc_prime = i;
  // 	    }
  // 	  if(is_right_trunc_prime(i))
  // 	    {
  // 	      largest_right_trunc_prime = i;
  // 	    }
  // 	}
  //   }
  // std::cout << "largest left trunc prime: " << largest_left_trunc_prime << '\n';
  // std::cout << "largest right trunc prime: " << largest_right_trunc_prime << '\n';
}
