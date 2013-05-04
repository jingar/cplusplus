#include <iostream>

void ratio(double val1,double val2)
{
  std::cout << "Ratio is: " << (val1 / val2) << std::endl;
}

void product(double val1,double val2)
{
  std::cout << "Product is: " << (val1 * val2) << std::endl;
}

void difference(double val1,double val2)
{
  std::cout << "difference is: " << (val1 - val2) << std::endl;
}

void sum(double val1,double val2)
{
  std::cout << "Sum is: " << (val1 + val2) << std::endl;
}

void min(double val1,double val2)
{
    if(val1 < val2)
    {
      std::cout << "Min is " << val1 << std::endl;
    }
  else if(val2 < val1)
    {
      std::cout << "Min is " << val2 << std::endl;
    }
}

void max(double val1,double val2)
{
  if(val1 > val2)
    {
      std::cout << "Max is " << val1 << std::endl;
    }
  else if(val2 > val1)
    {
      std::cout << "Max is " << val2 << std::endl;
    }
}

int main()
{
  double input_1 = 0.0;
  double input_2 = 0.0;
  
  std::cout << "Enter the the first value" << std::endl;
  std::cin >> input_1;
  std::cout << "Enter the the second value" << std::endl;
  std::cin >> input_2;

  max(input_1,input_2);
  min(input_1,input_2);
  sum(input_1,input_2);
  difference(input_1,input_2);
  product(input_1,input_2);
  ratio(input_1,input_2);
}
