#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include "Math.h"

namespace Math
{
  Rational::Rational(int n,int d)
    :numerator(n),denominator(d)
  {
    if(d == 0) // throw error for dividing by 0
      {
        throw std::runtime_error("Denomiator cannot be zero");
      }
    
    // simplify the fraction
    // get greatest common diviors then divde by both parts by it
    int div = gcd(numerator,denominator);
    numerator/= div;
    // std::cout << "numerator after simply in constructor: " << numerator << '\n';
    denominator/= div;
    // std::cout << "denominator after simply in constructor: " << denominator << '\n';
    
  }

  Rational::Rational()
    :numerator(1),denominator(1)
  {
  }

  void simplify(Rational& r)
  {
    int div = gcd(r.numerator,r.denominator);
    // std::cout << "div: " << div << '\n';
    r.numerator/= div;
    r.denominator/= div;
  }
  
  void normalize(Rational& l, Rational& r)
  {
    int new_denominator = l.denominator * r.denominator;
 
    l.numerator*= r.denominator;
    r.numerator*= l.denominator;

    l.denominator = r.denominator = new_denominator;
  }

  int gcd(int a,int b)
  {
    if (b == 0)
      {
        return abs(a);
      }
    return gcd(b, a%b);
  }
  double to_double(Rational x)	// convert to double (to floating point representation)
  {
	return double(x.numerator)/x.denominator;
  }


  Rational operator+(Rational l, Rational r)
  {
    Rational t;
    normalize(l,r); // get them with the same denominator
    // std::cout << "left numerator after normalize in + : " << l.numerator << '\n';
    // std::cout << "left denominator after normalize in + : " << l.denominator << '\n';

    // std::cout << "right numerator after normalize in + : " << r.numerator << '\n';
    // std::cout << "right denominator after normalize in + : " << r.denominator << '\n';
    t.numerator = l.numerator + r.numerator;
    t.denominator = l.denominator;
    // std::cout << "temp numerator after addition in + : " << t.numerator << '\n';
    // std::cout << "temp denominator after addition in + : " << t.denominator << '\n';
    simplify(t); 

    // std::cout << "temp numerator after simplify in + : " << t.numerator << '\n';
    // std::cout << "temp denominator after simplify in + : " << t.denominator << '\n';
    return t;
  }
  Rational operator-(Rational l,Rational r)
  {
    Rational t;
    normalize(l,r); // get them with the same denominator
    // std::cout << "left numerator after normalize in - : " << l.numerator << '\n';
    // std::cout << "left denominator after normalize in - : " << l.denominator << '\n';

    // std::cout << "right numerator after normalize in + : " << r.numerator << '\n';
    // std::cout << "right denominator after normalize in + : " << r.denominator << '\n';
    t.numerator = l.numerator - r.numerator;
    t.denominator = l.denominator;
    // std::cout << "temp numerator after minus in + : " << t.numerator << '\n';
    // std::cout << "temp denominator after minus in + : " << t.denominator << '\n';
    simplify(t); 

    // std::cout << "temp numerator after simplify in + : " << t.numerator << '\n';
    // std::cout << "temp denominator after simplify in + : " << t.denominator << '\n';
    return t;

  }
  Rational operator-(Rational r)
  {
    return Rational(-r.numerator,r.denominator);
  }

  Rational operator*(Rational l,Rational r)
  {
     Rational t;
    normalize(l,r); // get them with the same denominator
    // std::cout << "left numerator after normalize in + : " << l.numerator << '\n';
    // std::cout << "left denominator after normalize in + : " << l.denominator << '\n';

    // std::cout << "right numerator after normalize in + : " << r.numerator << '\n';
    // std::cout << "right denominator after normalize in + : " << r.denominator << '\n';
    t.numerator = l.numerator * r.numerator;
    t.denominator = l.denominator * r.denominator;
    // std::cout << "temp numerator after addition in + : " << t.numerator << '\n';
    // std::cout << "temp denominator after addition in + : " << t.denominator << '\n';
    simplify(t); 
    // std::cout << "temp numerator after simplify in + : " << t.numerator << '\n';
    // std::cout << "temp denominator after simplify in + : " << t.denominator << '\n';
    return t;
    

  }

  Rational operator/(Rational l,Rational r)
  {
     Rational t;
     // flip the numerator and denominator
     int temp = r.numerator;
     r.numerator = r.denominator;
     r.denominator = temp;
    // std::cout << "left numerator after normalize in + : " << l.numerator << '\n';
    // std::cout << "left denominator after normalize in + : " << l.denominator << '\n';

    // std::cout << "right numerator after normalize in + : " << r.numerator << '\n';
    // std::cout << "right denominator after normalize in + : " << r.denominator << '\n';
    t = l * r;
    // std::cout << "temp numerator after addition in + : " << t.numerator << '\n';
    // std::cout << "temp denominator after addition in + : " << t.denominator << '\n';
    simplify(t); 
    // std::cout << "temp numerator after simplify in + : " << t.numerator << '\n';
    // std::cout << "temp denominator after simplify in + : " << t.denominator << '\n';
    return t;

  }
  bool operator==(const Rational& l,const Rational& r)
  {
    return l.numerator == r.numerator && l.denominator == r.denominator;
  }

  bool operator!=(const Rational& l,const Rational& r)
  {
    return !(l==r);
  }
  std::ostream& operator<<(std::ostream& os,const Rational& r)
  {
    os << r.numerator << "/" << r.denominator;
    return os;

  }
}
