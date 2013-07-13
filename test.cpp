#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

int main( ) 
{

  std::cout << "Please enter input file name: \n";
  std::string f_name;
  std::cin >> f_name;
  std::ifstream ist(f_name.c_str());
  if(!ist)
  {
    std::cerr << "Error file could not be opened \n";
    return 0;
  }
  std::string r;
  while(ist >> r)
  {
    std::cout << r << "\n";
  }
  return 0;
}

