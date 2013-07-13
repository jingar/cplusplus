#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <random>
#include <functional>
#include <chrono>
struct Reading
{
  int hour;
  double temperature;
  Reading(int h, int t)
    :hour(h),temperature(t){}

};


void print_readings(const std::vector<Reading>& r,std::ostream& os)
{
  for(unsigned int i = 0; i < r.size(); ++i)
    {
      os << r[i].hour << " " << r[i].temperature << '\n';
    }
}
void writing_temp_to_file(const std::vector<Reading>& r,const std::string& file_name)
{
  std::ofstream ofs(file_name.c_str());
  if(!ofs)
    {
      throw std::runtime_error("cannt not open file: " + file_name);
    }
  print_readings(r,ofs);

}

void initalize_temperatures(std::vector<Reading>& r,unsigned int number_of_temps)
{
  std::mt19937_64 generator(std::chrono::system_clock::now().time_since_epoch().count());
  std::uniform_real_distribution<float> uniform_distribution_temp(-274.0, 70.0);
  std::uniform_int_distribution<int> uniform_distribution_hour(0,23);

  auto rand_temp = std::bind(uniform_distribution_temp, generator);
  auto rand_hour = std::bind(uniform_distribution_hour, generator);

  double scale_temp = 0.1;
  double scaled_random_number = 0.0;

  for(unsigned int i = 0; i < number_of_temps; ++i)
    {
      scaled_random_number = ((int)(rand_temp()/scale_temp))*scale_temp;
      r.push_back(Reading(rand_hour(),scaled_random_number));
    }
}
int main()
{
  std::vector<Reading> readings;
  initalize_temperatures(readings,50);
}
