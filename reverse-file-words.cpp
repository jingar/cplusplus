#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <algorithm>

void reverse_file_words(std::vector<char>& file_characters)
{
  int begin = 0;
  int end = 0;
  for(unsigned int i = 0; i < file_characters.size();++i)
    {
      if(isspace(file_characters[i]))
        {
          end = i;
          std::reverse(file_characters.begin()+begin,file_characters.begin()+end);
          begin = end+1;
        }
      ++end;
    }
  for(unsigned int i = 0; i < file_characters.size();++i)
    {
      std::cout << file_characters[i];
    }
}
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
  reverse_file_words(file_characters);
}
