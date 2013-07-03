#include <iostream>
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

  bool is_date(int d, Date::Month m, int y);
  bool leapyear(int y);
  bool operator==(const Date& a, const Date& b);
  bool operator!=(const Date& a, const Date& b);
  std::ostream& operator<<(std::ostream& os, const Date& d);
  std::istream& operator>>(std::istream& is, Date& dd);
}
