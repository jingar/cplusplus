#include <iostream>
#include <cstring>

int main()
{
  //char character = 'a';

  //print characters from a to z using while loop
  // while(character <= int('z'))
  //   {
  //     std::cout << character <<'\t' << int(character) << std::endl;
  //     ++character;
  //   }

  //i is initialized as integer value of 'a' and just make sure its less
  // than or equal to the integer value of 'z'
  for(int i = int('a'); i <= int('z'); i++)
    {
      std::cout << char(i) << '\t' << i <<  std::endl;
      
    }
}
