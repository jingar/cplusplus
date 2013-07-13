#include <iostream>
#include <cctype>
#include <stdexcept>
void skip_to_int()
{
  if(std::cin.fail())
    {
      std::cin.clear();
      char ch;
      while(std::cin >> ch)
        {
          if(isdigit(ch))
            {
              std::cin.unget();
              return;
            }

        }
    }
  throw std::runtime_error("no input: end of file reached");
}


int get_int()
{
  int n = 0;
  while(true)
    {
      if(std::cin >> n)
        {
          return n;
        }
      skip_to_int();
    }
}

int get_int(int low,int high)
{
  int n = 0;
  while(true)
    {
      n = get_int();
      if(low<=n && n<=high)
        {
          return n;
        }
    }
}
int main()
{
  try
    {
      std::cin.exceptions(std::cin.exceptions() | std::ios_base::badbit);
      int test = get_int();
      
    }
  catch(std::runtime_error& e)
    {
      std::cerr << "runtime error: " << e.what() << '\n';
    }
  catch(...)
    {
      std::cerr << "unexpected error \n";
    }


}
