#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>


class Random_number_generator
{
private:
  unsigned long int seed = 1;
  const int multiplier = 16807;
  const int increment = 12345;
  const long modulus = pow(2,32)-1;
public:
  Random_number_generator(int new_seed);
  unsigned int next_number();
 
}; 

Random_number_generator::Random_number_generator(int new_seed)
{
  seed = (unsigned)new_seed;
}

unsigned int Random_number_generator::next_number()
{
  seed = ((multiplier*seed) + increment) % modulus;
  return (unsigned int)seed;
}



int main()
{
  srand((unsigned int)time(NULL));
  std::cout << rand() %10 + 1 << std::endl;
  Random_number_generator r((unsigned int)time(NULL));
  int random_number = r.next_number() % 10 + 1;
  std::cout << random_number << std::endl;
  return 0;
}
