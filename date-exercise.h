#include <iostream>
#include <stdexcept>
#include <vector>
namespace chrono
{
  class Date 
  {
  public:
    enum Month 
    {
      jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
    };
    class Invalid { };
    Date(int d, Month m, int y);
    Date();
    int day() const { return d; }
    Month month() const { return m; }
    int year() const { return y; }
    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
  private:
    int d;
    Month m;
    int y;
  };

  bool leapyear(int y);
  bool is_date(int d, Date::Month m, int y);
  bool operator==(const Date& a, const Date& b);
  bool operator!=(const Date& a, const Date& b);
  std::ostream& operator<<(std::ostream& os, const Date& d);
  std::istream& operator>>(std::istream& is, Date& dd);

  enum Day
  {
    sunday ,monday,tuesday,wednesday,thursday,friday,saturday
  };
  std::ostream& operator<<(std::ostream& os, Day& d)
    {
      std::cout << (int)d;
      return os;
    }
  Day operator++(Day& d)
  {
    d = (d == saturday)? sunday: Day(d+1);
    return d;
  }

  Date::Month& operator++(Date::Month& m)
  {
    m = (m == Date::dec)? Date::jan : Date::Month(m+1);
    std::cout << m << '\n';
    return m;
  }

  // chrono::Day next_sunday(const Date& d)
  // {

  // }
  
  int week_of_year(Date& d)
  {
    //first day of year is sunday
    //Week 1 starts at january 1st
    std::cout << "week of year \n";
    int days = 0;
    Date::Month current_month = Date::jan;
    while(d.month() != current_month)
      {
        switch(current_month)
          {
          case Date::feb:
            days+= (leapyear(d.year()))?29:28;  // if year is leapyear then 29 otherwise 28
            break;
          case Date::apr: case Date::jun: case Date::sep: case Date::nov:
            days+= 30; // if any of theese months, make it equal to 30 days
            break;
          case Date::jan: case Date::mar: case Date::may: case Date::jul: case Date::aug: 
          case Date::oct: case Date::dec:
              days+= 31;
              break;
          default:
            throw std::runtime_error("unknown month");
          }
        ++current_month;
        std::cout <<"date: month: " <<  d.month() << '\n';
        std::cout << '\n';
        std::cout << "current_month: " << current_month << '\n';
      }
    std::cout << "days after handling month: " << days << '\n';
    days+=d.day();
    std::cout << "days after adding days in current month: " << days << '\n';
    std::cout << "weeks: " << days / 7<< '\n';
    return days / 7;
  }
  

  Day int_to_day(int d)
  {
    if(d < sunday || d > saturday)
      {
        throw std::runtime_error("unregconized day in chrono::Day_to_int");
      }
    return chrono::Day(d);       
  }
  Day date_to_day(const Date& date)
  {
    std::vector<int> t = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int d = date.day();
    int m = date.month();
    int y = date.year();
    if(m < 3)
      {
        --y;
      }
    int result = (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
    return int_to_day(result);
  }


  Day next_weekday(const Date& date)
  {
    Day d = date_to_day(date);
    while(true)
      {
        if(d != sunday || d != saturday)
          {
            return d;
          }
        ++d;
      }
  }
}
