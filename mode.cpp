#include <iostream>
#include <vector>

void mode(std::vector<double> & v)
{
  int counter = 0;
  int mode = 0;
  for(unsigned int i = 0; i < v.size();i++)
    {
      int temp = v[i];
      int temp_count = 0;
	
	for(unsigned int j = 0; j < v.size();j++)
	  {
	    if(temp == v[j])
	      {
		temp_count++;
	      }
	  }
	if(temp_count > counter)
	  {
	    counter = temp_count;
	    mode = temp;
	  }
    }
  std::cout << "Mode is " << mode << " amount " << counter << std::endl;
}

void print(const std::vector<double> & v)
{
  for(unsigned int i = 0; i < v.size();i++)
    {
      std::cout << v[i] << "\n";
    }
}
int main()
{
  double temp = 0.0;
  std::vector <double> numbers;
  
  std::cout << "This program will find the mode of a sequence of numbers" 
	    <<" After entering the sequence enter a symbol that is not a number" << "\n";
  
  while(std::cin >> temp)
    {
      numbers.push_back(temp);
    }

  mode(numbers);
  print(numbers);
  return 0;
}
