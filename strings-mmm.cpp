#include <iostream>
#include <string>
#include <vector>


void mode(const std::vector<std::string>& w)
{
  int counter = 0;
  std::string word = "";
  for(unsigned int i = 0; i<w.size();i++)
    {

      int temp_counter = 0;
      for(unsigned int j =0; j < w.size();j++)
	{
	  if(w[i] == w[j])
	    {
	      temp_counter++;
	    }
	}
      if(temp_counter > counter)
	{
	  word = w[i];
	  counter = temp_counter;
	}
    }
  std::cout << "The mode is " << word << " Seen: " << counter << std::endl;
}
void max_size(const std::vector<std::string>& w)
{
  unsigned int max_size = w[0].length();
  std::string max_word = w[0];
  for(unsigned int i = 1; i < w.size();i++)
    {
      
      if(w[i].length() > max_size)
	{
	  max_size = w[i].length();
	  max_word = w[i];
	}
    }
  std::cout << "The Maximum sized word is " << max_word << ", Size: " << max_size << std::endl;
}


void min_size(const std::vector<std::string>& w)
{
  unsigned int min_size = w[0].length();
  std::string min_word = w[0];
  for(unsigned int i = 1; i < w.size();i++)
    {
      
      if(w[i].length() < min_size)
	{
	  min_size = w[i].length();
	  min_word = w[i];
	}
    }
  std::cout << "The Minumum sized word is " << min_word << ", Size: " << min_size << std::endl;
}

int main()
{
  std::string word = "";
  std::vector<std::string> words;
  
  while(std::cin >> word)
    {
      words.push_back(word);
    }
  
  min_size(words);
  max_size(words);
  mode(words);
  return 0;
}
