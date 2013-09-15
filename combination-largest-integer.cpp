#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <sstream>
#include <boost/lexical_cast.hpp>

int converting_vectorint_to_int(const std::vector<int>& v)
{

}

void print_vector (const std::vector<int>& v)
{
  for(unsigned int i = 0; i < v.size();++i)
    {
      std::cout << v[i];;
    }
  std::cout << '\n';
}
//using a vector of integers find the combiniantion that grants the largest integer by concatenating
//all integers in the vector
int find_largest_int_concat(std::vector<int> numbers)
{
  std::stringstream ss;
  std::string perm;
  //auto find_first_digit = [](int number) ->int {while(number>=10) number/=10;return number;};
  //std::sort (numbers.begin(),numbers.end());
  do
    {
      for(int i: numbers)
	{
	  ss << i;
	}
      if(ss.str() > perm)
	{
	  perm = ss.str();
	}
      ss.str("");
      //print_vector(numbers);
    }
  while(std::next_permutation(numbers.begin(),numbers.end()));
  std::cout << "perm: " << perm << '\n';
  return 1;
}


int main()
{
  std::vector<int> numbers = {54,546,548,60};
  std::vector<int> numbers2 = {1, 34, 3, 98, 9, 76, 45, 4}
;
  //converting_vectorint_to_int(numbers);
  std::cout << find_largest_int_concat(numbers) << '\n';
  std::cout << find_largest_int_concat(numbers2) << '\n';
}



