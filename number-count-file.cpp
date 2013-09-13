#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>

void random_number(const std::string& file_name,int number)
{
  std::ofstream ofs(file_name.c_str());
  ofs.exceptions(ofs.exceptions()|std::ios_base::badbit);
  if(ofs.fail())
    {
      std::cout << "error outputting - some data may have been written to file \n";
    }
  auto seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> distribution(0,10);
  
  for(int i = 0; i < number; ++i)
    {
      ofs << distribution(generator) << '\n';
    }
}
void read_number(const std::string& file_name,std::vector<int>& numbers)
{
  std::ifstream ifs(file_name.c_str());
  ifs.exceptions(ifs.exceptions()|std::ios_base::badbit);
  int number;

  while(ifs >> number)
    {
      numbers.push_back(number);
    }
  if(ifs.eof())
    {
      std::cout << "finished reading - end of file reached \n";
      return;
    }
  if(ifs.fail())
    {
      std::cout << "error reading - but some data may have been taken in \n";
      return;
    }
}

void write_number(const std::string& file_name,const std::vector<int>& numbers)
{
  std::ofstream ofs(file_name.c_str());
  ofs.exceptions(ofs.exceptions()|std::ios_base::badbit);
  std::vector<int> unique_numbers = numbers;
  unique_numbers.erase(std::unique(unique_numbers.begin(),unique_numbers.end()),unique_numbers.end());
  for(auto i : unique_numbers)
    {
      ofs << i << " " << std::count(numbers.begin(),numbers.end(),i) << '\n';
    }
  if(ofs.fail())
    {
      std::cout << "error outputting - some data may have been written to file \n";
      return;
    }
}


void write_number_diff(const std::string& file_name,const std::vector<int>& numbers)
{
  std::ofstream ofs(file_name.c_str());
  ofs.exceptions(ofs.exceptions()|std::ios_base::badbit);
  unsigned int i = 0;
  while(i < numbers.size())
    {
      int counter = 0;
      unsigned int j = i;
      while(j < numbers.size())
        {
          if(numbers[i] == numbers[j])
            {
              ++counter;
              ++j;
            }
          else
            {
              break;
            }
        }
      ofs << numbers[i] << " " << counter << '\n';
      i = j;
    }
  
  if(ofs.fail())
    {
      std::cout << "error outputting - some data may have been written to file \n";
      return;
    }
}

void print_vector(const std::vector<int>& v)
{
  for(auto i: v)
    {
      std::cout << i << '\n';
    }
 }
int main( int argc, const char* argv[])
  {
    std::vector<int> numbers;
    random_number("input.txt",atoi(argv[1]));
    read_number("input.txt",numbers);
    std::sort(numbers.begin(),numbers.end(),[](int first,int second){return first < second;}); // sort decesnding order
    auto start = std::chrono::steady_clock::now();
    write_number("output.txt",numbers);
    // write_number_diff("output.txt",numbers);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    std::cout << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
  }
