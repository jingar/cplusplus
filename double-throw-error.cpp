#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stdexcept>
#include <cctype>


void error(const std::string& s)
{
  throw std::runtime_error(s);
}

void error(const std::string& s, const std::string& s2)
{
  error(s+s2);
}

double test()
{
  double d;
  std::cin >> d;
  if(d == 4.0)
    {
      return d;
    }
   
  error("error");
}
int main()
{
  double t = test;
  t = sqrt(t);
  return t;
}
