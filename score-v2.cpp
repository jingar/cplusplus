#include <iostream>
#include <string>
#include <vector>
#include <limits>

class Name_value
{
public:
  std::string name;
  int score;
  Name_value(std::string in_name,int in_score);
};

Name_value::Name_value(std::string in_name, int in_score)
  :name(in_name), score(in_score)
{
}


bool name_unique(const std::vector<Name_value>& name_scores, std::string name)
{
  for(unsigned int i = 0; i < name_scores.size(); ++i)
    {
      if(name_scores[i].name == name)
	{
	  std::cout << "Not unique name: " << name << " \n";
	  return false;
	}
    }
  return true;
}

void print_name_scores(const std::vector<Name_value>& name_score)
{
  for(unsigned int i = 0; i < name_score.size();++i)
    {
      std::cout << name_score[i].name << ": " << name_score[i].score << "\n";
    }
}


void find_score_by_name(const std::vector<Name_value>& name_score, std::string name)
{
  for(unsigned int i = 0; i < name_score.size();++i)
    {
      if(name_score[i].name == name)
	{
	  std::cout << name << " has the score " << name_score[i].score << std::endl;
	  return;
	}
    }
  std::cout << name << " not found " << std::endl;
  
}

void insert_name_scores(std::vector<Name_value>& name_score)
{
  std::string name = "";
  int score = 0;
  std::cout << "Please enter a name followed by space and then the person's score" << std::endl;
  while(std::cin >> name >> score && name != "Nomore")
    {
      if(name_unique(name_score,name))
	{
	    Name_value n(name,score);
	    name_score.push_back(n);
	}
    }
  
  std::cout << name  << " testing name " << name << "\n";
  if(!std::cin.good())
    {
      std::cout << "Failed close to name: " << name << "\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void find_all_scores(const std::vector<Name_value>& name_score,int score)
{
  bool found = false;
  for(unsigned int i = 0; i <name_score.size();i++)
    {
      if(name_score[i].score == score)
	{
	  std::cout << name_score[i].name << "\n";
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
	    << "FindAllScores - Find all names associated with a score \n"
	    << "Print - Print all names and scores \n"
	    << "Help - Display all commands \n"
	    << "Quit - Quit the program" << std::endl;
}
int main()
{
  std::vector<Name_value> name_score;
  std::string user_input = "";
  display_commands();
  while(std::cin >> user_input)
    {
      std::cout << user_input << " loop"  << std::endl;
      if(user_input == "Insert")
	{
	  std::cout << user_input << " insert " << std::endl;
	  insert_name_scores(name_score);
	}
      else if(user_input == "FindScore")
	{
	  std::string name = "";
	  std::cout << "Please enter a name to look for \n";
	  if(std::cin >> name)
	    {
	      find_score_by_name(name_score,name);
	    }
	  else
	    {
	      std::cout << "invalid input";
	    }
	}
      else if(user_input == "FindAllScores")
	{
	  int score = 0;
	  std::cout << "Please enter a score to look for \n";
	  if(std::cin >> score)
	    {
	      find_all_scores(name_score,score);
	    }
	  else
	    {
	      std::cout << "invalid input";
	    }
	}
      else if(user_input == "Print")
	{
	  print_name_scores(name_score);
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
	  std::cout << user_input << " not recognized " << std::endl;
	}
    }
  std::cout << user_input << std::endl;
  print_name_scores(name_score);

  return 0;
}
