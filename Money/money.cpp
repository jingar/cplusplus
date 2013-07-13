#include "money.h"


Money::Money(unsigned long int d, unsigned long int c)
  :cents(c)
{
  cents+= (d*100); // convert dollars into cents
}

Money::Money(unsigned long int c)
  :cents(c)
{
}

unsigned long int Money::get_dollars() const
{
  return cents/100;

}
unsigned long int Money::get_cents() const 
{
  return cents % 100;
}

unsigned long int Money::get_money_in_cents() const
{
  return cents;
}

Money operator+(const Money& l,const Money& r)
{
  // std::cout << "left cents: "  << l.get_cents() << '\n';
  // std::cout << "right cents: "  << r.get_cents() << '\n';
  // std::cout << "left + right: "  << l.get_cents() + r.get_cents() << '\n';
  return Money(l.get_money_in_cents() + r.get_money_in_cents());
}
Money operator-(const Money& l,const Money& r)
{
  return Money(l.get_cents() - r.get_cents());
}

std::ostream& operator<<(std::ostream& os,const Money& r)
{
  std::cout << r.get_dollars() << "." << r.get_cents();
  return os;
}


