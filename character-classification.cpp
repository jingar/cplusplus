#include <iostream>
#include <cctype>
#include <string>
#include <sstream>

std::string classification(char c)
{
  std::string all_classification;
  if(isspace(c)){all_classification+=" is space ";}
  if(isalpha(c)){all_classification+= " is alpha ";}
  if(isdigit(c)){all_classification+= " is digit ";}
  if(isxdigit(c)){all_classification+= " is xdigit ";}
  if(isupper(c)){all_classification+= " is uppercase ";}
  if(islower(c)){all_classification+= " is lowercase ";}
  if(isalnum(c)){all_classification+= " is alphanumeric ";}
  if(iscntrl(c)){all_classification+= " is control character ";}
  if(ispunct(c)){all_classification+= " is punctuation ";}
  if(isprint(c)){all_classification+= " is printable ";}
  //if(isgraph(c)){}
  return all_classification;
}
void write(std::stringstream& ss)
{
  std::string temp;
  char ch;
  while(ss.get(ch))
    {
      std::cout << ch << "(" << (int)ch << "): " << classification(ch) << '\n';
    }
}

int main()
{
  char ch;
  std::stringstream buffer;
  while(std::cin.get(ch))
    {
      buffer << ch;
    }
  write(buffer);
  return 0;
}
