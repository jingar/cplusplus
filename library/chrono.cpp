#include "chrono.h"
#include <stdexcept>
namespace chrono 
{
  Date::Date(int dd,Month mm, int yy)
    :d(dd),m(mm),y(yy)
  {
    if(!is_date(dd,mm,yy))
      {
        throw Invalid();
      }
  }
  Date& default_date()
  {
    static Date dd(1,Date::jan,2001);
    return dd;
  }
  
  Date::Date()
    :d(default_date().day()),m(default_date().month()),y(default_date().year())
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

  bool is_date(int d, Date::Month m, int y)
  {
    std::cout << "Days: " << d << '\n';
    // assume that y is valid
    
    if(d<=0) // day must be positive
      {
        std::cout << "day less than 0 \n";
        return false;
      }
    int days_in_month = 0;
    switch(m)
      {
      case Date::feb:
        days_in_month = (leapyear(y))?29:28;  // if year is leapyear then 29 otherwise 28
        break;
      case Date::apr: case Date::jun: case Date::sep: case Date::nov:
        days_in_month = 30; // if any of theese months, make it equal to 30 days
        break;
      case Date::jan: case Date::mar: case Date::may: case Date::jul: case Date::aug: 
      case Date::oct: case Date::dec:
        days_in_month = 31;
        break;
      default:
        throw std::runtime_error("unknown month");
      }
    if(d > days_in_month)
      {
        std::cout << "day is greater than days in the month \n";
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
    return a.day() == b.day() && a.month() == b.month() && a.year() == b.year();
  }

  bool operator!=(const Date& a, const Date& b)
  {
    return !(a==b);
  }

  std::ostream& operator<<(std::ostream& os,const Date& d)
  {
    return os << '(' << d.day() << ',' << d.month() << ',' << d.year() << ')';
  }

  std::istream& operator>>(std::istream& is, Date& dd)
  {
    int y,m,d;
    char ch1, ch2, ch3, ch4;
    is >> ch1 >> d >> ch2 >> m >> ch3 >> y >> ch4;
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

  enum Day
    {
      sunday,monday,tuesday,wednesday,thursday,friday,saturday
    };

  // Day day_of_week(const Date& d)
  // {

  // }
  // Day next_sunday(const Date& d)
  // {

  // }

  // Day next_weekday(const Date& d)
  // {

  // }
}
