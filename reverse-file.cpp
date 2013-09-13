#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <algorithm>

int main()
{
  std::string file_name = "input.txt";
  std::fstream file_access(file_name.c_str(),std::ifstream::in | std::ifstream::out);
  file_access.exceptions(file_access.exceptions() | std::ios_base::badbit);
  if(!file_access)
    {
      std::cout << "could not open file: " << file_name << '\n';
    }
  char ch;
  std::vector<char> file_characters;
  while(file_access.get(ch))
    {
      file_characters.push_back(ch);
    }
  std::reverse(file_characters.begin(),file_characters.end());

  for(unsigned int i = 0; i < file_characters.size();++i)
    {
      std::cout << file_characters[i];
    }
}
