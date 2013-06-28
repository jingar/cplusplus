#include <iostream>
#include <vector>
#include <string>

void print_until_s(const std::vector<std::string>& v, const std::string& quit)
{
  int occurence = 0;
  for(unsigned int i= 0; i<v.size(); ++i) 
    {
      if(v[i] == quit)
        {
          ++occurence;
          if(occurence == 2)
            {
              return;
            }
        }
      std::cout << v[i] << '\n';
    }
}

int main()
{
  std::vector<std::string> words = {"once" ,"upon" ,"a", "time", "quit", "wow" , "quit"};
  print_until_s(words,"quit");
  return 0;
}
