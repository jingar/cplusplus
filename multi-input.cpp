#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <stdexcept>

enum Base {decimal,octal,hexadecimal};

void write (Base b, int i)
{
  switch(b)
    {
    case hexadecimal:
      std::cout << std::hex << i << "hexadecimal " << std::setw(8);
      break;
    case octal:
      std::cout << std::oct <<  i << "octal      " << std::setw(8);
      break;
    case decimal:
      std::cout << std::dec << i << "decimal     " << std::setw(8);
      break;
    default:
      throw std::runtime_error("unknown type");
    }
  std::cout  << "converts to " << std::dec << i << " decimal \n";
}

int main()
{
  try
    {
      int i;
      std::cin.unsetf(std::ios::dec);
      std::cin.unsetf(std::ios::hex);
      std::cin.unsetf(std::ios::oct);
      std::cout << std::showbase;
      std::cout << "Enter numbers (octal,hexadecimal,decimal) \n";
      char c;
      while(std::cin.get(c))
        {
          if(c == '0')
            {
              std::cin.get(c);
              if(c == 'x' || c == 'X')
                {
                  std::cin >> std::hex >> i;
                  write(hexadecimal,i);
                }
              else if(c == '8'|| c == '9')
                {
                  throw std::runtime_error("unknown octal value");
                }
              else if(c != '8'|| c != '9')
                {
                  std::cin.unget();
                  write(octal,i);
                }
              else if(isdigit(c)) //zero
                {
                  std::cin.unget();
                  std::cin >> std::oct >> i;
                  write(octal,i);
                }
            }
          else if(isdigit(c))
            {
              std::cin.unget();
              std::cin >> std::dec >> i;
              write(decimal,i);
            }
        }
    }
  catch(std::runtime_error &e)
    {
      std::cout << "runtime error: " << e.what() << '\n';
    }
}
