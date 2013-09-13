#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
void expand_buffer(std::string s)
{
  char ch;
  std::size_t found = s.find("nt",0);
  while(found != std::string::npos)
    {
      s.insert(found," ");
      s.insert(found+2,"o");
      found = s.find("nt",found+1);
    }
  std::cout << s <<'\n';
}

int main()
{
  std::string line;
  std::stringstream buffer;
  std::getline(std::cin,line);
  for(int i = 0; i < line.size();++i)
    {
      if(!ispunct(line[i]))
        {
          buffer << line[i];
        }
      else if(line[i] == '-')
        {
          buffer << line[i];
        }
    }
  std::cout << "remove punct: " << buffer.str() << '\n';
  expand_buffer(buffer.str());
  std::cout << '\n';
  return 0;
}
