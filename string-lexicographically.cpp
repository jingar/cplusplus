#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

void print(const std::vector<std::string>& v)
{
  for(unsigned int i =0; i < v.size();++i)
    {
      std::cout << "v[" << i << "]: " << v[i] << '\n';
    }
}

std::string lexico_first(const std::vector<std::string>& s)
{
  std::vector<std::string> temp = s;
  std::sort(temp.begin(),temp.end());
  return temp.front();
}

std::string lexico_last(const std::vector<std::string>& s)
{
  std::vector<std::string> temp = s;
  std::sort(temp.begin(),temp.end());
  return temp.back();
}

std::string shortest_string(const std::vector<std::string>& s)
{
  std::string shortest = s[0];
  for(unsigned i = 1; i < s.size(); ++i)
    {
      if(s[i].size() < shortest.size())
        {
          shortest = s[i];
        }
    }
  return shortest;
}

std::string longest_string(const std::vector<std::string>& s)
{
  std::string longest = s[0];
  for(unsigned i = 1; i < s.size(); ++i)
    {
      if(s[i].size() > longest.size())
        {
          longest = s[i];
        }
    }
  return longest;
}

std::vector<int> count_chars(const std::vector<std::string>& s)
{
  std::vector<int> count;

  for(unsigned int i = 0; i < s.size();++i)
    {
      count.push_back((int)s[i].size());
      std::cout << count[i] << '\n';
    }
  return count;
}




int main()
{
  std::vector<std::string> words;

  std::string word;
  std::string line;
  std::getline(std::cin,line);
  std::istringstream iss(line);
  while(iss >> word)
    {
      words.push_back(word);
    }

  count_chars(words);
  std::cout << "longest: " << longest_string(words) << '\n';
  std::cout << "shortest: " << shortest_string(words) << '\n';
  std::cout << "lexico_first: " << lexico_first(words) << '\n';
  std::cout << "lexico_last: " << lexico_last(words) << '\n';
  std::cout << "finished \n";
  return 0;
}
