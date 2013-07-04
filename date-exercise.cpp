#include "chrono.h"
#include <stdexcept>
#include <vector>

namespace chrono 
{
  Date::Date(int yy,Month mm, int dd)
    :y(yy),m(mm),d(dd)
  {
    if(!is_date(yy,mm,dd))
      {
        throw Invalid();
      }
  }
  Date& default_date()
  {
    static Date dd(2001,Date::jan,1);
    return dd;
  }
  
  Date::Date()
    :y(default_date().year()),m(default_date().month()),d(default_date().day())
  {
  }

  // void Date::add_day(int n)
  // {
  // }

  // void Date::add_month(int n)
  // {
  // }

  void Date::add_year(int n)
  {
    if(m == feb && d == 29 && !leapyear(y+n))
      {
        m = mar;
        d = 1;
      }
    y+=n;
  }

  bool is_date(int y, Date::Month m, int d)
  {
    // assume that y is valid
    
    if(d<=0) // day must be positive
      {
        std::cout << "day is less than or equal to 0 \n";
        return false;
      }
    int days_in_month = 31; // most months have 31 days
    switch(m)
      {
      case Date::feb:
        days_in_month = (leapyear(y))?29:28;  // if year is leapyear then 29 otherwise 28
        break;
      case Date::apr: case Date::jun: case Date::sep: case Date::nov:
        days_in_month = 30; // if any of theese months, make it equal to 30 days
        break;
      }
    if(d > days_in_month)
      {
        std::cout << "day is the month are more then possible \n";
        return false;
      }
    return true;
  }

  bool leapyear(int y)
  {
    // if a year is evenly divisble by a 100 it must also be evely divisble by
    // 400 to be a leap year other wise it must be evenly divisble by 4
    if((y  % 100 == 0 && y % 400 == 0 )|| y % 4 == 0)
      {
        return true; // for now
      }
    return false;
  }

  bool operator==(const Date& a, const Date& b)
  {
    // check if the year months and days match
    return a.year() == b.year() && a.month() == b.month() && a.day() == b.day();
  }

  bool operator!=(const Date& a, const Date& b)
  {
    return !(a==b);
  }

  std::ostream& operator<<(std::ostream& os,const Date& d)
  {
    return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
  }

  std::istream& operator>>(std::istream& is, Date& dd)
  {
    int y,m,d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
    if(!is)
      {
        return is;
      }
    if(ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
      {
        is.clear(std::ios_base::failbit);
        return is;
      }
    return is;
  }

}
