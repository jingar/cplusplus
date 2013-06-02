#include <fstream>

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>



int main()
{
  std::ofstream outputFile("words.txt");
  std::vector<std::string> word_list;
  std::ifstream word_file("test-word.txt");
  std::string current_word;
  
  if(!word_file.is_open())
    {
      std::cerr << "Couldn't open the file words.txt \n";
    }

  while(word_file >> current_word)
    {
      word_list.push_back(current_word);
    }

  std::string temp;
  
  for(unsigned int i = 0 ; i < word_list.size();++i)
    {
      temp = word_list[i];
      if(temp.size() < 3)
	{
	  word_list.erase(word_list.begin()+i);
	}
    }

  for(unsigned int i = 0 ; i < word_list.size();++i)
    {
      outputFile << word_list[i] << '\n';
    }
  return 0;
}
