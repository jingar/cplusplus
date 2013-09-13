#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdio>
#include <cctype>
#include <sstream>
int main()
{
  std::cin.unsetf(std::ios::dec);	// see page 380
  std::cin.unsetf(std::ios::oct);
  std::cin.unsetf(std::ios::hex);
  char ch;
  int x;
  std::cout << std::showbase;	// see page 378
  while (std::cin.get(ch)) {
    if(ch=='0') {
      std::cin.get(ch);
      if (ch=='x' || ch=='X') {	// read hexadecimal
        std::cin>>std::hex>>x;
        std::cout << std::hex << '\n';
      }
      else if (isdigit(ch)) {	// read octal
        std::cin.unget();	// put character back
        std::cin>>std::oct>>x;
        std::cout << std::oct << '\n';
      }
      else {	// it was plain 0
                // 0 is an octal number (really!)
        std::cin.unget();	// put character back
        std::cout << std::oct << '\n';
      }
    }
    else if (isdigit(ch)) {	// read decimal
      std::cin.unget();	// put character back
      std::cin>>std::dec>>x;
      std::cout << std::dec << '\n';
          
    }
  }
  return 0;
}

