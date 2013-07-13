#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

const int not_a_reading = -7777;
const int not_a_month = -1;

std::vector<std::string> month_input_table;

int month_to_int(std::string s)
{
  // std::cout << "month to int: " << s << '\n';

  for(int i = 0; i < 12; ++i)
    {
      //std::cout << "month_input_table: " << month_input_table[i] << '\n';
      if(month_input_table[i] == s)
        {
          return i;
        }
    }
  return -1;
}
// look for terminating character
void end_of_loop(std::istream& is, char term, const std::string& message)
{
  if(is.fail())
    {
      is.clear();
      char ch;
      if(is >> ch && ch == term)
        {
          return;
        }
      throw std::runtime_error(message);
    }
}
struct Day
{
  std::vector<double> hour;
  Day()
    :hour(24,not_a_reading){}
};

struct Month
{
  int month;
  std::vector<Day> day;
  Month()
  :month(not_a_month),day(32){}
};

struct Year
{
  int year;
  std::vector<Month> month;
  Year()
    :year(0),month(12){};
};

struct Reading
{
  int day;
  int hour;
  double temperature;
};

const int implausible_min = -200;
const int implausible_max = 200;

bool is_valid(const Reading& r)
{
  if(r.day < 1 || 31 < r.day)
    {
      return false;
    }
  if(r.hour < 0 || 23 < r.hour)
    {
      return false;
    }
  if(r.temperature < implausible_min || implausible_max < r.temperature)
    {
      return false;
    }
  return true;
}

std::istream& operator>>(std::istream& is, Reading& r)
{
  //std::cout << "reading \n";
  char first_bracket = 0;
  if(is >> first_bracket && first_bracket != '(')
    {
      is.unget();
      is.clear(std::ios_base::failbit);
      return is;
    }
  //std::cout << "found first bracket \n";
  int d;
  int h;
  double t;
  char right_bracket;
  is >> d >> h >> t >> right_bracket;
  std::cout << d << ": " << h << ": " << t << ": " << right_bracket << '\n';
  if(!is || right_bracket != ')')
    {
      throw std::runtime_error("bad reading");
    }
  r.day = d;
  r.hour = h;
  r.temperature = t;
  //std::cout << "end reading \n";
  return is;
}

std::istream& operator>>(std::istream& is, Month& m)
{
  //std::cout << "month \n";
  char left_brace = ' ';
  //std::cout << "aftet left brace initailization";
  if(is >> left_brace && left_brace != '{')
    {
      is.unget();
      is.clear(std::ios_base::failbit);
      return is;
    }
  //std::cout << "found left brace\n";
  std::string month_marker;
  std::string mm;
  is >> month_marker >> mm;
  std::cout << "month marker: " << month_marker << " month: " << mm << '\n';
  if(!is || month_marker != "month")
    {
      throw std::runtime_error("bad start of month");
    }
  // std::cout << "end month marker and month \n";
  m.month = month_to_int(mm);
  std::cout << "month value: " << m.month  << '\n';
  Reading r;
  int duplicates = 0;
  int invalids = 0;
  while(is >> r)
    {
      if(is_valid(r))
        {
          if(m.day[r.day].hour[r.hour] != not_a_reading)
            {
              ++duplicates;
            }
          m.day[r.day].hour[r.hour] = r.temperature;
        }
      else
        {
          ++invalids;
        }
    }
   if(invalids)
     {
       throw std::runtime_error("invalid readings in month " + invalids);
     }
   if(duplicates)
     {
       throw std::runtime_error("duplicates readings in month " + duplicates);
     }
   end_of_loop(is,'}',"bad end of month");
   //std::cout << "end month \n";
   return is;
}

std::istream& operator>>(std::istream& is, Year& y)
{
  //std::cout << "year \n";
  char left_brace;
  is >> left_brace;
  if(left_brace != '{')
    {
      is.unget();
      is.clear(std::ios::failbit);
      return is;
    }
  std::string year_marker;
  int yy;
  is >> year_marker >> yy;
  if(!is || year_marker != "year")
    {
      throw std::runtime_error("bad start of year");
    }
  y.year = yy;

  while(true)
    {
      Month m;
      if(!(is >> m))
        {
          break;
        }
      //std::cout << "m.month " << m.month << '\n';
      y.month[m.month] = m;
    }
  end_of_loop(is,'}',"bad end of year");
  //std::cout << "end year \n";
  return is;

}

void init_input_table(std::vector<std::string>& table)
{
  table.push_back("jan");
  table.push_back("feb");
  table.push_back("mar");
  table.push_back("apr");
  table.push_back("may");
  table.push_back("jun");
  table.push_back("jul");
  table. push_back("aug");
  table. push_back("sep");
  table.push_back("oct");
  table.push_back("nov");
  table.push_back("dec");
}

void print_day(std::ostream& os,const Day& d)
{
  for(unsigned int i = 0; i < d.hour.size();++i)
    {
      if(d.hour[i] != not_a_reading)
        {
          os << "hour: " << i  << " temperature: "
             << d.hour[i] << '\n';
        }
    }
}

void print_month(std::ostream& os,const Month& m)
{
  if(m.month != not_a_month)
    {
      os << "Month: " << m.month << '\n';
    }
  
  for(unsigned int i = 0; i < m.day.size();++i)
    {     
      print_day(os,m.day[i]);
    }
}

void print_year(std::ostream& os,const Year& y)
{
  os << "Year: " << y.year << '\n';
 
  for(unsigned int i = 0; i < y.month.size();++i)
    {
      print_month(os,y.month[i]);
    }
}

int main()
{
  std::cout << "Please enter the input file name \n";
  std::string file_name;
  std::cin >> file_name;
  std::ifstream ifs(file_name.c_str());
  ifs.exceptions(ifs.exceptions()|std::ios_base::badbit);

  init_input_table(month_input_table);
  std::vector<Year> years;
  while(true)
    {
      Year y;
      if(!(ifs >> y))
        {
          break;
        }
        years.push_back(y);
    }

  for(unsigned int i =0; i < years.size();++i)
    {
      print_year(std::cout,years[i]);
    }
 
}
 
 
 
