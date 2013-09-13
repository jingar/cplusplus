#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <sstream>
#include <stdexcept>
#include <algorithm>
void print_vector(const std::vector<int>& numbers)
{
  for(unsigned int i = 0 ; i < numbers.size();++i)
    {
      std::cout << numbers[i] << '\n';
    }
}

void insertion_sort(std::vector<int>& numbers)
{
  for(unsigned int current_index = 1; current_index < numbers.size();++current_index)
    {
      int key = numbers[current_index];
      int previous_index = current_index - 1;
      while(previous_index >= 0 && numbers[previous_index] > key)
	{
	  numbers[previous_index+1] = numbers[previous_index]; // swap current number with previous number;
	  --previous_index;
	}
      numbers[previous_index + 1] = key;
    }
}

void compare(const std::vector<int> numbers)
{
  std::vector<int> numbers_copy = numbers;
  std::sort(numbers_copy.begin(),numbers_copy.end());

  if(std::equal(numbers.begin(),numbers.end(),numbers_copy.begin()))
    {
      std::cout << "all match \n";
    }
    else
      {
	std::cout << "not all match \n";
      }
}
void generate_random_number(std::vector<int>& numbers,int amount_generated)
{
unsigned long int seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 gen(seed);
  std::uniform_int_distribution<int> distribution(0,9);
  for(int i = 0; i < amount_generated; ++ i)
    {
      numbers.push_back(distribution(gen));
    }
}

int main(int argc, char* argv[])
{
  try
    {
      std::vector<int> numbers;
      std::istringstream ss(argv[1]);
      int iterations;
      if(!(ss >> iterations))
	{
	  throw std::runtime_error("could not convert input number");
	}
      generate_random_number(numbers,iterations);
      print_vector(numbers);
      std::cout << "-------------------- \n";
      insertion_sort(numbers);
      print_vector(numbers);
      compare(numbers);
    }
  catch(std::exception& e)
    {
      std::cerr << "runtime error: " << e.what() << '\n';
    }
}
