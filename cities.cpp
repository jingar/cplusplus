#include <iostream>
#include <vector>

double find_mean(const std::vector<double>& v)
{
  double mean = 0.0;
  for(unsigned int i = 0; i < v.size();i++)
    {
      mean+= v[i];
    }

  return mean/v.size();
}
double find_max(const std::vector<double>& v)
{
  double max = v[0];
  for(unsigned int i = 0; i < v.size();i++)
    {
      if(v[i] > max)
	{
	  max = v[i];
	}
    }

  return max;
}
double find_min(const std::vector<double>& v)
{
  double min = v[0];
  for(unsigned int i = 0; i < v.size();i++)
    {
      if(v[i] < min)
	{
	  min = v[i];
	}
    }

  return min;
}

double total_distance(const std::vector<double>& v)
{
  double total_distance = 0.0;
  for(unsigned int i = 0; i < v.size();i++)
    {
      total_distance+= v[i];
    }

  return total_distance;
}
int main()
{
  std::vector<double> distance_between_cities;
  double current = 0.0;

  std::cout << "Please enter distances between cities" << std::endl;

  while(std::cin >> current)
    {
      distance_between_cities.push_back(current);
    }
  if(distance_between_cities.size() > 0)
    {
      std::cout << "Total distance is " << total_distance(distance_between_cities) << std::endl;
      std::cout << "Largerst distance between neighbouring cities is " << find_max(distance_between_cities) << " and the smallest is " 
		<< find_min(distance_between_cities) << std::endl;

      std::cout << "The mean distance is " << find_mean(distance_between_cities) << std::endl;
      return 0;
    }
  else
    {
      std::cout << "You must enter at least one value" << std::endl;
      return -1;
    }
}
