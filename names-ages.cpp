#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void take_names(std::vector<std::string>& v)
{
  std::cout << "Enter each name followed by a space \n";
  std::string name;
  std::string line;
  std::getline(std::cin,line);
  std::istringstream iss(line);
  while(iss >> name)
    {
      v.push_back(name);
    }
  std::cout << "finished \n";
}

void take_ages(std::vector<int>& v)
{
  std::cout << "Enter each age followed by a space \n";
  int age;
  std::string line;
  std::getline(std::cin,line);
  std::istringstream iss(line);
  while(iss >> age)
    {
      v.push_back(age);
    }
  std::cout << "finished \n";
}
int find_string(std::string s,const std::vector<std::string>& v)
{
  for(unsigned int i = 0; i < v.size();++i)
    {
      if(v[i] == s)
        {
          return i;
        }
    }
  return -1;
}

void print_name_age_pairs(std::vector<std::string>& names, const std::vector<int>& ages)
{
  std::vector<std::string> temp_names = names;
  std::sort(names.begin(),names.end());
  for(unsigned int i  = 0; i < names.size();++i)
    {
      int indice = find_string(names[i],temp_names);
      if(indice != -1)
        {
          std::cout << "name: " << names[i] << " age: " << ages[indice] << '\n';
        }
    }
}

int main()
{
  std::vector<std::string> names;
  std::vector<int> ages;

  take_names(names);
  take_ages(ages);
  print_name_age_pairs(names,ages);
  return 0;

}
