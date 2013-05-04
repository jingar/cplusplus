#include <iostream>

int main ()
{
  //a mile in kilometers
  double mile = 1.609;
  //initialise user input
  double user_miles = 0.0;

  std::cout << "This program converts miles to km" << std::endl;
  std::cout << "Please enter number of miles" << std::endl;
  std::cin >> user_miles;
  std::cout << user_miles * mile << " km" << std::endl;
  
  
}
