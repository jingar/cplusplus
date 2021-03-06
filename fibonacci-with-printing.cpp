#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>


void print(const std::string& s, const std::vector<int>& v)
{
  const unsigned int element_till_newline = 10;
  std::cout << s << " {";
  
  for(unsigned int i = 0; i < v.size();++i)
    {
      if(i == v.size() -1) // if its the last element dont print comma
        {
          std::cout << v[i];
        }
      else if(i == element_till_newline)
        {
          std::cout << v[i] << ", \n";
        }
      else
        {
          std::cout << v[i] << ",";
        }
    }
  std::cout << "} \n";
 
}c

void fibbonaci_vector(int first,int second,std::vector<int>& store, int total_steps)
{
  if(total_steps <=0)
    {
      throw std::runtime_error("you must choose to generate at least 1 element of the fibbonaci sequence");
    }
  else if(total_steps <=1)
    {
      store.push_back(first);
    }
  else if(total_steps <= 2)
    {
      store.push_back(second);
    }
  for(int i = 0; i < total_steps; ++i)
    {
      int next = first + second;
      store.push_back(next);
      first = second;
      second = next;
    }
}

int main()
{
  std::cout << "Enter three values: first and second value will used as the start of the fibonnaci sequence and the third value will be used as number of elements to be generated \n";
  std::cout << "Type in any non integer value to cancel \n";
  int first = 0;
  int second = 0;
  int steps = 0;
  try
    {
      while(std::cin >> first >> second >> steps)
        {
          std::vector<int> fibs;
          fibbonaci_vector(first,second,fibs,steps);
          print("fibs",fibs);
        }
      return 0;
    }
  catch(std::runtime_error& e)
    {
      std::cerr << "runtime error: " << e.what() << std::endl;

    }
}
