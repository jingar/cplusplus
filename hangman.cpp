#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

const int number_of_words = 235882;
const std::string dictionary = "words.txt";
class Word_container
{
public:
  std::string word;
  std::vector<bool> found;
  std::vector<char> wrong_guess;
  unsigned int matched;
  unsigned int lives = 9;
  Word_container(std::string s)
    :word(s),matched(0)
  {
    found.resize(s.size(),false);
  };
  bool already_found(char c);
  void match(char c);
  void print_found_letters();
  void print_wrong_guesses();
  bool is_dead();
};

bool Word_container::already_found(char c)
{
  for(unsigned int i = 0; i < found.size(); ++i)
    {
      if(found[i] == true && word[i] == c)
	{
	  return true;
	}
    }
  for(unsigned int i = 0; i < wrong_guess.size(); ++i)
    {
      if(wrong_guess[i] == c)
	{
	  return true;
	}
    }
  
  return false;
}
void Word_container::match(char c)
{
  bool matched_once = false;
  for(unsigned int i = 0; i < word.size();++i)
    {
      if(word[i] == c)
	{
	  found[i] = true;
	  ++matched;
	  matched_once = true;
	}
    }
  if(!matched_once)
    {
      --lives;
      wrong_guess.push_back(c);
    }
}


void Word_container::print_found_letters()
{
  for(unsigned int i = 0; i < found.size();++i)
    {
      if(found[i] == true)
	{
	  std::cout << word[i];
	}
      else
	{
	  std::cout << " _ ";
	}
    }
  std::cout << "\n";
}


void Word_container::print_wrong_guesses()
{
  std::cout << "wrongly guessed letter(s): ";
  for(unsigned int i = 0; i < wrong_guess.size();++i)
    {
      std::cout << wrong_guess[i];
    }
  std::cout << "\nnumber of of lives left " << lives << "\n";
}

std::string find_random_word()
{
  std::ifstream word_file(dictionary);
  std::string current_word;
  int counter = 0;
  srand( time(0) );
  int random_number = rand()%number_of_words;
  
  if(!word_file.is_open())
    {
      std::cerr << "Couldn't open the file words.txt \n";
    }

  while(word_file >> current_word)
    {
      if(random_number == counter)
	{
	  break;
	}
      ++counter;
    }
  return current_word;
}

bool Word_container::is_dead()
{
  if(0>=lives)
    {
      return true;
    }
  return false;
}


void print_hangman(Word_container w)
{
  int stage = w.wrong_guess.size();
  
  switch(stage)
    {

    case 1: std::cout << "\|\n"
		      << "\|\n"      
		      << "\|\n"
		      << "\|\n"      
		      << "\|\n"      
		      << "\|\n"      
		      << "\|\n"     
		      << "\|\n"
		      << "-----------------\n";
	break;

    case 2: std::cout << "\|---------------\n"
		      << "\|\n"      
		      << "\|\n"
		      << "\|\n"      
		      << "\|\n"      
		      << "\|\n"      
		      << "\|\n"     
		      << "\|\n"
		      << "---------------- \n";
      break;
    case 3: std::cout << "\|---------------\n"
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|\n"      
		      << "\|\n"      
		      << "\|\n"     
		      << "\|\n"
		      << "-----------------\n";
      break;
    case 4: std::cout << "\|---------------\n"
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|             0\n"      
		      << "\|\n"      
		      << "\|\n"     
		      << "\|\n"
		      << "-----------------\n";
      break;
    case 5: std::cout << "\|---------------\n"
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|             0\n"      
		      << "\|             \|\n"      
		      << "\|             \|\n"
		      << "\|\n"
		      << "-----------------\n";
      break;
    case 6: std::cout << "\|---------------\n"
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|             0\n"      
		      << "\|            \\\|\n"      
		      << "\|             \|\n"
		      << "\|\n"
		      << "-----------------\n";
      break;
    case 7: std::cout << "\|---------------\n"
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|             0\n"      
		      << "\|            \\\|/\n"      
		      << "\|             \|\n"
		      << "\|\n"
		      << "-----------------\n";
      break;
    case 8: std::cout << "\|---------------\n"
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|             0\n"      
		      << "\|            \\\|/\n"      
		      << "\|             \|\n"
		      << "\|            /\n"
		      << "\|\n"
		      << "-----------------\n";
      break;
    case 9: std::cout << "\|---------------\n"
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|             \|\n"      
		      << "\|             0\n"      
		      << "\|            \\\|/\n"      
		      << "\|             \|\n"
		      << "\|            /\ \\\n"
		      << "\|\n"
		      << "-----------------\n";
      break;
    }
}

int main()
{
  Word_container w(find_random_word());

  std::cout << "This is a game called hangman.\n" 
	    << "To play guess the word i am thinking of by guessing one letter at a time but be careful you only have 9 lives.\n"
	    << "If you run out lives you lose the game and a man dies....you have been warned!\n\n";
  
  char in_letter;
  
  while(w.word.size() != w.matched && !w.is_dead())
    {
      std::cout << "Your guess: ";
      std::cin >> in_letter;
      if(w.already_found(in_letter))
	{
	  std::cout << "You already guessed that letter" << "\n";
	  continue;
	}
      w.match(in_letter);
      w.print_found_letters();
      w.print_wrong_guesses();
      print_hangman(w);
      std::cout << "\n";
      std::cout << "\n";
    }

  if(w.is_dead())
    {
      std::cout << "YOU LOOOOSEE, YOU KILLED HANGMAN .... \n";
      std::cout << "The word was " << w.word << ", how could you not get that?\n";
    }
  else
    {
      std::cout << "you win!! \n";      
    }
}
