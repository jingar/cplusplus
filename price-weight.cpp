#include <iostream>
#include <vector>
#include <stdexcept>


void calculate_cost(const std::vector<double>& prices, std::vector<double>& weights)
{
  if(weights.size() > prices.size())
    {
      throw std::runtime_error("you must have less weights or equal to the amount of prices");
    }
  for(unsigned int i = 0; i < weights.size();++i)
    {
      std::cout << weights[i] * prices[i] << '\n';
    }

}

int main()
{
  try
    {
      std::vector<double> prices = {1.0,2.0,3.0,4.0};
      std::vector<double> weights = {1.0,2.0,3.0,4.0};

      calculate_cost(prices,weights);
      
      return 0;
    }
  catch(std::runtime_error& e)
    {
      std::cerr << "runtime error: " << e.what() << '\n';
    }
}

