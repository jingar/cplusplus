#include <iostream>
#include <string>
#include <vector>
#include <sstream>
std::vector<std::string> split(const std::string& s)
{
  std::istringstream ss(s);
  std::vector<std::string> res;
  std::string buff;
  while(ss >> buff)
    {
      res.push_back(buff);
    }
  return res;
}
std::vector<std::string> split_with(const std::string& s,const std::string& w)
{
  std::size_t prev_pos = 0;
  std::size_t current_pos = 0;
  std::vector<std::string> result;
  while((current_pos = s.find_first_of(w,prev_pos)) != std::string::npos)
    {
      if(current_pos > prev_pos)
        {
          result.push_back(s.substr(prev_pos,current_pos-prev_pos));
        }
      prev_pos = current_pos + 1;
    }

  if(prev_pos < s.length())
    {
      result.push_back(s.substr(prev_pos,std::string::npos));
    }
  return result;
}
int main()
{
  std::string line;
  while(getline(std::cin,line))
    {
      std::vector<std::string> line_vec = split_with(line,"f");
      std::cout << "words in line:\n";
      for (unsigned int i=0; i<line_vec.size(); ++i)
        {
          std::cout << line_vec[i] << ' ';
        }
      std::cout << '\n';
    }
}
