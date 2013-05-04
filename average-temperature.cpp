#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
  std::vector<double> temperatures;
  double temp = 0.0;
  double average = 0.0;
  std::cout << 9/2 << std::endl;

  while(std::cin >> temp)
    {
      temperatures.push_back(temp);
    }

  for(unsigned int i = 0; i < temperatures.size();i++)
    {
      average+= temperatures[i];
    }
  
  std::cout << "Average temperature is " << average/temperatures.size() << std::endl;

  std::sort(temperatures.begin(),temperatures.end());

  if((temperatures.size() % 2) == 0)
    {
      std::cout << "Is even " << std::endl;
      std::cout << "Median is " << (temperatures[temperatures.size()/2] + temperatures[(temperatures.size()/2)-1]) / 2 << std::endl;

    }
  else if((temperatures.size() % 2) != 0)
    {
      std::cout << "Is odd " << std::endl;
      std::cout << temperatures.size()/2 << std::endl;
      
      std::cout << "Median is " <<  temperatures[(temperatures.size()/2)] << std::endl;
    }

  return 0;

}
