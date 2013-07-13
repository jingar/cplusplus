#include <iostream>
#include <string>
class Money
{
 public:
  Money(std::string currency,float money);
  Money(unsigned long int dollars, unsigned long int cents);
  Money(unsigned long int cents);
  unsigned long int get_dollars() const;
  unsigned long int get_cents()const ;
  unsigned long int get_money_in_cents()const;
  std::string currency;
 private:
  unsigned long int cents;

};

Money operator+(const Money& l,const Money& r);
Money operator-(const Money& l,const Money& r);
std::ostream& operator<<(std::ostream& osl,const Money& r);
