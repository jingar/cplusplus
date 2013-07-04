#include "Special_Date.h"
#include <stdexcept>
namespace Special_Date
{
  Date::Date(int l)
    :days(l)
  {
    if(!is_date(l))
      {
        throw std::runtime_error("invalid date");
      }
  }

  int Date::get_date() const
  {
    return days;
  }

  void Date::add_day(int n)
  {
    if(n < 0)
      {
        throw std::runtime_error("you can add a negative day");
      }
    days+=n;
  }
  bool is_date(int l)
  {
    if(l < 0)
      {
        return false;
      }
    return true;
  }


  bool operator==(const Date& l, const Date& r)
  {
    return l.get_date() == r.get_date();
  }
  bool operator!=(const Date& l, const Date& r)
  {
    return !(l==r);
  }
  
  std::ostream& operator<<(std::ostream& os,const Date& d)
  {
    std::cout << d.get_date() << '\n';
    return os;
  }
  std::istream& operator>>(std::istream& is,Date& d)
  {
    int n;
    is >> n;
    if(n < 0)
      {
        is.clear(std::ios_base::failbit);                    // set the fail bit
        return is;
      }
    d = Date(n);
    return is;
  }




}
