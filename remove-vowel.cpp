#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdio>
#include <cctype>
#include <sstream>
bool is_vowel(char c)
{
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
     c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    {
      return true;
    }
  return false;
}
int main() 
{
  std::string in_file = "input.txt";
  std::stringstream buffer;
  std::ifstream ifs(in_file.c_str());
  ifs.exceptions(ifs.exceptions()|std::ios_base::badbit);
  char c;
  while(ifs.get(c))
    {
      if(!is_vowel(c))
        {
          buffer << (char)toupper(c);
        }
    }

  std::cout << buffer.str();
  return 0;
}
