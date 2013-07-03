#include <iostream>
#include <stdexcept>
namespace Months
{
  enum Month
    {
      jan = 1, feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec
    };
  Month& operator++(Month& m)
  {
    m = (m==dec)?jan:Month(m+1);
    return m;
  }

  bool operator<  (Enum ee) const;
  bool operator<= (Enum ee) const;
  bool operator>  (Enum ee) const;
  bool operator>= (Enum ee) const;
  bool operator== (const Enum ee) const;
  bool operator!= (const Enum ee) const;

}

class Date
{
public:
  Date(int y,Months::Month m,int d);
  void add_day(int n);
  int year() { return y; }
  Months::Month month() { return m; }
  int day() { return d; }
private:
  int y;
  Months::Month m;
  int d;
};

Date::Date(int yy,Month mm, int dd)
  :y(yy),m(mm),d(dd)
{
  if(m <=0 || m > 12)
    {
      throw std::runtime_error("month must be between 1 and 12");
    }
  if(d > 31 || d <= 0)
    {
      throw std::runtime_error("day must be greater than 0 and less than or equal to 31");
    }
  if(y < 0)
    {

      throw std::runtime_error("year must be greater than 0");
    }
}


// void Date::add_day(int n)
// {
//   switch(m)
//     {
//     case jan:
//     case mar:
//     case may:
//     case jul:
//     case aug:
//     case oct:
//     case dec:
//       break;
//     case apr:
//     case jun:
//     case sep:
//     case nov:
//       break;
//     case feb:
//       break;
//     default:
//       throw std::runtime_error("unrecognized month");
//     }

// }
int main()
{

  // Date today(1978,Date::Month(1),31);
  // std::cout << "Year: " << today.year() << " Month: " << today.month() 
  //           << " Day: " << today.day() << '\n';

  // today.add_day(20);

  // std::cout << "Year: " << today.year() << " Month: " << today.month() 
  //           << " Day: " << today.day() << '\n';
  return 0;
}
