#include <iostream>

int main()
{
  double d =0;
  while (std::cin>>d) 
    {
      // repeat the statements below
      // as long as we type in numbers
      int i = d;
      // try to squeeze a double into an int
      char c = i;
      // try to squeeze an int into a char
      int i2 = c;
      // get the i nteger va lue of the character
      std::cout << "d==" << d
	// the original double
		<< " i="<< i
	// converted to int
		<< " i2=" << i2
	// int value of char
		<< " char(" << c << ")\n"; // the chcl r
    }
  // char is singed from -128 to 127

}
