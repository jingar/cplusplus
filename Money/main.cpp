#include "money.h"


int main()
{
  Money m(123);
  std::cout << m << '\n';

  Money m1(1,23);
  std::cout << m1 << '\n';

  Money test = m + m1;
  std::cout << test << '\n';

  Money test1 = m - m1;
  std::cout << test1 << '\n';
}
