#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
#include <cstdlib>
#include <vector>


int main()
{
  try 
    {
      
      return 0;
    }
  catch(std::exception& e) 
    {
      std::cerr << "error: " << e.what() << '\n';
      return 1 ;
    }
  catch (...) 
    {
      std::cerr << "Oops: unknown exception !\n " ;
      return 2;
    }
}
