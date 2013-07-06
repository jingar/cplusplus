#include <iostream>
namespace Math
{
  class Rational
    {
    public:
      Rational(int n, int d);
      Rational();
      int numerator;
      int denominator;
    };

  void simplify(Rational& r); // simplify the fraction
  void normalize(Rational& l,Rational& r); // transfor both fractions so they have both the same denominator
  int gcd(int a,int b); // find the greatest common divisor
  double to_double(Rational x); // return a double repersentation of a Rational
  //operator overloading
  Rational operator+(Rational l,Rational r);
  Rational operator-(Rational l,Rational r);
  Rational operator-(Rational r); // unary minus
  Rational operator*(Rational l,Rational r);
  Rational operator/(Rational l,Rational r);
  bool operator==(const Rational& l,const Rational& r);
  bool operator!=(const Rational& l,const Rational& r);
    std::ostream& operator<<(std::ostream& os,const Rational& r);

}
