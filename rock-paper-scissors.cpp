#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

const int ROCK = 0;
const int PAPER = 1;
const int SCISSORS = 2;
int player_score = 0;
int computer_score = 0;
std::string choices(int c)
{
  switch(c)
  {
 case 0:
    return "Rock";
    break;
 case 1:
   return "Paper";
    break;
 case 2:
   return "Scissors";
   break;
  default:
    return "Error";
    break;
  }
}
void resolver(int computer, int user)
{
  std::cout << "Computer chooses " << choices(computer) << std::endl;
  int value = (3 + computer - user) % 3;
  switch(value)
    {
    case 0:
      std::cout << "Its a tie \n" << std::endl;
      break;
    case 1:
      std::cout << choices(computer) << " beats " << choices(user) << "\n";
      std::cout << "The computer wins" << std::endl;
      break;
    case 2:
      std::cout <<  choices(user) << " beats " << choices(computer) << "\n";
      std::cout << "You win" << std::endl;
      break;
    }
}


int main()
{
  std::string user_choice = "";
  int computer_choice = 0;
  srand((unsigned)time(0)); 
  std::cout << "Hello, this is a Rock,Paper,Siccors game\n";
  std::cout << "What is your choice" << std::endl;
  computer_choice = rand() % 3;
  if(std::cin >> user_choice)
    {
      if(user_choice == "Rock")
	{
	  resolver(computer_choice,ROCK);
	}
      else if(user_choice == "Paper")
	{
	  resolver(computer_choice,PAPER);
	}
	else if(user_choice == "Scissors")
	  {
	    resolver(computer_choice,SCISSORS);
	  }
	else 
	  {
	    std::cout << "I dont understand the word " << user_choice << std::endl;
	    return -1;
	  }
    }

  return 0;
}
