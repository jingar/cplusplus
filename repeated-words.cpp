#include <iostream>
#include <string>
using namespace std;
int main()
{
  string previous = "";
  string current;
  int position = 1;

  while(std::cin >> current)
    {
      if(current == previous)
	{
	  std::cout << "repeated word: " << current 
		    << ", at position: " << position << std::endl;
	}
      previous = current;
      position++;
    }

}
