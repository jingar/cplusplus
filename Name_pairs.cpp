#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class Name_age_pair
{
public:
  Name_age_pair();
  void read_names();
  void read_ages();
  void sort();
  std::vector<double> get_ages();
  std::vector<std::string> get_names();
private:
  bool enough_ages();
  std::vector<std::string> names;
  std::vector<double> ages; 
};


std::vector<double> Name_age_pair::get_ages()
{

  return ages;
}

std::vector<std::string> Name_age_pair::get_names()
{
  return names;
}

Name_age_pair::Name_age_pair()
  :names(),ages()
{
}

bool Name_age_pair::enough_ages()
{
  return (ages.size() != names.size())? false: true;
}

void Name_age_pair::read_names()
{
  std::cout << "please provide a set of names seperated by spaces " << '\n';
  std::string name;
  std::string line;
  std::getline(std::cin,line);
  std::istringstream iss(line);
  while(iss >> name)
    {
      names.push_back(name);
    }
  std::cout << "finished names \n";
}

void Name_age_pair::read_ages()
{
  std::cout << "please provide a set of ages seperated by spaces " << '\n';
  int age;
  std::string line;
  std::getline(std::cin,line);
  std::istringstream iss(line);
  while(ages.size() <= names.size() && iss >> age ) 
    // only read in same amount of ages as names
    {
      ages.push_back(age);
    }
  std::cout << "finished ages \n";
}

std::ostream& operator<<(std::ostream& os, Name_age_pair& n)
{
  std::vector<std::string> names = n.get_names();
  std::vector<double> ages = n.get_ages();
  for(unsigned int i  = 0; i < names.size();++i)
    {
      std::cout << "name: " << names[i] << " age: " << ages[i] << '\n';
    }
  return os;
}

bool operator==(Name_age_pair l , Name_age_pair r) 
{
  std::vector<std::string> left_names = l.get_names();
  std::vector<double> left_ages = l.get_ages();
  
  std::vector<std::string> right_names = r.get_names();
  std::vector<double> right_ages = r.get_ages();

  if(left_names.size() != right_names.size() || right_names.size() != right_ages.size())
    {
      return false;
    }
  for(unsigned int i = 0; i < left_names.size(); ++i)
    {
      if(left_names[i] != right_names[i])
        {
          return false;
        }
    }

    for(unsigned int i = 0; i < left_ages.size(); ++i)
    {
      if(left_ages[i] != right_ages[i])
        {
          return false;
        }
    }
    return true;
}

bool operator!=(Name_age_pair l , Name_age_pair r) 
{
  return !(l==r);
}
int main()
{
  Name_age_pair n;

  n.read_names();
  n.read_ages();

  std::cout << n << '\n';
  Name_age_pair s;

  s.read_names();
  s.read_ages();
  std::cout << s << '\n';

  if(s == n)
    {
      std::cout << "they are equal \n";
    }
  else
    {
      std::cout << "they are not equal \n";
    }
  return 0;
}
