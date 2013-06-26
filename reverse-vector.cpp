#include <iostream>
#include <vector>
#include <string>

void reverse_vector(std::vector<int>& v)
{
  long unsigned int start_position = 0;
  long unsigned int end_position = v.size() - 1;

  while(start_position < end_position)
    {
      int temp = v[start_position];
      v[start_position] = v[end_position];
      v[end_position] = temp;
      ++start_position;
      --end_position;
    }
}


std::vector<int> return_reversed_vector(std::vector<int> v)
{
  std::vector<int> reversed_vector;

  for(int i = v.size()-1; i>=0; --i)
    {
      std::cout << "v[" << i << "]: " << v[i] << std::endl;
      reversed_vector.push_back(v[i]);
    }
  return reversed_vector;
}


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
 
}


void reverse_vector_string(std::vector<std::string>& v)
{
  std::cout << "here \n";
  long unsigned int start_position = 0;
  long unsigned int end_position = v.size() - 1;

  while(start_position < end_position)
    {
      std::cout << "in while \n";
      std::cout << "start: " << start_position << '\n';
      std::cout << "end: " << end_position << '\n';
      std::string temp = v[start_position];
      v[start_position] = v[end_position];
      v[end_position] = temp;
      ++start_position;
      --end_position;
    }
}


std::vector<std::string> return_reversed_vector_string(std::vector<std::string> v)
{
  std::vector<std::string> reversed_vector;

  for(int i = v.size()-1; i>=0; --i)
    {
      std::cout << "v[" << i << "]: " << v[i] << std::endl;
      reversed_vector.push_back(v[i]);
    }
  return reversed_vector;
}



void print(const std::string& s, const std::vector<std::string>& v)
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
 
}

int main()
{
  std::vector<int> ref = {1,2,3,4,5};
  std::vector<int> value = {6,7,8,9,10};
  reverse_vector(ref);
  print("reversed vector",ref);
  print("return reversed vector",return_reversed_vector(value));

  std::vector<std::string> ref_string = {"s","a","a","d"};
  std::vector<std::string> value_string = {"f","a","h","a","d"};
  reverse_vector_string(ref_string);
  print("reversed vector string",ref_string);
  print("return reversed vector string",return_reversed_vector_string(value_string));
  
  return 0;
}
