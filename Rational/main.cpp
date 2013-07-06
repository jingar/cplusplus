//#include <boost/lexical_cast.hpp>
#include "Math.h"
#include <iostream>
#include <stdexcept>
int main(int argc,char* argv[])
{
  try
    {
      Math::Rational r1(4,2);
      std::cout << r1 << "==" << Math::to_double(r1) << '\n';
      Math::Rational r2(42,24);
      std::cout << r2 << "==" << Math::to_double(r2) <<'\n';
      std::cout << r1+r2 << "==" << Math::to_double(r1+r2) << "==" << Math::to_double(r1)+Math::to_double(r2) << '\n';
      std::cout << r1-r2 << "==" << Math::to_double(r1-r2) << "==" << Math::to_double(r1)-Math::to_double(r2) << '\n';
      std::cout << -r2 << "==" << Math::to_double(-r2) << "==" << -Math::to_double(r2) << '\n';
      std::cout << r1*r2 << "==" << Math::to_double(r1*r2) << "==" << Math::to_double(r1)*Math::to_double(r2) << '\n';
      std::cout << r1/r2 << "==" << Math::to_double(r1/r2) << "==" << Math::to_double(r1)/Math::to_double(r2) << '\n';
      if (r2==Math::Rational(14,8))
        {
          std::cout << "equal\n";
        }
      if (r2!=Math::Rational(14,8))
        {
          std::cout << "not equal\n";
        }
      // Math::Rational(3,0);	// we're out of here!
    }
  catch(std::runtime_error& e)
    {
      std::cerr << e.what() << '\n';
    }
    catch(...)
    {
      std::cout << "unexpected error \n";
    }
}
