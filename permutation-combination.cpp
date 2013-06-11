#include <iostream>
#include <stdexcept>
unsigned int factorial(unsigned int number)
{
  unsigned int answer = 1;
  for(unsigned int i = 1; i <= number;++i)
    {
      answer*=i;
    }
  return answer;
}
int permutation(unsigned int a, unsigned int b)
{
  if(a <= 0 || b <=0)
    {
      throw std::runtime_error("Input must be greater than 0");
    }
  return factorial(a)/factorial(a-b);
}

int combination(unsigned int a, unsigned int b)
{
  if(a <= 0 || b <=0)
    {
      throw std::runtime_error("Input must be greater than 0");
    }
  int p = permutation(a,b);
  return p/factorial(b);
}

int main()
{
  std::cout << "This program calculates Permuatation or Combination \n";
  std::cout << "Enter P for Permutation or C or Combination \n";
  
  char c;
  std::cin >> c;

  std::cout << "Enter two numbers, first number is different possible options \n";
  std::cout << "Enter second number,number how many options you can pick at a time \n";
  int f,s;
  std::cin >> f >> s;

  if(!std::cin)
    {
      std::cout << "You must enter two numbers \n";
      return -1;
    }
  switch(c)
  {
  case 'P':
    std::cout << permutation(f,s) << '\n';
    break;
  case 'C':
    std::cout << combination(f,s) << '\n';
    break;
  default:
    std::cout << "Unrecognized input: " << c << '\n';
  }

  return 1;
}
