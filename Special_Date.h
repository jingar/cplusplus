/* Date Repersentation is to keep days since 1 January 1970 (day 0) */
#include <iostream>
namespace Special_Date
{
  class Date  
  {
  public:
    Date(int l);
    int get_date() const; // return days
    void add_day(int n );
  private:
    long days;  
  };
  bool is_date(int n);
  bool operator==(const Date& l, const Date& r);
  bool operator!=(const Date& l, const Date& r);
  
  std::ostream& operator<<(std::ostream& os,const Date& d);
  std::istream& operator>>(std::istream& os,const Date& d);
}
