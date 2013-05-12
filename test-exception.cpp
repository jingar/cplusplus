#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>

void error(std::string s1)
{
  throw std::runtime_error(s1);
}
//Just testing how when happens when you throw an exception
int main()
{
  //error("YOU SUCK!!");
}
