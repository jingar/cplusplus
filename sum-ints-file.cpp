#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>


int sum_file(std::string file_name)
{
  std::ifstream file_in_stream(file_name.c_str());
  //file_in_stream.exceptions(file_in_stream.exceptions()| std::ios_base::badbit);
  if(!file_in_stream)
    {
      throw std::runtime_error("error file could not be opened: " + file_name);
    }
  int sum = 0;
  int number;

  while(file_in_stream >> number)
    {
      std::cout << "in here \n";
      sum+=number;
    }


  if(file_in_stream.eof())
    {
      return sum;
    }
  if(file_in_stream.fail())
    {
      throw std::runtime_error("failed to read file");
    }
}


int main()
{
  try
    {
      std::cout << "Enter a file name \n";
      std::string file_name;
      std::cin >> file_name;
      std::cout << sum_file(file_name) << '\n';
    }
  catch(std::runtime_error& e)
    {
      std::cerr << "run time error: " << e.what() << '\n';
    }

}
