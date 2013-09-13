#include <iostream>
#include <random>
#include <fstream>
#include <chrono>
#include <limits>

int main()
{
  std::string file_name;
  std::cin >> file_name;
  std::ofstream ofs(file_name.c_str());
  ofs.exceptions(ofs.exceptions()|std::ios_base::badbit);
  if(ofs.fail())
    {
      std::cout << "error outputting - some data may have been written to file \n";
    }
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::mt19937 generator(seed);
  std::uniform_int_distribution<int> distribution(0,10);
  
  for(unsigned int i = 0; i < 1000; ++i)
    {
      ofs << distribution(generator) << '\n';
    }
}
