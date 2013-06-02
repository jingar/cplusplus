#include <iostream>
#include <string>
#include <vector>
#include <limits>



bool name_unique(const std::vector<std::string>& names,std::string name)
{
  for(unsigned int i = 0; i < names.size(); i++)
    {
      if(names[i] == name)
	{
	  std::cout << "Not unique" << std::endl;
	  return false;
	}
    }
  return true;
}
void print_name_scores(const std::vector<std::string>& names,const std::vector<int>& scores)
{
  for(unsigned int i = 0; i < names.size();i++)
    {
      std::cout << names[i] << ": " << scores[i] << "\n";
    }
}
void find_score_by_name(const std::vector<std::string>& names,const std::vector<int>& scores, std::string name)
{
  for(unsigned int i = 0; i < names.size();i++)
    {
      if(names[i] == name)
	{
	  std::cout << name << " has the score " << scores[i] << std::endl;
	  return;
	}
    }
  std::cout << name << " not found " << std::endl;
  
}


void insert_data(std::vector<std::string>& names, std::vector<int>& scores)
{
  std::string name = "";
  int score = 0;
  std::cout << "Please enter a name followed by space and then the person's score" << std::endl;
  while(std::cin >> name >> score && name != "Nomore")
    {
      if(name_unique(names,name))
	{
	  names.push_back(name);
	  scores.push_back(score);
	}
    }
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


void find_all_scores(const std::vector<std::string>& names, const std::vector<int>& scores,int score)
{
  bool found = false;
  for(unsigned int i = 0; i <scores.size();i++)
p    {
      if(scores[i] == score)
	{
	  std::cout << names[i] << "\n";
	  found = true;
	}
    }
  if(!found)
    {
      std::cout << "Score not found "<< std::endl;
    }
}
void display_commands()
{
  std::cout << "Insert - Insert data \n"
	    << "FindScore -Find score by name \n"
	    << "Print - Print all names and scores \n"
	    << "FindAllScores - Find all names associated with a score \n"
	    << "Help - Display all commands \n"
	    << "Quit - Quit the program" << std::endl;
}
int main()
{
  std::string user_input = "";
  std::vector<std::string> names;
  std::vector<int> scores;
  
  display_commands();
  while(std::cin >> user_input)
    {
      if(user_input == "Insert")
	{
	  insert_data(names,scores);
	}
      else if(user_input == "FindScore")
	{
	  std::string name = "";
	  std::cout << "Please enter a name to look for \n";
	  if(std::cin >> name)
	    {
	      find_score_by_name(names,scores,name);
	    }
	  else
	    {
	      std::cout << "invalid input";
	    }
	}
      else if(user_input == "Print")
	{
	  std::cout << "Print \n";
	  print_name_scores(names,scores);
	}
      else if(user_input == "FindAllScores")
	{
	  int score = 0;
	  std::cout << "Please enter a score to look for \n";
	  if(std::cin >> score)
	    {
	      find_all_scores(names,scores,score);
	    }
	  else
	    {
	      std::cout << "invalid input";
	    }
	}
      else if(user_input == "Help")
	{
	  display_commands();
	}
      else if(user_input == "Quit")
	{
	  std::cout << "Bye" << std::endl;
	  return 0;
	}
      else
	{
	  std::cout << "Input not recognized" << std::endl;
	}
    }
}

